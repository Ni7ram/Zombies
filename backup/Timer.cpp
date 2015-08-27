#include "Timer.h"

Timer::Timer(){};
Timer::~Timer(){};

//***********************************************
//              OTHER FUNCTIONS
//***********************************************

void Timer::init(){
    start = GetTickCount();
};

float Timer::GetEllapsedTime(){
    double t = GetTickCount();
    int g = (int)(t-start);
    return g;
};

void Timer::reset(){
   double t = GetTickCount();
   start = t;
};

