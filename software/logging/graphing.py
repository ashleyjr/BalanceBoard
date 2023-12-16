import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import argparse
import multiprocessing
import threading
import sys
import serial
import time

MPU_SAMPLE_PERIOD_S = 5e-3
MPU_FS_SEL = 500
MPU_AFS_SEL = 2
MPU_FS_SEL_DIV = (2 ** 16) / (2*MPU_FS_SEL)
MPU_AFS_SEL_DIV = (2 ** 16) / (2*MPU_AFS_SEL)
MOTOR_DRV = 100

class Analysis:

    def __init__(self, filename):

        self.last = 0
        self.laps = 0

        self.log = ""

    def read(self, filename):
        # Read in logfile
        f = open(filename,"r+")
        self.logfile= f.read()
        f.close()

    def proc(self):
        # Get the data
        self.__procLog(self.logfile)

    def log(self):

        with serial.Serial('/dev/ttyUSB0', 115200, timeout=0.1) as ser:
            ser.flush()
            ser.flushInput()
            ser.flushOutput()
            ser.reset_input_buffer()

            while True:
                if ser.inWaiting() > 0:
                    print('a')
                    self.log += ser.read(ser.inWaiting()).decode("utf-8")
                    ser.write("a".encode("utf-8"))
                time.sleep(0.1)

    def __procLog(self, log):
        self.__time = []
        self.__accel_x = []
        self.__accel_y = []
        self.__accel_z = []
        self.__gyro_x = []
        self.__gyro_y = []
        self.__gyro_z = []
        self.__motor = []
        lines = log.split("\n")[1:-1]
        for line in lines:
            self.__time.append(self.__procLineTime(line))
            self.__accel_x.append(self.__procLineAccelX(line))
            self.__accel_y.append(self.__procLineAccelY(line))
            self.__accel_z.append(self.__procLineAccelZ(line))
            self.__gyro_x.append(self.__procLineGyroX(line))
            self.__gyro_y.append(self.__procLineGyroY(line))
            self.__gyro_z.append(self.__procLineGyroZ(line))
            self.__motor.append(self.__procLineMotor(line))

    def __procLineTime(self, line):
        s = line.split(",")[0]
        i = int(s, 16)
        if(self.last > i):
            self.laps += 1
        self.last = i
        return ((self.laps * (2 ** 16)) + i) *  MPU_SAMPLE_PERIOD_S

    def __procLineAccelX(self, line):
        return self.__procTwosComp(line.split(",")[1]) / MPU_AFS_SEL_DIV

    def __procLineAccelY(self, line):
        return self.__procTwosComp(line.split(",")[2]) / MPU_AFS_SEL_DIV

    def __procLineAccelZ(self, line):
        return self.__procTwosComp(line.split(",")[3]) / MPU_AFS_SEL_DIV

    def __procLineGyroX(self, line):
        return self.__procTwosComp(line.split(",")[4]) / MPU_FS_SEL_DIV

    def __procLineGyroY(self, line):
        return self.__procTwosComp(line.split(",")[5]) / MPU_FS_SEL_DIV

    def __procLineGyroZ(self, line):
        return self.__procTwosComp(line.split(",")[6]) / MPU_FS_SEL_DIV

    def __procLineMotor(self, line):
        return self.__procTwosComp(line.split(",")[7])

    def __procTwosComp(self, s):
        i = int(s, 16)
        if(i & 0x8000):
            i = (~i + 1)
            i &= 0xFFFF
            i = -i
        return i

    def getTime(self):
        return self.__time

    def getAccelX(self):
        return self.__accel_x

    def getAccelY(self):
        return self.__accel_y

    def getAccelZ(self):
        return self.__accel_z

    def plotAll(self):
        fig, ax = plt.subplots(3,1)
        ax[0].plot(self.__time, self.__accel_x, label="x")
        ax[0].plot(self.__time, self.__accel_y, label="y")
        ax[0].plot(self.__time, self.__accel_z, label="z")
        ax[1].plot(self.__time, self.__gyro_x, label="x")
        ax[1].plot(self.__time, self.__gyro_y, label="y")
        ax[1].plot(self.__time, self.__gyro_z, label="z")
        ax[2].plot(self.__time, self.__motor, label="Motor")
        for i in range(3):
            ax[i].grid(True, which='major')
            ax[i].grid(True, which='minor')
            ax[i].legend()
            ax[i].legend(loc='center left', bbox_to_anchor=(1, 0.5))
        ax[1].set_label("Time(s)")
        ax[0].set_ylabel("Accel (g)")
        ax[1].set_ylabel("Gyro (º/s)")
        ax[2].set_ylabel("Motor Drive (+/-%)")
        ax[0].set_ylim([-MPU_AFS_SEL,MPU_AFS_SEL])
        ax[1].set_ylim([-MPU_FS_SEL,MPU_FS_SEL])
        ax[2].set_ylim([-MOTOR_DRV, MOTOR_DRV])
        plt.savefig("graph.png", dpi=200)


def log(arg, filename):
    t = threading.currentThread()
    with serial.Serial('/dev/ttyUSB0', 115200, timeout=0.1) as ser:
        ser.flush()
        ser.flushInput()
        ser.flushOutput()
        ser.reset_input_buffer()

        f = open(filename, "w+")

        while getattr(t, "do_run", True):
            if ser.inWaiting() > 0:
                f.write(ser.read(ser.inWaiting()).decode("utf-8"))
                ser.write("a".encode("utf-8"))
            time.sleep(0.1)

        f.close()

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--filename", type=str, required=True)
    args = parser.parse_args()

    print("Capturing...")
    t = threading.Thread(target=log, args=("task",args.filename,))
    t.start()
    sys.stdin.read(1)
    t.do_run = False
    t.join()

    print("Plotting...")
    u = Analysis(args.filename)
    u.read(args.filename)
    u.proc()
    u.plotAll()

if "__main__" == __name__:
    main()
