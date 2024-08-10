#include <iostream>
#include "pid.h"


Pid::Pid(void){
   Reset(); 
}

void Pid::Reset(void){
   set = 0;
   p = 0;
   i = 0;
   d = 0;
   err_n0 = 0;
   area = 0;
}

void Pid::SetSet(float v){
   set = v;
}

void Pid::SetP(float v){
   p = v;
}

void Pid::SetI(float v){
   i = v;
}

void Pid::SetD(float v){
   d = v;
}

float Pid::Process(float v){ 
   float gradient;
   float err_n1;
   // Calculate Error
   err_n1 = err_n0;
   err_n0 = set - v;
   // Accumulate Area
   area += (err_n0 + err_n1) / 2;
   // Calculate Gradient
   gradient = err_n0 - err_n1;
   // Sum to drive output
   p_out = p * err_n0;
   i_out = i * area;
   d_out = d * gradient;
   out = p_out + i_out + d_out;
   return out;
}

void Pid::GetPout(float *v){
   *v = p_out;
}

void Pid::GetIout(float *v){
   *v = i_out;
}

void Pid::GetDout(float *v){
   *v = d_out;
}

void Pid::GetErr(float *v){
   *v = err_n0;
}

void Pid::GetOut(float *v){
   *v = out;
}
