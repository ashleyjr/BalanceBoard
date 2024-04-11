import socket
import time
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style
import numpy as np
import threading

HOST = "192.168.1.153"
PORT = 3333

style.use('fivethirtyeight')
fig = plt.figure()
ax1 = fig.add_subplot(2,1,1)
ax2 = fig.add_subplot(2,1,2)

accel = []
duty = []

def get_data():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        while(True):
            s.sendall(bytes(f"1", encoding="ascii"))
            data = s.recv(1024)
            data_str = data.decode("utf-8")
            datas = data_str.split(',')

            accel.append(int(datas[0]))
            duty.append(int(datas[1]))

def animate(time):
    ax1.clear()
    ax1.plot(range(len(accel)), accel)
    ax2.clear()
    ax2.plot(range(len(duty)), duty)

if __name__ =="__main__":
    t = threading.Thread(target=get_data)
    t.start()
    ani = animation.FuncAnimation(fig, animate, interval=100)
    plt.show()
    t.join()

