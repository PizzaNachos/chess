#include <vector>
#include <memory>
#include <string>
#include <array>

enum COLOR {
    WHITE = 0,
    BLACK = 32
};
enum TYPE {
    PAWN   = 'P',
    ROOK   = 'R',
    KNIGHT = 'N',
    BISHOP = 'B',
    QUEEN  = 'Q',
    KING   = 'K'
};


struct peice {
public:
    TYPE type;
    COLOR color;
    char square_num;    

    bool moved = false;
};


struct square {
public:    
    char number;
    char peice_index;
};

struct move{
public:
    char start;
    char end;
};

struct made_move{
    char start_square;
    char end_square;
    peice start_peice;
    peice destroed_peice;
};


class board
{
private:
//Board has two arrays, one of its peices, and one of its squares
//Squares have a pointer to their peice, or just the index of that peice in the array
    std::array<peice, 32> peices;
    std::array<square, 64> squares;

    std::vector<made_move> made_moves;
    void fill_peices_squares_default();
public:
    board();
    ~board();
    void print();
    std::vector<move> get_moves(COLOR c);
    bool make_move(char start, char end);
};