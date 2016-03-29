#ifndef Board_hpp
#define Board_hpp
#include <iostream>
#include <list>
class Board{
public:
    Board(int row, int col);
    void add_square_from(int row, int col, std::string type);
};

#endif

