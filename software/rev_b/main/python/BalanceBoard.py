import socket
import time
from tools.hdr2const import hdr2Const

class BalanceBoard:

    def __init__(self, ip, port, const_filepath):
        self.port = port
        self.ip = ip
        self.time = -1
        self.c = hdr2Const(const_filepath)

    def __sendFrame(self, data):
        assert(len(data) < self.c.MAX_SIZE)
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect((self.ip, self.port))
            s.sendall(str(data+'\0').encode())
            reply = s.recv(self.c.MAX_SIZE).decode("utf-8")
        # Check the replay
        if(reply[0:len(data)] != data):
            print("ERROR")
            print(f"Expected: {data}")
            print(f"Recieved: {bounce}")
        return reply[len(data):]

    def __sendCmdData(self, cmd, data):
        s = f"{cmd:0>8X}{data:0>8X}"
        return self.__sendFrame(s)

    def onLED(self):
        self.__sendCmdData(self.c.CMD_UPDATE_LED,1)

    def offLED(self):
        self.__sendCmdData(self.c.CMD_UPDATE_LED,0)

    def setPID(self, p, i, d):
        self.__sendCmdData(self.c.CMD_UPDATE_P_CTRL, int(p * float(self.c.FLOAT_SCALE)))
        self.__sendCmdData(self.c.CMD_UPDATE_I_CTRL, int(i * float(self.c.FLOAT_SCALE)))
        self.__sendCmdData(self.c.CMD_UPDATE_D_CTRL, int(d * float(self.c.FLOAT_SCALE)))

    def deactivateMotor(self):
        cmd = self.c.CMD_CTRL_MANUAL
        cmd |= self.c.CMD_UPDATE_MOTOR_STBY
        self.__sendCmdData(cmd,0)

    def activateMotor(self):
        cmd = self.c.CMD_CTRL_MANUAL
        cmd |= self.c.CMD_UPDATE_MOTOR_STBY
        self.__sendCmdData(cmd,1)

    def setMotorA(self, d, p):

        # TODO: Chaneg to make 0 around 2^31

        cmd = self.c.CMD_CTRL_MANUAL
        cmd |= self.c.CMD_UPDATE_MOTOR_A_DIR
        self.__sendCmdData(cmd,d)
        cmd = self.c.CMD_CTRL_MANUAL
        cmd |= self.c.CMD_UPDATE_MOTOR_A_PWM
        self.__sendCmdData(cmd,p)

    def sampleImu(self):
        cmd  = self.c.CMD_SAMPLE_ACCEL_X
        cmd |= self.c.CMD_SAMPLE_ACCEL_Y
        cmd |= self.c.CMD_SAMPLE_ACCEL_Z
        cmd |= self.c.CMD_SAMPLE_GYRO_X
        cmd |= self.c.CMD_SAMPLE_GYRO_Y
        cmd |= self.c.CMD_SAMPLE_GYRO_Z
        d = self.__sendCmdData(cmd,0)
        d = d.split(',')
        self.time = int(d[0])
        self.accel_x = int(d[1])
        self.accel_y = int(d[2])
        self.accel_z = int(d[3])
        self.gyro_x = int(d[4])
        self.gyro_y = int(d[5])
        self.gyro_z = int(d[6])

    def getTimeMs(self):
        return self.time

    def getTimeS(self):
        return self.getTimeMs() / 1000

    def getTimeM(self):
        return self.getTimeS() / 60

    def getAccelX(self):
        return self.accel_x

    def getAccelY(self):
        return self.accel_y

    def getAccelZ(self):
        return self.accel_z

    def getGyroX(self):
        return self.gyro_x

    def getGyroY(self):
        return self.gyro_y

    def getGyroZ(self):
        return self.gyro_z



