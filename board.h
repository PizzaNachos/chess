#include <vector>
#include <memory>
#include <string>

enum COLOR {
    WHITE,
    BLACK
};
enum TYPE {
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};


struct peice {
public:
    TYPE type;
    COLOR color;
    int square_num;    
};


struct square {
public:    
    int number;
    peice peice_on_square;
};


class board
{
private:
    std::vector<std::shared_ptr<peice>> peices;
    std::vector<square> squares;
public:
    board();
    ~board();
    void print();
};