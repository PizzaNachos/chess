#include "board.h"
#include <string>
#include <memory>
#include <iostream>

// std::string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"
board::board() {
    this->fill_peices_squares_default();
}
void board::print(){
    for(int i = 0; i < this->squares.size(); ++i){
        if((i % 8 == 0)) printf("\n");

        if(squares[i].peice_index == -1) {
            printf(" . ");
        } else {
            peice p = this->peices[squares[i].peice_index];
            printf(" %c ",(p.type + p.color));
        }
    }
    std::cout << std::endl;
}
bool board::make_move(char start, char end){
    squares.at(end) = squares.at(start);
    squares.at(start).peice_index = -1;
    return true;
}
std::vector<move> board::get_moves(COLOR c){
    std::vector<move> moves;
    for(peice p : this->peices){
        //Only calculate moves for our colors peices
        if(p.color != c) continue;

        if(p.type == ROOK || p.type == BISHOP || p.type == QUEEN){
            int directions[] = {-9,-8,-7,-1,7,1,9,8};
            int slide_mask = 1;
            int slide_offset = 0;

            if(p.type == BISHOP) {
                slide_mask = 2;
                slide_offset = 0;
            }
            if(p.type == ROOK) {
                slide_mask = 2;
                slide_offset = 1;
            }
            for(int i = slide_offset; i < 8; i += slide_mask){
                //How to get distance to edge? depends on direction i think, if x > 63 || x < 0
                
                // printf("<%c,%i>\n",p.type + p.color, directions[i]);

            }
                //Walk in each 4 directions (-1,1,-8,8) until the end of the board, or till we hit a peice, if its opposite colored we 
                //add that move, if same color we discard it
        }
        if(p.type == KNIGHT){
            //Off sets = 15,17,
            //Knight
        }
        if(p.type == PAWN){
            //Spooky
        }
        if(p.type == KING){
            //Casteling and stuff
        }

    }
    return moves;
}

void board::fill_peices_squares_default(){

    //Fill black peices
    this->peices[0] = peice{ROOK,   BLACK, 0};
    this->peices[1] = peice{KNIGHT, BLACK, 1};
    this->peices[2] = peice{BISHOP, BLACK, 2};
    this->peices[3] = peice{QUEEN,  BLACK, 3};
    this->peices[4] = peice{KING,   BLACK, 4};
    this->peices[5] = peice{BISHOP, BLACK, 5};
    this->peices[6] = peice{KNIGHT, BLACK, 6};
    this->peices[7] = peice{ROOK,   BLACK, 7};

    this->peices[8]  = peice{PAWN, BLACK, 8};
    this->peices[9]  = peice{PAWN, BLACK, 9};
    this->peices[10] = peice{PAWN, BLACK, 10};
    this->peices[11] = peice{PAWN, BLACK, 11};
    this->peices[12] = peice{PAWN, BLACK, 12};
    this->peices[13] = peice{PAWN, BLACK, 13};
    this->peices[14] = peice{PAWN, BLACK, 14};
    this->peices[15] = peice{PAWN, BLACK, 15};

    //Fill white peices
    this->peices[16] = peice{ROOK,   WHITE, 56};
    this->peices[17] = peice{KNIGHT, WHITE, 57};
    this->peices[18] = peice{BISHOP, WHITE, 58};
    this->peices[19] = peice{QUEEN,  WHITE, 59};
    this->peices[20] = peice{KING,   WHITE, 60};
    this->peices[21] = peice{BISHOP, WHITE, 61};
    this->peices[22] = peice{KNIGHT, WHITE, 62};
    this->peices[23] = peice{ROOK,   WHITE, 63};

    this->peices[24] = peice{PAWN, WHITE, 48};
    this->peices[25] = peice{PAWN, WHITE, 49};
    this->peices[26] = peice{PAWN, WHITE, 50};
    this->peices[27] = peice{PAWN, WHITE, 51};
    this->peices[28] = peice{PAWN, WHITE, 52};
    this->peices[29] = peice{PAWN, WHITE, 53};
    this->peices[30] = peice{PAWN, WHITE, 54};
    this->peices[31] = peice{PAWN, WHITE, 55};

    //Fill all squares
    for(char i = 0; i < this->squares.size(); i++){
        this->squares[i] = square{i, -1};
    }

    //Make squares index proper
    for(char i = 0; i < peices.size(); i++){
        squares[peices[i].square_num].peice_index = i;
    }

}
board::~board()
{

}
