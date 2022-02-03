#include "board.h"
#include <string>
#include <memory>
#include <iostream>

// std::string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"
board::board() {
    this->squares.push_back(square{number: 0, peice{ROOK,   WHITE, 0}});
    this->squares.push_back(square{1, peice{KNIGHT, WHITE, 1}});
    this->squares.push_back(square{2, peice{BISHOP, WHITE, 2}});
    this->squares.push_back(square{3, peice{QUEEN,  WHITE, 3}});
    this->squares.push_back(square{4, peice{KING,   WHITE, 4}});
    this->squares.push_back(square{5, peice{BISHOP, WHITE, 5}});
    this->squares.push_back(square{6, peice{KNIGHT, WHITE, 6}});
    this->squares.push_back(square{7, peice{ROOK,   WHITE, 7}});
    for(int i = 8; i < 16; i++){
        this->squares.push_back(square{i, peice{PAWN,   WHITE, i}});
    }


    // for(int i = 16; i < 48; i++){
    //     this->squares.push_back(square{i, NULL});
    // }

    // this->peices.push_back(peice{KING,  WHITE, 4});
    // this->peices.push_back(peice{QUEEN, WHITE, 3});
    // this->peices.push_back(peice{ROOK,  WHITE, 0});
    // this->peices.push_back(peice{ROOK,  WHITE, 7});
    // this->peices.push_back(peice{BISHOP, WHITE, 1});
    // this->peices.push_back(peice{BISHOP, WHITE, 6});
    // this->peices.push_back(peice{KNIGHT, WHITE, 2});
    // this->peices.push_back(peice{KNIGHT, WHITE, 5});

    // this->peices.push_back(peice{KING,  BLACK, 4 + 56});
    // this->peices.push_back(peice{QUEEN, BLACK, 3 + 56});
    // this->peices.push_back(peice{ROOK,  BLACK, 0 + 56});
    // this->peices.push_back(peice{ROOK,  BLACK, 7 + 56});
    // this->peices.push_back(peice{BISHOP, BLACK, 1 + 56});
    // this->peices.push_back(peice{BISHOP, BLACK, 6 + 56});
    // this->peices.push_back(peice{KNIGHT, BLACK, 2 + 56});
    // this->peices.push_back(peice{KNIGHT, BLACK, 5 + 56});

    // for(int i = 0; i < 8; i++){ 
    //     this->peices.push_back(peice{PAWN, WHITE, i + 8});
    //     this->peices.push_back(peice{PAWN, BLACK, i + 48});
    // }


   
    // std::cout << this->peices[0].square_num;
}
void board::print(){
    for(square s : this->squares){
         s.number % 8 == 0 ? (std::cout << std::endl << s.number) : (std::cout << s.number);
        // std::cout << (s.number);// % 8 == 0 ? " " + s.number : "\n" + s.number);
    }
    std::cout << std::endl;

}
board::~board()
{
}
