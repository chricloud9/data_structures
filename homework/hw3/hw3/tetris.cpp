#include <iostream>
#include "tetris.h"

//Similarly, when a full row is identified during scoring, all of the columns will decrease in height. You are
//required to re-allocate new, smaller arrays for every column and copy the remaining squares of data to the
//new arrays.
Tetris::Tetris(int w){
    width = w;
    heights = new int[w];
    for(int i=0; i < w; ++i ){
        heights[i] = 0;
    }
    data = new char*[w]; // single dimensional array of chars
    for(int i=0; i<w; i++)
    {
        data[i] = new char[0]; // adds an array to each dimension of the array
        // each of these arrays in our data array has 0 elements in it
        // we essentially have data[col][row], each ready to be filled with more chars
    }
}

int Tetris::get_width(){
    return width;
}
//void Tetris::reallocate(int position, int increment){
//    
//}
void Tetris::add_piece(char shape, int rotation, int position)
{
    int *h = heights;
    int tallest = 0;
    
    if(shape == 'I')
    {
        if(rotation==0 || rotation==180) // both orientations structurally the same
        {
            board[position] = new char[h[position]+4]; // add an array of length h[position]+4]
            for(int i = 0; i < h[position]; ++i){ //copy the old contents into the new contents
//                std::cout << "copying old contents"<<std::endl;
                board[position][i] = data[position][i];
//                std::cout<<"what is being copied in"<< board[position][i] << std::endl;
                
            }
            std::cout<<"data position before deletion: "<< data[position] <<std::endl;

            delete[] data[position];
            std::cout<<"data position after deletion: "<< data[position] <<std::endl;
//          std::cout<< "what was copied in"<<board[position] << std::endl;
            data[position] = new char[h[position]+4]; //at position create enough space for the I
            std::cout<<"data["<<position<<"] is: "<<data[position]<<std::endl;
            std::cout<<"board["<<position<<"] is: "<<board[position]<<std::endl;
            for(int i =0; i< h[position]; ++i){
                data[position][i] = board[position][i];
            }
//            data[position] = board[position]; //make a for loop to fill data[position]
            
            std::cout <<"data[position] is:"<< data[position] << std::endl;
            delete[] board[position];
            std::cout << "h[position] before the for loop" << h[position] << std::endl;
            for(int i = h[position]; i < h[position]+4; ++i){
                data[position][i] = 'I'; // place on top of the tallest one in that column
            }
            
            h[position] += 4;
            
            
        }
        if(rotation ==90 || rotation == 270){
            for(int i=0; i<4; ++i){ // we want to place it on top of the tallest block that
                // is within the range of the position it wants to be placed in so we do not
                //replace any existing blocks
                if(tallest < h[position+i])
                    tallest = h[position+i];
                std::cout<<"tallest: "<<tallest<<std::endl;
            }
            std::cout<<"tallestoutside: "<<tallest<<std::endl;

            for(int i=0; i < 4; ++i){ // allocate new arrays in the four horizontal spaces
                //that are equal to the tallest in that 4 range plus 1 because
                //it's going to have to be on top of some other block
                board[position+i] = new char[tallest+1];
                for(int j=0; j<tallest; j++){// fill our newly created rows with old data
                    board[position+i][j] = data[position+i][j];
//                    std::cout<<"in copy loop board["<<position + i <<"]["<<j<<"]"<< "is: "<<board[position+i][j] << std::endl; //looks good
                }
            }
            
            for(int i=0; i < 4; ++i){
                delete[] data[position+i]; // delete our old data
                data[position+i] = new char[tallest+1]; // but not for long
                for(int j=0; j<tallest; j++){
                     std::cout<<"in fill loop data["<<position + i <<"]["<<j<<"]"<< "is: "<<data[position+i][j] << std::endl;
                    if(board[position+i][j] == 'J' || board[position+i][j] == 'L' || board[position+i][j] == 'S' || board[position+i][j] == 'Z' || board[position+i][j] == 'T' || board[position+i][j] == 'O' || board[position+i][j] == 'I')
                       data[position+i][j] = board[position+i][j];
                    else
                        data[position+i][j] = ' ';
//                    data[position+i][j] = board[position+i][j];
//                    std::cout<<"in fill loop data["<<position + i <<"]["<<j<<"]"<< "is: "<<data[position+i][j] << std::endl; //looks good too
                }
            }
            
            
            for(int i=0; i <4; ++i ){
                std::cout<<"position + i: "<<position + i<<" tallest + 1: "<<tallest+1<<std::endl;
                data[position+i][tallest] = 'I';
                std::cout<<"data["<<position+i<<"]["<<tallest+1<<"] is: "<<data[position+i][tallest+1]<<std::endl;
                 std::cout<<"data["<<position+i<<"]["<<tallest-2<<"] is: "<<data[position+i][tallest-2]<<std::endl;
                 std::cout<<"data["<<position+i<<"]["<<tallest-1<<"] is: "<<data[position+i][tallest-1]<<std::endl;
                delete[] board[position+i];
                h[position+i] = tallest+1;
            }
        }
    }
    if(shape == 'O'){
        
        board[position] = new char[h[position]+2];
        board[position] = new char[h[position+1]+2];
        
        for(int i =0; i<2; ++i){
            board[position+i] = 
        }
        
        tallest = 0;
        for(int i = 0; i <2; ++i){
            if(tallest < h[position+i])
                tallest = h[position+i];
        }
        for(int i=0; i<2; ++i){
            for(int j=0; j<2; ++j){
                data[position+i][tallest+j] = 'O';
                std::cout<<"filling O";
            }
        }
        h[position] = h[position]+2;
        h[position+1] =h[position+1]+2;
    
    }
    if(shape == 'T'){
        
        if(rotation == 0){
            for(int i = 0; i <3; ++i){
                if(h[position-1 + i]>tallest)
                    tallest = h[position-1+i];
            }
            
            data[position][tallest] = 'T';
            data[position][tallest+1] = 'T';
            data[position-1][tallest+1] = 'T';
            data[position+1][tallest+1] = 'T';
        }
        if(rotation == 90){
            tallest=h[position];
            for(int i = 0; i < 3; i++){
                data[position][tallest+i] = 'T';
            }
            data[position-1][tallest+1] = 'T';
        }
//        if(rotation == 180){
////            tallest = h[position];
////            board[position][]
//        }
    }
    
}

int Tetris::get_max_height() const{
    int hold = 0;
    for(int i=0; i<width; ++i){
        if (heights[i] > hold)
            hold = heights[i];
    }
    return hold;
}

int Tetris::count_squares(){
    return 0;
}