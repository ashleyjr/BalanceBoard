import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style
import time
import threading
from BalanceBoard import BalanceBoard

style.use('fivethirtyeight')
fig = plt.figure()
ax1 = fig.add_subplot(2,1,1)
ax2 = fig.add_subplot(2,1,2)

sample_time = []
accel_x = []
accel_y = []
accel_z = []
gyro_x = []
gyro_y = []
gyro_z = []

def animate(time):
    # Sample and pack data
    b.sampleImu()
    sample_time.append(b.getTimeM())
    accel_x.append(b.getAccelX())
    accel_y.append(b.getAccelY())
    accel_z.append(b.getAccelZ())
    gyro_x.append(b.getGyroX())
    gyro_y.append(b.getGyroY())
    gyro_z.append(b.getGyroZ())
    # Draw graph
    ax1.clear()
    ax1.plot(sample_time, accel_x)
    ax1.plot(sample_time, accel_y)
    ax1.plot(sample_time, accel_z)
    ax2.clear()
    ax2.plot(sample_time, gyro_x)
    ax2.plot(sample_time, gyro_y)
    ax2.plot(sample_time, gyro_z)

if __name__ =="__main__":
    b = BalanceBoard("192.168.1.184", 3333)
    b.setMotor(False,False,200,True,255)
    time.sleep(1)
    b.setMotor(True,False,200,True,255)

    #ani = animation.FuncAnimation(fig, animate, interval=100)
    #plt.show()



