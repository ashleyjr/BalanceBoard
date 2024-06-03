import socket
import time
from tools.hdr2const import hdr2Const

HOST = "192.168.1.153"
PORT = 3333
c = hdr2Const("../common/balance_board.h")


def sendFrame(b):
    assert(len(b) == 7)
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        s.sendall(bytes(chr(b[0])+chr(b[1])+chr(b[2])+chr(b[3])+chr(b[4])+chr(b[5])+chr(b[6]), encoding='utf-8'))
        data = s.recv(1024)
    data_str = data.decode("utf-8")
    datas = data_str.split(',')
    print(f"{datas}")

def setMotor(stby, a_dir, a_pwm, b_dir, b_pwm):
    b = []
    b.append(2)
    b.append(1)
    b.append(int(stby  == True))
    b.append(int(a_dir == True))
    b.append(int(a_pwm % 256))
    b.append(int(b_dir == True))
    b.append(int(b_pwm % 256))
    sendFrame(b)

if __name__ =="__main__":


    setMotor(True, True, 128, True, 0)
    time.sleep(0.5)
    setMotor(False, False, 0, True, 0)
    time.sleep(0.1)
    setMotor(True, False, 128, True, 0)
    time.sleep(0.5)
    setMotor(False, True, 0, True, 0)

