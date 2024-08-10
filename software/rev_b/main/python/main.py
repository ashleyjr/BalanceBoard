import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style
import time
import threading
from BalanceBoard import BalanceBoard

style.use('fivethirtyeight')
fig = plt.figure()
ax1 = fig.add_subplot(2,1,1)
#ax2 = fig.add_subplot(2,1,2)

sample_time = []
accel_x = []
accel_y = []
accel_z = []
gyro_x = []
gyro_y = []
gyro_z = []


b = BalanceBoard("192.168.1.184", 3333, "../common/balance_board.h")

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
    #ax1.plot(sample_time, accel_x)
    #ax1.plot(sample_time, accel_y)
    #ax1.plot(sample_time, accel_z)
    #ax2.clear()
    #ax1.plot(sample_time, gyro_x)
    ax1.plot(sample_time, gyro_y)
    #ax1.plot(sample_time, gyro_z)

if __name__ =="__main__":

    b.activateMotor()
    for i in range(10):
        b.setMotorA(0, 100)
        time.sleep(1)
        b.setMotorA(1, 100)
    b.deactivateMotor()


    #b = BalanceBoard("192.168.1.184", 3333, "../common/balance_board.h")

    #for i in range(10):
    #    b.sampleImu()

    #b.onLED()
    #time.sleep(1)
    #b.offLED()

    #b.setPID(1,30,3)

    #b.setPid(0,256)
    #b.sampleImu()
    #b.ledOn()

    #for i in range(0,30):
    #    print(i)


    #b.setMotor(True,False,200,True,255)
    #time.sleep(0.5)
    #b.setMotor(False,False,0,True,255)
    #time.sleep(0.5)

    #b.ledOff()
    #b.setMotor(False,False,10,True,255)

    #ani = animation.FuncAnimation(fig, animate, interval=100)
    #plt.show()



