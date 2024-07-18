import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style
import threading
import time
from BalanceBoard import BalanceBoard

style.use('fivethirtyeight')
fig = plt.figure()
ax1 = fig.add_subplot(2,1,1)
ax2 = fig.add_subplot(2,1,2)

time = []
accel_x = []
accel_y = []
accel_z = []
gyro_x = []
gyro_y = []
gyro_z = []

def get_data(b):
    while(True):
        b.sampleImu()
        time.append(b.getTime())
        accel_x.append(b.getAccelX())
        accel_y.append(b.getAccelY())
        accel_z.append(b.getAccelZ())
        gyro_x.append(b.getGyroX())
        gyro_y.append(b.getGyroY())
        gyro_z.append(b.getGyroZ())

def animate(time):
    ax1.clear()
    ax1.plot(time, accel_x)
    ax1.plot(time, accel_y)
    ax1.plot(time, accel_z)
    ax2.clear()
    ax2.plot(time, gyro_x)
    ax2.plot(time, gyro_y)
    ax2.plot(time, gyro_z)

if __name__ =="__main__":
    b = BalanceBoard("192.168.1.184", 3333)
    t = threading.Thread(target=get_data, args=(b,))
    t.start()
    ani = animation.FuncAnimation(fig, animate, interval=100)
    plt.show()
    time.sleep(1)
    t.join()



