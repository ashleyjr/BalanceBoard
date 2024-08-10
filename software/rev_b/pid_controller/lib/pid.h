#ifndef PID_H
#define PID_H

class Pid{
   public:
      Pid(void);
      void Reset(void);
      void SetSet(float v);
      void SetP(float v);
      void SetI(float v);
      void SetD(float v);
      float Process(float v);
      void GetPout(float *v);
      void GetIout(float *v);
      void GetDout(float *v);
      void GetErr(float *v);
      void GetOut(float *v);
   private:
      float set;
      float act;
      float p;
      float i;
      float d;
      float err_n0;
      float area;
      float p_out;
      float i_out;
      float d_out;
      float out;
};

extern "C" {
   Pid* Pid_new(){ return new Pid(); }
   void Pid_SetSet(Pid* pid, float v){ pid->SetSet(v); }
   void Pid_SetP(Pid* pid, float v){ pid->SetP(v); }
   void Pid_SetI(Pid* pid, float v){ pid->SetI(v); }
   void Pid_SetD(Pid* pid, float v){ pid->SetD(v); }
   float Pid_Process(Pid* pid, float v){ return pid->Process(v); }
   void Pid_GetPout(Pid* pid, float *v) { return pid->GetPout(v); }
   void Pid_GetIout(Pid* pid, float *v) { return pid->GetIout(v); }
   void Pid_GetDout(Pid* pid, float *v) { return pid->GetDout(v); } 
   void Pid_GetErr(Pid* pid, float *v) { return pid->GetErr(v); } 
   void Pid_GetOut(Pid* pid, float *v) { return pid->GetOut(v); } 
}


#endif
