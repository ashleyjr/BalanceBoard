from pid import Pid
from plants import FirstOrder
import matplotlib.pyplot as plt
import numpy as np

start_s = -0.1
stop_s  = 2
step_s  = 1e-3
samples = np.arange(start=start_s, stop=stop_s, step=step_s)

u = Pid()
m = FirstOrder(Ts=step_s)

p = []
i = []

err = []
target = []
drive = []
measure = []

u.SetP(100)
u.SetI(1)


for i in samples:
    if (0 < i) and (i < 1):
        u.SetSet(1)
        target.append(1)
    else:
        u.SetSet(0)
        target.append(0)

    d = u.Process(m.getOut())

    err.append(abs(u.GetErr()))
    drive.append(d)
    measure.append(m.getOut())

    m.update(d)

plt.subplot(3,1,1)
plt.plot(samples,drive)


plt.subplot(3,1,2)
plt.plot(samples,measure)
plt.plot(samples,target)

plt.subplot(3,1,3)
plt.plot(samples,err)
plt.yscale('log')


plt.show()
