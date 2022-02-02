#include "board.h"
#include <string>
#include <memory>
#include <iostream>

// std::string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"
board::board() {
    
    this->peices.push_back(peice{KING,  WHITE, 4});
    this->peices.push_back(peice{QUEEN, WHITE, 3});
    this->peices.push_back(peice{ROOK,  WHITE, 0});
    this->peices.push_back(peice{ROOK,  WHITE, 7});
    this->peices.push_back(peice{BISHOP, WHITE, 1});
    this->peices.push_back(peice{BISHOP, WHITE, 6});
    this->peices.push_back(peice{KNIGHT, WHITE, 2});
    this->peices.push_back(peice{KNIGHT, WHITE, 5});

    this->peices.push_back(peice{KING,  BLACK, 4 + 56});
    this->peices.push_back(peice{QUEEN, BLACK, 3 + 56});
    this->peices.push_back(peice{ROOK,  BLACK, 0 + 56});
    this->peices.push_back(peice{ROOK,  BLACK, 7 + 56});
    this->peices.push_back(peice{BISHOP, BLACK, 1 + 56});
    this->peices.push_back(peice{BISHOP, BLACK, 6 + 56});
    this->peices.push_back(peice{KNIGHT, BLACK, 2 + 56});
    this->peices.push_back(peice{KNIGHT, BLACK, 5 + 56});

    for(int i = 0; i < 8; i++){ 
        this->peices.push_back(peice{PAWN, WHITE, i + 8});
        this->peices.push_back(peice{PAWN, BLACK, i + 48});
    }

    // this->squares 
    // std::cout << this->peices[0].square_num;
}
void board::print(){


}
board::~board()
{
}
