//
//  main.cpp
//  average
//
//  Created by Christopher Chandler on 2/15/16.
//  Copyright © 2016 Christopher Chandler. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "input an integer corresponding to the number of floats you want to enter later";
    int length;
    cin >> length;
    float a[length];
    float sum = 0;
    float average;
    for (int i =0; i <length; i++){
        cout << "enter a float";
        float dec;
        cin >> dec;
        a[i] = dec;
        sum += dec;
    }
    average = sum / length;
    cout << "the average is: " << average << endl;
    for (int i =0; i < length; i++){
        if(a[i] < average){
            cout << a[i] << " is less than the average"<< endl;
        }
        
    }
}
