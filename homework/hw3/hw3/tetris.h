class Tetris
{
public:
    
    Tetris(int w);
    
    void add_piece(char shape, int rotation, int position);
    
    int remove_full_rows();
    
    int get_width();
    
    void print() const;
    
    int get_max_height() const;
    
    int count_squares();
    
//    void reallocate(int position, int increment);
    
private:
    int width;
    int *heights;
    char **data;
    
};