import matplotlib.pyplot as plt
import numpy as np
import argparse


MPU_SAMPLE_PERIOD_S = 5e-3

class Analysis:

    def __init__(self, filename):

        self.last = 0
        self.laps = 0

        # Read in logfile
        f = open(filename,"r+")
        logfile= f.read()
        f.close()

        # Get the data
        self.__procLog(logfile)

    def __procLog(self, log):
        self.__time = []
        self.__accel_x = []
        self.__accel_y = []
        self.__accel_z = []
        self.__gyro_x = []
        self.__gyro_y = []
        self.__gyro_z = []
        lines = log.split("\n")[:-1]
        for line in lines:
            self.__time.append(self.__procLineTime(line))
            self.__accel_x.append(self.__procLineAccelX(line))
            self.__accel_y.append(self.__procLineAccelY(line))
            self.__accel_z.append(self.__procLineAccelZ(line))
            self.__gyro_x.append(self.__procLineGyroX(line))
            self.__gyro_y.append(self.__procLineGyroY(line))
            self.__gyro_z.append(self.__procLineGyroZ(line))

    def __procLineTime(self, line):
        s = line.split(",")[0]
        i = int(s, 16)
        if(self.last > i):
            self.laps += 1
        self.last = i
        return ((self.laps * (2 ** 16)) + i) *  MPU_SAMPLE_PERIOD_S

    def __procLineAccelX(self, line):
        return self.__procTwosComp(line.split(",")[1])

    def __procLineAccelY(self, line):
        return self.__procTwosComp(line.split(",")[2])

    def __procLineAccelZ(self, line):
        return self.__procTwosComp(line.split(",")[3])

    def __procLineGyroX(self, line):
        return self.__procTwosComp(line.split(",")[4])

    def __procLineGyroY(self, line):
        return self.__procTwosComp(line.split(",")[5])

    def __procLineGyroZ(self, line):
        return self.__procTwosComp(line.split(",")[6])

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
        plt.plot(self.__time, self.__accel_x)
        plt.plot(self.__time, self.__accel_y)
        plt.plot(self.__time, self.__accel_z)
        plt.plot(self.__time, self.__gyro_x)
        plt.plot(self.__time, self.__gyro_y)
        plt.plot(self.__time, self.__gyro_z)
        plt.grid(True, which='major')
        plt.grid(True, which='minor')
        plt.legend()
        plt.xlabel("Position")
        plt.ylabel("Time (ns)")
        plt.savefig("graph.png", dpi=200)



#    def plotRef(self, x0, y0, x1, y1):
#        plt.plot([x0,x1],[y0,y1],linewidth=1)
#        if x0 == x1:
#            plt.ylim([y0,y1])
#        else:
#            plt.xlim([x0,x1])
#
#
#    def plotTrace(self, time, voltage, label=""):
#        assert self.trace == True
#        self.times.append(time)
#        self.traces.append(voltage)
#        self.labels.append(label)
#
#    def save(self):
#        #plt.subplots(len(self.traces),1)
#        plt.rcParams.update({'font.size': 4})
#        i = 1
#        for label,time,trace in zip(self.labels,self.times,self.traces):
#            plt.subplot(len(self.traces),1,i)
#            plt.plot(time,trace)
#            plt.gca().get_xaxis().set_visible(False)
#            plt.ylabel(f"{label} (V)")
#            i += 1
#        plt.gca().get_xaxis().set_visible(True)
#        plt.savefig(f"graph_{self.name}.png", dpi=200)

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--filename", type=str, required=True)
    args = parser.parse_args()

    u = Analysis(args.filename)
    u.plotAll()

    #def print_guide(name, l):
    #    print(f"{name}")
    #    s = ""
    #    for i in range(l):
    #        s = f"{str(hex(i % 16))[2]}{s}"
    #    print(s)

    #for test in [v]:
    #    print_guide("D", 70)
    #    samples = test.getSampleTaps()
    #    for s in samples:
    #        print(f"{s}:\t{samples[s]}")

    #print("Sampled Data:")
    #for test in [v]:
    #    print_guide("Q", 48)
    #    samples = test.getSamples()
    #    for s in samples:
    #        print(f"{s}:\t{samples[s]}")


    #p = Plotter("q_trace", trace=True)
    #taps = v.getTrace()
    #p.plotTrace(v.getTime(),v.getVdd(),"VDD")
    #p.plotTrace(v.getTime(),v.getClock(), "CLK")
    #for i in range(12,22):
    #    p.plotTrace(v.getTime(),v.getData()[f"{i}"],f"Q[{i}]")
    #p.save()

    #p = Plotter("d_trace", trace=True)
    #taps = v.getTrace()
    #p.plotTrace(v.getTime(),v.getVdd(),"VDD")
    #p.plotTrace(v.getTime(),v.getClock(), "CLK")
    #for i in range(25,35):
    #    p.plotTrace(v.getTime(),v.getTaps()[f"{i}"],f"Q[{i}]")
    #p.save()

    ## Plot the delays
    #p = Plotter("taps", taps=True)
    #p.plotTaps(v.getTapCrossings(), ["750mV","770mV","790mV","810mV","830mV", "850mV"])
    #p.plotRef(0,2e-8,50,2e-8)
    #p.plotRef(21,0,21,3e-8)
    #p.plotRef(38,0,38,3e-8)
    #p.plotRef(39,0,39,3e-8)
    #p.plotRef(40,0,40,3e-8)
    #p.save()

if "__main__" == __name__:
    main()
