//
//  main.cpp
//  lab_7
//
//  Created by Christopher Chandler on 3/9/16.
//  Copyright © 2016 Christopher Chandler. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <list>

#include "dslist.h"

int main() {
    
    // =======================================
    // CHECKPOINT 1
    
    // create a list of the sqrt of the first 10 integers
//    dslist<double> a;
//    for (int i = 0; i < 10; ++i)
//        a.push_back(sqrt(i));
//    
//    
//    // print out details of the list
//    std::cout << "a.size() = " << a.size() << " --- should be 10" << std::endl;
//    std::cout << "a.front() = " << a.front() << " --- should be 0.0 " << std::endl;
//    std::cout << "a.back() = " << a.back() << " --- should be 3.0" << std::endl;
//    dslist<double>::iterator itr;
//    std::cout << "Elements = ";
//    for (itr = a.begin(); itr != a.end(); ++itr)
//        std::cout << " " << *itr;
//    std::cout << std::endl;
//    
//    
    // clear out the list
//    a.clear();
    
    
    // =======================================
    // CHECKPOINT 2
    
    std::list<int> kayla;
    std::cout<<"where kayla lives on the stack: ";
    std::cout << &kayla << std::endl;
    kayla.push_back(0);
    for(int p; p<47; p++){
        kayla.push_back(p);
    }
    std::cout << "at kayla's first node: " <<std::endl;
    std::list<int>::iterator vibr = kayla.begin();
    std::cout<<"what's in kayla: "<<std::endl;
    while(vibr != kayla.begin()){
        vibr -- ;
        std::cout<< *vibr;
    }
    
     std::list<int> b; // standard library list of ints called b
     for (int i = 0; i < 10; i++) {
     b.push_back(i);
     }
    std::list<std::string> playlist;
    
     // iterate backwards
     std::cout << "elements: ";
     std::list<int>::iterator itr2 = b.end();
     while (itr2 != b.begin()) {
     itr2--;
         std::cout << *itr2<<std::endl;
     std::cout << " " << *itr2;
     }
     std::cout << std::endl;
    // iterate backwards
    std::cout << "elements: ";
    std::list<int>::iterator newitr2 = b.end();
    while (itr2 != b.begin()) {
        itr2--;
        std::cout << " " << *itr2;
    }
    std::cout << std::endl;
    
     
     
     // USING DSLIST
     dslist<int> c;
     for (int i = 0; i < 5; i++) {
     c.push_back(i);
     }
     
     // iterate backwards
     std::cout << "elements: ";
     dslist<int>::iterator itr3 = c.end();
     while (itr3 != c.begin()) {
     itr3--;
     std::cout << " " << *itr3;
     }
     std::cout << std::endl;
    
    

    return 0;
}
