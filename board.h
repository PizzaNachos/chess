#include <vector>

enum COLOR {
    WHITE,
    BLACK
};
enum TYPE {
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
};


struct peice {
    TYPE type;
    COLOR color;
    int square_num;    
};
struct sqaure {
    int number;
    peice* peice;
};


class board
{
private:
    std::vector<peice> peices;
    std::vector<sqaure> squares;
public:
    board(std::string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    ~board();
};