//
//  main.cpp
//  hw5
//
//  Created by Christopher Chandler on 3/9/16.
//  Copyright © 2016 Christopher Chandler. All rights reserved.
//

#include <iostream>
#include <list>
#include "MultiLL.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::list<int> kayla;
    for(int i = 0; i<47; ++i){
        kayla.push_back(i);
    }
    std::cout<<"contents of kayla: "<<std::endl;
    
    return 0;
}
