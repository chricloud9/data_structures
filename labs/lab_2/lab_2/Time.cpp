#include <iostream>
#include "Time.h"

Time::Time(){
    hour = 0;
    minute = 0;
    second = 0;
}

Time:Time(int h, int m, int s){
    hour = h;
    minute = m;
    second = s;
}

int Time::getHour() const{
    return hour;
}

int Time::getMinute() const{
    return minute;
}

int Time::getSecond() const{
    return second;
}

