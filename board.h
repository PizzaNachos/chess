#include <vector>
#include <memory>
#include <string>
#include <array>
#include <unordered_map>

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
    char start_peice_index;
    char destroed_peice_index;
};


class board
{
private:
//Board has two arrays, one of its peices, and one of its squares
//Squares have a pointer to their peice, or just the index of that peice in the array
    //Peice 33 is a non-peice
    std::array<peice, 33> peices;

    //Sqaure 65 is the dead peice square
    std::array<square, 65> squares;
    std::vector<made_move> made_moves;
    std::unordered_map<int,int> squares_to_direction_map;

    void fill_peices_squares_default();
    bool can_move_to_square(char square_num, COLOR c);
    int squares_in_direction(int start_square, int direction);
public:
    board();
    ~board();
    void print();
    std::vector<move> get_moves(COLOR c);
    made_move make_move(move m);
    void unmake_move(made_move m);
};