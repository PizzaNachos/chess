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
struct sqaure {
public:    
    int number;
    std::shared_ptr<peice> peice_on_square;
};


class board
{
private:
    std::vector<peice> peices;
    std::vector<sqaure> squares;
public:
    board();
    ~board();
    void print();
};