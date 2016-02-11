//
//  main.cpp
//  lab_2
//
//  Created by Christopher Chandler on 2/11/16.
//  Copyright © 2016 Christopher Chandler. All rights reserved.
//

#include <iostream>
#include "Time.h"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    Time t1(5,30,59); //calls the non-default constructor w/ 3 integer arguments
    //Time t2(); // COMPILE ERROR - a buggy attempt to call the dafualt constructor
    Time t3; // the *correct* way to call the default constructor
    return 0;
}
