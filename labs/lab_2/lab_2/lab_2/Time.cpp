#include <iostream>
#include <algorithm>
#include "Time.h"


Time::Time(){
    hour = 0;
    minute = 0;
    second = 0;
}

Time::Time(int h, int m, int s){
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

void Time::setHour(int h){
    hour = h;
}

void Time::setMinute(int m){
    minute = m;
}

void Time::setSecond(int s){
    second = s;
}

void Time::printAmPm(){
    int pm_hour;
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

bool isEarlierThan(const Time& t1, const Time& t2){
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
    return true;
    
}
