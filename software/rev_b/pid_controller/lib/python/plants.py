import math
import scipy.signal as sig

class FirstOrder:
    def __init__(self, K=1, T=1, Ts=0.01):
        self.v_o = 0
        self.a = (-1/T)
        self.b = (K/T)
        self.Ts = Ts

    def update(self, v_i):
        self.v_o = (1 + (self.Ts * self.a)) * self.v_o
        self.v_o += self.Ts * self.b * v_i

    def getOut(self):
        return self.v_o
