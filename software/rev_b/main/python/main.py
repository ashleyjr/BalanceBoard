import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style
import time
import threading
from BalanceBoard import BalanceBoard

style.use('fivethirtyeight')
fig = plt.figure()
ax1 = fig.add_subplot(3,1,1)
ax2 = fig.add_subplot(3,1,2)
ax3 = fig.add_subplot(3,1,3)


sample_time = []
gyro_y = []
p_drive = []
i_drive = []
d_drive = []
error = []

b = BalanceBoard("192.168.1.184", 3333, "../common/balance_board.h")

def animate(time):
    # Sample and pack data
    b.sampleLoopData(True)
    sample_time.append(b.getTimeM())
    gyro_y.append(b.getGyroY())
    p_drive.append(b.getPdrive())
    i_drive.append(b.getIdrive())
    d_drive.append(b.getDdrive())
    error.append(b.getError())
    # Draw graph
    ax1.clear()
    ax1.plot(sample_time, gyro_y)
    ax2.clear()
    ax2.plot(sample_time, p_drive)
    ax2.plot(sample_time, i_drive)
    ax2.plot(sample_time, d_drive)
    ax3.clear()
    ax3.plot(sample_time, error)



if __name__ =="__main__":

    #b.activateMotor()
    #for i in range(10):
    #    b.setMotorA(0, 100)
    #    time.sleep(1)
    #    b.setMotorA(1, 100)
    #b.deactivateMotor()


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

    b.setPID(0.03,0.01,0)
    b.activatePID()
    ani = animation.FuncAnimation(fig, animate, interval=100)
    plt.show()



