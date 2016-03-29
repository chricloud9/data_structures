//
//  main.cpp
//  test
//
//  Created by Christopher Chandler on 2/28/16.
//  Copyright © 2016 Christopher Chandler. All rights reserved.
//

#include <iostream>
int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
//    float x = 5, y = 9;
//    float *p = &x, *q = &y;
//    std::cout<<"x: "<<x<<", y: "<<y<<std::endl;
//    std::cout<<"*p "<<*p<<", *q: "<<*q<<std::endl;
//    *p = 17.0;
//    std::cout<<"p: "<<p<<" *p"<<*p<<std::endl;
//    *q = *p;
//    std::cout<<"*q "<<*q<<", *p: "<<*p<<"p "<<p<<" q "<<q<<std::endl;
//    q = p;
//    std::cout<<"q"<<q<<" p "<<p<<" *q "<<*q <<" *p " <<*p<<std::endl;
//    *q = 13.0;
//    std::cout<<"q "<<q<<" *q "<<*q<<" p "<<p<< " *p "<<*p<<std::endl;
//    std::cout<<"x "<<x<<" y "<<y<<std::endl;
//
    double * p = new double;
    *p = 35.1;
    double * q = p;
    std::cout << *p << " " << *q << std::endl;
    p = new double;
    *p = 27.1;
    std::cout << *p << " " << *q << std::endl;
    *q = 12.5;
    std::cout << *p << " " << *q << std::endl;
    delete p;
    delete q;
    return 0;
    
}