//
//  main.cpp
//  lab_3.cpp
//
//  Created by Christopher Chandler on 2/10/16.
//  Copyright © 2016 Christopher Chandler. All rights reserved.
//

#include <iostream>
#include "time.h"
using namespace std;

void compute_squares(int a[], int b[], int n);
int main() {
    // insert code here...
    Time t1;
    int n = 4;
    int a[n];
    int b[n];
    for (int i=1; i<5; i++){
        a[i-1] = i;
    
    };
    compute_squares(a,b, n);
    for ( int i =0; i < n; i++){
        if( b[i] == (a[i]*a[i]))
            cout << b[i] << endl;
    }
    for ( int i =0; i < n; i++){
        if( a[i] == 2 && b[i] == 4)
            cout << "the element was squared" <<endl;
    }
    cout << sizeof(t1) << endl;
    return 0;
}

void compute_squares(int a[], int b[], int n){
    for( int i = 0; i < n; i++){
        b[i] = (a[i]*a[i]);
    }
    
    
}

