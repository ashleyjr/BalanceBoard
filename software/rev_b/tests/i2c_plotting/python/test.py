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

ax = []
ay = []
az = []

gx = []
gy = []
gz = []

def get_data():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        while(True):
            s.sendall(bytes(f"1", encoding="ascii"))
            data = s.recv(1024)
            data_str = data.decode("utf-8")
            datas = data_str.split(',')

            ax.append(int(datas[0]))
            ay.append(int(datas[1]))
            az.append(int(datas[2]))

            gx.append(int(datas[4]))
            gy.append(int(datas[5]))
            gz.append(int(datas[6]))

def animate(time):
    ax1.clear()
    ax1.plot(range(len(ax)), ax)
    ax1.plot(range(len(ay)), ay)
    ax1.plot(range(len(az)), az)
    ax2.clear()
    ax2.plot(range(len(gx)), gx)
    ax2.plot(range(len(gy)), gy)
    ax2.plot(range(len(gz)), gz)

if __name__ =="__main__":
    t = threading.Thread(target=get_data)
    t.start()
    ani = animation.FuncAnimation(fig, animate, interval=100)
    plt.show()
    t.join()

