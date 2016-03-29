//
//  main.cpp
//  hw6
//
//  Created by Christopher Chandler on 3/21/16.
//  Copyright © 2016 Christopher Chandler. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream> // string streams

#include <stdlib.h>     /* atoi */
using namespace std;

//std::vector<std::vector<bool>> make_vector(int rows, int cols){
//    std::vector<std::vector<bool>> game;
//}
int main(int argc, const char * argv[]) {
    

    // Open and test the input file.
    ifstream istr(argv[1]);
    if (!istr) {
        cerr << "Could not open " << argv[1] << " to read\n";
        return 1;
    }
    // Open and test the output file.
    ofstream ostr(argv[2]);
    if (!ostr) {
        cerr << "Could not open " << argv[2] << " to write\n";
        return 1;
    }
    // data processing
    int row; // the number of rows in the board
    int col; // the number of columns in the board
    
    string str;
    vector<string> ships;
    vector<int> num_in_row;
    vector<int> num_in_col;
    vector<string> process;
    while(istr >> str){
        process.push_back(str);
    }
    bool checked_rows = false;
    bool checked_cols = false;
    for(int i = 0; i < process.size(); i++){
        cout << process[i] << endl;
        if(process[i] == "rows"){
            checked_rows = true;
        }
        if(process[i] == "cols"){
            checked_cols = true;
        }
        if(process[i] == "cols" && checked_rows == true){
            checked_rows = false;
        }
        if(process[i] == "board"){
            row = stoi(process[i+1]);
            col = stoi(process[i+2]);
        }
        cout << process[i] << endl;
        if ( checked_rows == true && checked_cols == false){
            num_in_row.push_back(stoi(process[i+1]));
        }

        
    }
//    for(int i =0; i < ships.size(); ++i){
//        cout << "ships: "<<ships[i] << endl;
//    }
    for(int i =0; i < num_in_row.size(); ++i){
        cout <<"num in rows: "<< num_in_row[i];
    }

    // insert code here...
    //make a 2d vector that is a temporary holder vector filled with
    //false booleans that represent water
    //information given: board sizes, how many things are in each row,
    //how many things are in each colum
    //go through temporary vector created that has size row and column
    //cross reference rows and columns
    //if you are in the row specified and that number of things in row
    //is greater than 0, loop through the column at that row
    //and add to that row, column index a true boolean
    //then pass in the vector to board class to change these values to ship types
    
    //make a test to pass in a vector to the board class that couts a solution

    return 0;
    //make a board class
    //contains rows and columns vector
    //make a ship class
}


