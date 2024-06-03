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

def setMotor(stby, a_dir, a_pwm, b_dir, b_pwm, led=True):
    b = []
    b.append(2)
    b.append(int(led == True))
    b.append(int(stby  == True))
    b.append(int(a_dir == True))
    b.append(int(a_pwm % 256))
    b.append(int(b_dir == True))
    b.append(int(b_pwm % 256))
    sendFrame(b)

if __name__ =="__main__":

    setMotor(True, True, 50, True, 50)
    time.sleep(0.5)
    setMotor(False, True, 255, True, 255)


    #setMotor(True, True, 255, True, 0)
    #time.sleep(0.1)
    #setMotor(True, False, 0, False, 255)
    #time.sleep(0.5)
    #setMotor(False, True, 0, True, 0)

