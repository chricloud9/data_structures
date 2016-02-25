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
    std::cout << "width: " << width << std::endl;
    char** board = new char*[width];
    int *h = heights;
    int tallest = 0;
    
    if(shape == 'I')
    {
        if(rotation==0 || rotation==180) // both orientations structurally the same
        {
            std::cout<<"h[position+4]"<<h[position+4];
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
            tallest = 0;
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
//                     std::cout<<"in fill loop data["<<position + i <<"]["<<j<<"]"<< "is: "<<data[position+i][j] << std::endl;
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
        tallest = 0;
        board[position] = new char[h[position]+2];
        board[position+1] = new char[h[position+1]+2];
        for(int i=0; i<2; ++i){ // we want to place it on top of the tallest block that
            // is within the range of the position it wants to be placed in so we do not
            //replace any existing blocks
            if(tallest < h[position+i])
                tallest = h[position+i];
            std::cout<<"tallest: "<<tallest<<std::endl;
        }
        for(int i =0; i<2; ++i){
            for(int j =0; j< tallest; j++){
                board[position+i][j] = data[position+i][j];
            }
        }
        for(int i=0; i < 2; ++i){
            delete[] data[position+i]; // out with the old
            data[position+i] = new char[tallest+2]; // in with the new
            for(int j = 0; j<tallest; j++){
//                std::cout<<"in fill loop data["<<position + i <<"]["<<j<<"]"<< "is: "<<data[position+i][j] << std::endl;
                if(board[position+i][j] == 'J' || board[position+i][j] == 'L' || board[position+i][j] == 'S' || board[position+i][j] == 'Z' || board[position+i][j] == 'T' || board[position+i][j] == 'O' || board[position+i][j] == 'I')
                    data[position+i][j] = board[position+i][j];
                else
                    data[position+i][j] = ' ';
            }
        }
        
        for(int i=0; i<2; ++i){
            delete[] board[position+i];
            for(int j=0; j<2; ++j){
                data[position+i][tallest+j] = 'O';
                std::cout<<"filling O";
            }
        }
        h[position] = h[position]+2;
        h[position+1] =h[position+1]+2;
    
    }
    if(shape == 'T'){
        tallest = 0;
        
        if(rotation == 0 || rotation == 180){
            for(int i = 0; i<3; ++i){
                if(tallest < h[position+i])
                    tallest = h[position+i];
            }

            for(int i=0; i < 3; ++i){
//                std::cout<<"creating new board array at column: " <<position+i << std::endl;

                board[position+i] = new char[tallest+2];
                for(int j=0; j<tallest; j++){
                    board[position+i][j] = data[position+i][j];
//                    std::cout<<"board["<<position+i<<"]["<<j<<"]"<<" is: "<< data[position+i][j]<<std::endl;
                }
            }
            
            for(int i=0; i<3; ++i){
                delete[] data[position+i]; //gone so soon?
                data[position+i] = new char[tallest+2]; //bigger and better than ever
                for(int j=0; j<tallest+2; j++){ // could cause errors
                    if(board[position+i][j] == 'J' || board[position+i][j] == 'L' || board[position+i][j] == 'S' || board[position+i][j] == 'Z' || board[position+i][j] == 'T' || board[position+i][j] == 'O' || board[position+i][j] == 'I')
                        data[position+i][j] = board[position+i][j];
                    else
                        data[position+i][j] = ' ';
                }
            }
            if(rotation == 0){
                for(int i = 0; i <3; ++i){
//                    std::cout << "tallest is: " <<tallest<<" i is: "<<i<< std::endl;
                    delete[] board[position+i];
                    std::cout<<"tallest: "<<tallest<<std::endl;
                    if(tallest != 0)
                        if(i==1){
                            data[position+1][tallest] = 'T';
                            std::cout<< "this ran" << std::endl;
                            
                            h[position+i] = tallest+2;
                        }
        //                std::cout<<"board["<<position+i<<"] is: "<< board[position+i];
                        data[position+i][tallest+1] = 'T';
                        std::cout<<i<<" is i"<<std::endl;
                        
                        h[position+i] = tallest+2;
                    if(tallest ==0){
                        if(i==1){
                            data[position+1][tallest] = 'T';
                            std::cout<< "this ran" << std::endl;
                            
                            h[position+i] = tallest+2;
                        }
                        data[position+i][tallest+1] = 'T';
                        std::cout<<i<<" is i"<<std::endl;
                    }
                }
            }
            else if(rotation == 180){
                for(int i = 0; i <3; ++i){
//                    std::cout << "tallest is: " <<tallest<<" i is: "<<i<< std::endl;
                    delete[] board[position+i];
                    if(i==1){
                        data[position+i][tallest] = 'T';
                        data[position+i][tallest+1] = 'T';
                        
                        h[position+i] = tallest +2;
                        std::cout<<"tallest 180 = " << tallest+3 << std::endl;
                        std::cout<< "this ran 180" <<" and h["<<position+i<<"] is: "<<h[position+i]<< std::endl;
                        
                    }
                    //                std::cout<<"board["<<position+i<<"] is: "<< board[position+i];
                    if(i!=1){
                        data[position+i][tallest] = 'T';
                        std::cout<<i<<" is i"<<std::endl;
                        
                        h[position+i] = tallest+1;
                    }
                }
            }
        }
        if(rotation == 90 || rotation == 270){
            int tallest_position = 0;
            bool same_height;
            if(h[position+1] == h[position])
                same_height = true;
            else
                same_height = false;
            for(unsigned int i =0; i < 2; ++i){
                if(tallest < h[position+i]){
                    tallest = h[position+i];
                    tallest_position = position+i;
                }
            }
            if(rotation == 90){
                for(unsigned int i=0; i<2; ++i){
                    board[position+i] = new char[tallest];
                    for(unsigned int j=0; j<tallest; j++){
                        board[position+i][j] = data[position+i][j];
                    }
                }
                for(unsigned int i=0; i<2; ++i){
                    delete[] data[position+i];
                    data[position+i] = new char[tallest+2];
                    if(i==1){
                        for(int j=0; j<tallest+3; j++){
                            if(board[position+i][j] == 'J' || board[position+i][j] == 'L' || board[position+i][j] == 'S' || board[position+i][j] == 'Z' || board[position+i][j] == 'T' || board[position+i][j] == 'O' || board[position+i][j] == 'I')
                                data[position+i][j] = board[position+i][j];
                            else
                                data[position+i][j] = ' ';

                        }
                    }
                    for(int k = 0; k< tallest+1; k++){
                        if(board[position+i][k] == 'J' || board[position+i][k] == 'L' || board[position+i][k] == 'S' || board[position+i][k] == 'Z' || board[position+i][k] == 'T' || board[position+i][k] == 'O' || board[position+i][k] == 'I')
                            data[position+i][k] = board[position+i][k];
                        else
                            data[position+i][k] = ' ';
                    }

                
                }
                for(int i =0; i <2; ++i){
                    delete[] board[position+i];
                    if(i==0){// because of the shape of this one we need to make sure we are not replacing stuff that already is there
                        bool temp = (tallest_position == position);
                        std::cout<<"same height is: "<<same_height<<"and tallest_position == position "<<temp<<std::endl;
                        if(tallest_position == position && same_height){
                            std::cout<<"position is: "<<position<<"tallest is: "<<tallest<<std::endl;
                            data[position][tallest+1] = 'T';
                            h[position] = tallest+2;
                            std::cout<<"tallest position running and same height is true : "<<std::endl;
                            for(int j=0; j<3; j++){
                                data[position+1][tallest+j] = 'T';
                            }
                        }
                        else if(tallest_position != position && !same_height){
                            
                            data[position][tallest+2] = 'T';
                            h[position] = tallest+2;
                            
                        }
                        else if(tallest_position == position && !same_height){
                            std::cout<<"tallest position == position && same_height == false"<<std::endl;
                            data[position][tallest] = 'T';
                            std::cout<<"data["<<position<<"]["<<tallest+1<<"] is: "<<data[position][tallest+1]<<std::endl;
                            h[position] = tallest+1;
                            for(int j=0; j<3; j++){
                                data[position+1][tallest-1+j] = 'T';
                            }
                        }
                    }
                    
                    if(i==1){
                        h[position+i] = tallest+3;
                    }
                }
            }
        }
        if(rotation == 270){
            std::cout<<"tallest in 270 "<<tallest<<std::endl;
            board[position] = new char[tallest]; // one shorter one idnex to the right because it looks like
                //  T
                //  TT
                //  T
                // -----
            if(tallest == 0)
                board[position+1] = new char[tallest];
            else
                board[position+1] = new char[tallest-1]; // should be tallest -1, this will cause memory problems later
            for(int j=0; j<tallest; j++){ // copy data into board
                board[position][j] = data[position][j];
                std::cout<<"j: "<<j<<std::endl;
                board[position+1][j] = data[position+1][j];
            }
            delete[] data[position];
            delete[] data[position+1];
            data[position] = new char[tallest+3]; // again,
            //  T
            //  TT
            //  T
            // -----
            // is the shape
            data[position+1] = new char[tallest+2];
            for(unsigned int i=0; i<2; ++i){
                if(i==1){
                    for(int j=0; j<tallest+2; j++){
                        if(board[position+i][j] == 'J' || board[position+i][j] == 'L' || board[position+i][j] == 'S' || board[position+i][j] == 'Z' || board[position+i][j] == 'T' || board[position+i][j] == 'O' || board[position+i][j] == 'I')
                            data[position+i][j] = board[position+i][j];
                        else
                            data[position+i][j] = ' ';
                        
                    }
                }
                else{
                    for(int j=0; j<tallest+3; j++){
                        if(board[position+i][j] == 'J' || board[position+i][j] == 'L' || board[position+i][j] == 'S' || board[position+i][j] == 'Z' || board[position+i][j] == 'T' || board[position+i][j] == 'O' || board[position+i][j] == 'I')
                            data[position+i][j] = board[position+i][j];
                        else
                            data[position+i][j] = ' ';
                    }
                
                }
                for(int k = 0; k< tallest+1; k++){
                    if(board[position+i][k] == 'J' || board[position+i][k] == 'L' || board[position+i][k] == 'S' || board[position+i][k] == 'Z' || board[position+i][k] == 'T' || board[position+i][k] == 'O' || board[position+i][k] == 'I')
                        data[position+i][k] = board[position+i][k];
                    else
                        data[position+i][k] = ' ';
                }
                

            }
            
            int tallest_position = 0;
            bool same_height;
            if(h[position+1] == h[position])
                same_height = true;
            else
                same_height = false;
            for(unsigned int i =0; i < 2; ++i){
                if(tallest < h[position+i]){
                    tallest = h[position+i];
                    tallest_position = position+i;
                }
            }
            std::cout<<"same_height="<<same_height<<" tallest position: "<<tallest_position<<" position:"<<position<<std::endl;
            
            for(int i =0; i<2; ++i){
                delete[] board[position+i];
            }
            if(position!= tallest_position && same_height == false){
                std::cout<<"RUNNING!"<<std::endl;
                for(int i =0; i<3; ++i){
                    data[position][tallest+i] = 'T';
                }
                data[position+1][tallest+1] = 'T';
                h[position] = tallest+3;
                h[position] = tallest+2;
            }
            if(position == tallest_position && same_height ==true){
                std::cout<<"running!"<<std::endl;
                for(int i =0; i<3; ++i){
                    data[position][tallest+i] = 'T';
                }
                data[position+1][tallest+1] = 'T';
                h[position] = tallest+3;
                std::cout<<"tallest+3 = "<<tallest+3<<" and position is: "<<position<<std::endl;
                h[position+1] = tallest+2;
                
            }
            else{
//                std::cout<<"gnrkjaljdl;kasjd"<<std::endl;
//                std::cout<<"tallest"<<tallest+2<<std::endl;
                for(int i=0; i<3; ++i){
                    data[position][tallest+i] = 'T';
                }
                data[position+1][tallest+1] = 'T';
                h[position] = tallest+3;
                h[position+1] = tallest+2;
            }
   
        }// end of if(rotation == 270)

    }
    if(shape == 'Z'){
        tallest = 0;
        for(int i = 0; i< 3; ++i){
            if(h[position+i]>tallest){
                tallest = h[position+i];
            }
        }
        if(rotation == 0 || rotation == 180){
            for(int i = 0; i<3; ++i){
                board[position+i] = new char[tallest];
                for(int j = 0; j< tallest; j++){
                    board[position+i][j] = data[position+i][j]; // copt old data into new
                }
            }
            
        
        for(int i=0; i<3; ++i){
            delete[] data[position+i]; //get rid of old data
        }
         //make new data in the right size
        data[position] = new char[tallest+2]; // what we need for Z regular
        data[position+1] = new char[tallest+2];
        data[position+2] = new char[tallest+1];
        //copy board data over
        for(int i=0; i<3; ++i){
            for(int j=0; j<tallest+1; j++){
                if(board[position+i][j] == 'J' || board[position+i][j] == 'L' || board[position+i][j] == 'S' || board[position+i][j] == 'Z' || board[position+i][j] == 'T' || board[position+i][j] == 'O' || board[position+i][j] == 'I')
                    data[position+i][j] = board[position+i][j];
                else
                    data[position+i][j] = ' ';
            }
        }//data copied back over
        for(int i = 0; i <3; ++i){
            delete[] board[position+i]; // delete board data
        }
            
            
            std::cout<<"tallest"<<tallest<<position<<"position"<<std::endl;
            std::cout << tallest +1<<" tallest+1";
            //works if position is same height as position +1 and +2
            data[position][tallest+1] = 'Z';
            data[position+1][tallest+1] = 'Z';
            data[position+2][tallest] = 'Z';
            data[position+1][tallest] = 'Z';
            

            
            std::cout<<"data[position+2][tallest+1]"<<data[position+2][tallest]<<std::endl;
            std::cout<<"data[position][tallest+1]"<<data[position][tallest]<<std::endl;
//        data[position+2][tallest] = 'Z';
            h[position] = tallest+2;
            h[position+1] = tallest+2;
            h[position+2] = tallest+1;
        }
    }

    
    if(shape == 'J'){
        if(rotation == 90){
            int tallest_position = 0;
            for(unsigned int i =0; i < 2; ++i){
                if(tallest < h[position+i]){
                    tallest = h[position+i];
                    tallest_position = position+i;
                }
            }
            for(unsigned int i=0; i<2; ++i){
                board[position+i] = new char[tallest];
                for(unsigned int j=0; j<tallest; j++){
                    board[position+i][j] = data[position+i][j];
                }
            }
            for(unsigned int i=0; i<2; ++i){
                delete[] data[position+i];
                data[position+i] = new char[tallest+2];
                if(i==1){
                    for(int j=0; j<tallest+3; j++){
                        if(board[position+i][j] == 'J' || board[position+i][j] == 'L' || board[position+i][j] == 'S' || board[position+i][j] == 'Z' || board[position+i][j] == 'T' || board[position+i][j] == 'O' || board[position+i][j] == 'I')
                            data[position+i][j] = board[position+i][j];
                        else
                            data[position+i][j] = ' ';
                        
                    }
                }
                for(int k = 0; k< tallest+1; k++){
                    if(board[position+i][k] == 'J' || board[position+i][k] == 'L' || board[position+i][k] == 'S' || board[position+i][k] == 'Z' || board[position+i][k] == 'T' || board[position+i][k] == 'O' || board[position+i][k] == 'I')
                        data[position+i][k] = board[position+i][k];
                    else
                        data[position+i][k] = ' ';
                }
                
                
            }
            for(int i =0; i <2; ++i){
                delete[] board[position+i];
                if(i==0){
                    if(tallest_position == position){
                        data[position][tallest] = 'J';
                        h[position] = tallest+1;
                    }
                    else{
                        data[position][tallest+1] = 'J';
                        h[position] = tallest+2;
                    }
                }
                if(i==1){
                    for(int j = 0; j<3; j++){
                        data[position][tallest+j+1] = 'J';
                    }
                }
                if(i==1){
                    h[position+i] = tallest+3;
                }
            }
            
        }
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