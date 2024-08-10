import ctypes as c
lib = c.cdll.LoadLibrary('./libpid.so')

class Pid(object):
    def __init__(self):
        self.obj = lib.Pid_new()
    def SetSet(self, s):
        v = c.c_float()
        v.value = s
        lib.Pid_SetSet(self.obj, v)
    def SetP(self, p):
        v = c.c_float()
        v.value = p
        lib.Pid_SetP(self.obj, v)
    def SetI(self, i):
        v = c.c_float()
        v.value = i
        lib.Pid_SetI(self.obj, v)
    def SetD(self, d):
        lib.Pid_SetD(self.obj, d)
    def Process(self, a):
        v = c.c_float()
        v.value = a
        lib.Pid_Process(self.obj, v)
        lib.Pid_GetOut(self.obj, c.byref(v))
        return v.value
    def GetPout(self, p):
        return lib.Pid_GetPout(self.obj, p)
    def GetIout(self):
        v = c.c_float()
        lib.Pid_GetIout(self.obj, c.byref(v))
        return v.value
    def GetDout(self, d):
        return lib.Pid_GetDout(self.obj, d)
    def GetErr(self):
        v = c.c_float()
        lib.Pid_GetErr(self.obj, c.byref(v))
        return v.value
    def GetOut(self):
        v = c.c_float()
        lib.Pid_GetOut(self.obj, c.byref(v))
        return v.value




##v = c.c_float()
#v.value = 2
#pid = Pid()
#pid.SetP(v)
#pid.SetI(v)
#pid.SetD(v)
#pid.SetSet(v)
#v.value = 0
#pid.Process(v)
#pid.GetPout(c.byref(v))
#pid.GetIout(c.byref(v))
#pid.GetDout(c.byref(v))
#print(v.value)
