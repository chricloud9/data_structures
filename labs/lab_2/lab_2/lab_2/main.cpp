//
//  main.cpp
//  lab_2
//
//  Created by Christopher Chandler on 2/15/16.
//  Copyright © 2016 Christopher Chandler. All rights reserved.
//

#include <iostream>
#include "Time.h"
#include <algorithm>
#include <vector>

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<Time> times;
    Time t1;
    Time t2;
    Time t3(12,4,1);
    Time t4(24,47,47);
    Time t5(11,7,1);
    t3.printAmPm();
    t4.printAmPm();
    t5.printAmPm();
//    for(int i=0; i<24; i++){
//        times.push_back(Time(i,i,i));
//    }
    for(int i=0; i<24; i++){
        times.push_back(Time(i,i,i+1));
    }
    sort(times.begin(), times.end(), isEarlierThan);
    for(int i=0; i< times.size(); i++){
        times[i].printAmPm();
    }
    cout << t1.getHour() << t2.getHour() <<endl;
    cout << "t3 is earlier than t4: " << isEarlierThan(t3,t4) << endl;
}
