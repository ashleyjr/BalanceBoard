import socket
import time

HOST = "192.168.1.153"
PORT = 3333

if __name__ =="__main__":
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        for i in range(6):
            for j in range(255):
                s.sendall(bytes(str(i)+chr(j), encoding='utf-8'))
                data = s.recv(1024)
                data_str = data.decode("utf-8")
                datas = data_str.split(',')
                print(f"{i}:{datas}")



