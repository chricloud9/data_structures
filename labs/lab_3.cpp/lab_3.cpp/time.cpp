#include <iostream>
#include <algorithm>
#include "Time.h"


Time::Time(){
    hour = 0;
    minute = 0;
    second = 0;
}

Time::Time(uintptr_t h, uintptr_t m, uintptr_t s){
    hour = h;
    minute = m;
    second = s;
}

uintptr_t Time::getHour() const{
    return hour;
}

uintptr_t Time::getMinute() const{
    return minute;
}

uintptr_t Time::getSecond() const{
    return second;
}

void Time::setHour(uintptr_t h){
    hour = h;
}

void Time::setMinute(uintptr_t m){
    minute = m;
}

void Time::setSecond(uintptr_t s){
    second = s;
}

void Time::printAmPm(){
    uintptr_t pm_hour;
    if(hour>11){
        if (hour == 12)
            cout << hour << ":";
        else{
            pm_hour = hour-12;
            cout << pm_hour << ":";
        }
    
        if (minute < 10)
            cout << "0" << minute <<":";
        else
            cout << minute << ":";
        if (second < 10)
            cout << "0" << second << " pm" << endl;
        else
            cout << second <<" pm"<< endl;
    }
    else{
        if (hour == 0)
            cout << 12 << ":";
        else
            cout << hour << ":";
            if(minute < 10)
                cout << "0" << minute << ":";
            else
                cout << minute << ":";
        if (second < 10)
            cout << "0" << second << " am";
        else
            cout << second << " am";
        
}
}

bool Time::isEarlierThan(const Time& t1, const Time& t2){
    if(t1.getHour() >= t2.getHour()){ //if t1 hour is greater than t2 hour
        if(t1.getHour() == t2.getHour()){ //if the hours are equal
            if (t1.getMinute() >= t2.getMinute()) { // if t1 minute is greater than t2 minute
                if(t1.getMinute() == t2.getMinute()){ // if t1 minute is equal to t2 minute
                    if(t1.getSecond() > t2.getSecond()){ // if t1 second is greater than t2 second
                        return false; // the minutes and hours are equal, t1 second is greater
                    }
                    else // t1 second is less than t2 second
                        return true;
                }
               
            }
            else // t1 minute is greater than t2 minute
                return false;
        }
    }
    else // if t1 hour is less than t2 hour
        return true;
    
}
void change_times(const Time& t1, const Time& t2){
    t1.setHour(t1.getHour() + 1);
    t1.setMinute(t1.getMinute() +1);
    t2.setHour(t2.getHour() +2);
    t2.setMinute(t2.getMinute() + 2);
}