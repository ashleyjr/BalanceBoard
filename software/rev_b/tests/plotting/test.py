import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style
import numpy as np

style.use('fivethirtyeight')

fig = plt.figure()
ax1 = fig.add_subplot(2,1,1)
ax2 = fig.add_subplot(2,1,2)


def animate(time):
    xs = []
    yxs = []
    yys = []
    yzs = []
    for t in range(time):
        xs.append(t)
        yxs.append(np.sin(((np.pi/10)*t) + np.pi))
        yys.append(np.sin(((np.pi/10)*t) + (np.pi/2)))
        yzs.append(np.sin(((np.pi/10)*t)))
    ax1.clear()
    ax1.plot(xs, yxs)
    ax1.plot(xs, yys)
    ax1.plot(xs, yzs)
    ax2.clear()
    ax2.plot(xs, yxs)
    ax2.plot(xs, yys)
    ax2.plot(xs, yzs)
ani = animation.FuncAnimation(fig, animate, interval=100)
plt.show()
