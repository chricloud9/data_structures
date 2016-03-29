//
//  main.cpp
//  lab_8
//
//  Created by Christopher Chandler on 3/23/16.
//  Copyright © 2016 Christopher Chandler. All rights reserved.
//

#include <iostream>

int pathfinder(int x,int y){
    int paths=0;
    if (x>0)
        paths+=pathfinder(x-1,y);
    else if (x<0)
        paths+=pathfinder(x+1,y);
    if (y>0)
        paths+=pathfinder(x,y-1);
    else if (y<0)
        paths+=pathfinder(x,y+1);
    if (x==0 && y==0)
        paths++;
    return paths;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout<<pathfinder(4,4)<<std::endl;
    std::cout<<pathfinder(1,1)<<std::endl;
    std::cout<<pathfinder(0,0)<<std::endl;
    std::cout<<pathfinder(2,1)<<std::endl;
    std::cout<<pathfinder(2,2)<<std::endl;
    return 0;
}
