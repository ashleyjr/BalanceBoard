import socket
import time
from tools.hdr2const import hdr2Const

class BalanceBoard:

    def __init__(self, ip, port):
        self.port = port
        self.ip = ip
        self.time = -1

    def sendFrame(self, b):
        assert(len(b) == 9)
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect((self.ip, self.port))
            s.sendall(bytes(chr(b[0])+chr(b[1])+chr(b[2])+chr(b[3])+chr(b[4])+chr(b[5])+chr(b[6])+chr(b[8])+chr(b[8]), encoding='utf-8'))
            data = s.recv(1024)
        data_str = data.decode("utf-8")
        datas = data_str.split(',')
        return datas

    def setMotor(self, stby, a_dir, a_pwm, b_dir, b_pwm, led=True):
        b = []
        b.append(0)
        b.append(int(led == True))
        b.append(int(stby  == True))
        b.append(int(a_dir == True))
        b.append(int(a_pwm))
        b.append(int(b_dir == True))
        b.append(int(b_pwm))
        d = self.sendFrame(b)
        print(d)

    def sampleImu(self):
        b = [0] * 9
        b[0] = 0x80
        b[8] = 1
        d = self.sendFrame(b)
        print(d)
        self.time = int(d[0])
        self.accel_x = int(d[1])
        self.accel_y = int(d[2])
        self.accel_z = int(d[3])
        self.gyro_x = int(d[4])
        self.gyro_y = int(d[5])
        self.gyro_z = int(d[6])

    def setPid(self, p_mul, p_div):
        b = [0] * 9
        b[0] = 2
        b[7] = p_mul
        b[8] = p_div
        d = self.sendFrame(b)

    def ledOn(self):
        b = [0] * 7
        b[1] = 1
        d = self.sendFrame(b)

    def ledOff(self):
        b = [0] * 7
        b[1] = 0
        d = self.sendFrame(b)

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



