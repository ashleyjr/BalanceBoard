import socket
import time
from tools.hdr2const import hdr2Const

class BalanceBoard:

    def __init__(self, ip, port):
        self.port = port
        self.ip = ip
        self.time = -1

    def sendFrame(self, b):
        assert(len(b) == 7)
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect((self.ip, self.port))
            s.sendall(bytes(chr(b[0])+chr(b[1])+chr(b[2])+chr(b[3])+chr(b[4])+chr(b[5])+chr(b[6]), encoding='utf-8'))
            data = s.recv(1024)
        data_str = data.decode("utf-8")
        datas = data_str.split(',')
        return datas

    def setMotor(stby, a_dir, a_pwm, b_dir, b_pwm, led=True):
        b = []
        b.append(2)
        b.append(int(led == True))
        b.append(int(stby  == True))
        b.append(int(a_dir == True))
        b.append(int(a_pwm % 256))
        b.append(int(b_dir == True))
        b.append(int(b_pwm % 256))
        self.sendFrame(b)


    def sampleImu(self):
        b = [0] * 7
        b[0] = 0x7E
        d = self.sendFrame(b)
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



