#include "board.h"
#include <string>
#include <memory>
#include <iostream>
#include <unordered_map>

// std::string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"
board::board() {
    this->fill_peices_squares_default();
    // this->squares_to_direction_map = new std::unordered_map(); //<square_and_direction,int>();
    // std::string section;
    // std::vector<std::string> fen_sections;
    // while (getline(fen, section, ' ')) {
    //     fen_sections.push_back(section);
    // }
    // this->peices[0] = peice{ROOK,   WHITE, 11};
    // this->peices[1] = peice{ROOK,   WHITE, 43};
    // this->peices[2] = peice{ROOK,   BLACK, 46};

    // for(char i = 0; i < this->squares.size(); i++){
    //     this->squares[i] = square{i, 33};
    // }

    // //Make squares index proper
    // for(char i = 0; i < peices.size(); i++){
    //     squares[peices[i].square_num].peice_index = i;
    // }
}
void board::print(){
    for(int i = 0; i < 64; ++i){
        if((i % 8 == 0)) std::cout << std::endl;
            
        // printf(" %i:%i ",i,this->squares[i].peice_index);
        if(i == 26){
            printf("26 ");
            continue;
        }
        if(i == 27){
            printf("27 ");
            continue;
        }
        if(this->squares[i].peice_index == 33) {
            printf(" . ");
        } else {
            peice p = this->peices[this->squares[i].peice_index];
            printf(" %c ",(p.type + p.color));
        }
    }
    std::cout << std::endl;
}
made_move board::make_move(const move m){
    made_move mov = {
        m.start,
        m.end,
        this->squares.at(m.start).peice_index,
        this->squares.at(m.end).peice_index
    };

    this->peices.at(squares.at(m.start).peice_index).square_num = m.end;
    this->squares.at(m.end).peice_index = this->squares.at(m.start).peice_index;

    this->peices.at(squares.at(m.end).peice_index).square_num = 64;
    this->squares.at(m.start).peice_index = 33;

    return mov;
}
void board::unmake_move(made_move m){
    this->peices.at(m.destroed_peice_index).square_num = m.end_square;
    this->peices.at(m.start_peice_index).square_num = m.start_square;

    this->squares.at(m.start_square).peice_index = m.start_peice_index;
    this->squares.at(m.end_square).peice_index = m.destroed_peice_index;
}
int board::squares_in_direction(int start_square, int direction){
    int square_and_direction = (start_square * 100) + direction;
    //Start squares = 0 - 63
    //Directions = -9 - 9
    // 62 * 100 = 6200 + -9 = 6111
    // 61 + 1 = 610 + 1 = 611
    int distance = 0;
    if(this->squares_to_direction_map.count(square_and_direction)){
        return this->squares_to_direction_map.at(square_and_direction);
    } 

    //Left
    if(direction == -1){
        distance = (start_square % 8);
        this->squares_to_direction_map.emplace(square_and_direction,distance);
        return distance;
    }
    //Right
    if(direction == 1){
        distance = 7 - (start_square % 8);
        this->squares_to_direction_map.emplace(square_and_direction,distance);
        return distance;
    }
    //Down
    if(direction == 8){
        distance = 7 - (start_square / 8);
        this->squares_to_direction_map.emplace(square_and_direction,distance);
        return distance;
    }
    //UP
    if(direction == -8){
        distance = (start_square / 8);
        this->squares_to_direction_map.emplace(square_and_direction,distance);
        return distance;
    }

    //Down Right
    if(direction == 9){
        int down = 7 - (start_square / 8);
        int right = 7 - (start_square % 8);
        distance = (down < right) ? down : right;
        this->squares_to_direction_map.emplace(square_and_direction,distance);
        return distance;
    }
    //Down left
    if(direction == 7){
        int down = 7 - (start_square / 8);
        int left = (start_square % 8);
        distance = (down < left) ? down : left;
        this->squares_to_direction_map.emplace(square_and_direction,distance);
        return distance;
    } 
    //Up Right
    if(direction == -7){
        int up = (start_square / 8);
        int right = 7 - (start_square % 8);
        distance = (up < right) ? up : right;
        this->squares_to_direction_map.emplace(square_and_direction,distance);
        return distance;
    } 
    //Up Left
    if(direction == -9){
        int up = (start_square / 8);
        int left = (start_square % 8);
        distance = (up < left) ? up : left;
        this->squares_to_direction_map.emplace(square_and_direction,distance);
        return distance;
    }
    return 0;
}
std::vector<move> board::get_moves(COLOR c){
    std::vector<move> moves;
    for(peice p : this->peices){
        //Only calculate moves for our colors peices
        if(p.color != c) continue;
        if(p.type == ROOK || p.type == BISHOP || p.type == QUEEN){
            // int directions[] = {-9,-8,-7,-1,7,1,9,8};
            int ydirections[] = {-1,0,1,0};
            int xdirections[] = {-8,0,8,0};

            int x_mask = 2;
            int x_index = 0;

            int y_mask = 2;
            int y_index = 0;

            if(p.type == BISHOP) {

                for(char x = p.square_num - 7; x >= 0; x -= 8){
                    if(this->squares[x].peice_index == 33){
                            moves.push_back(move{p.square_num, x});
                        } else if(this->peices[this->squares[x].peice_index].color != c){
                            moves.push_back(move{p.square_num, x});
                            break;
                        } else {break;}                    
                }

                //Down 
                for(char x = p.square_num + 9; x < 63; x += 8){
                     if(this->squares[x].peice_index == 33){
                            moves.push_back(move{p.square_num, x});
                        } else if(this->peices[this->squares[x].peice_index].color != c){
                            moves.push_back(move{p.square_num, x});
                            break;
                        } else {break;}  
                }

                //Right
                for(char x = p.square_num + 7; x < p.square_num + (8 - (p.square_num % 8) ); x++){
                     if(this->squares[x].peice_index == 33){
                            moves.push_back(move{p.square_num, x});
                        } else if(this->peices[this->squares[x].peice_index].color != c){
                            moves.push_back(move{p.square_num, x});
                            break;
                        } else {break;}  
                }

                //Left
                for(char x = p.square_num - 9; x >= p.square_num - (p.square_num % 8); --x){
                    if(this->squares[x].peice_index == 33){
                            moves.push_back(move{p.square_num, x});
                        } else if(this->peices[this->squares[x].peice_index].color != c){
                            moves.push_back(move{p.square_num, x});
                            break;
                        } else {break;}  
                }
                
            } 
            else if(p.type == ROOK) {

                //Up
                for(char x = p.square_num - 8; x >= 0; x -= 8){
                    if(this->squares[x].peice_index == 33){
                            moves.push_back(move{p.square_num, x});
                        } else if(this->peices[this->squares[x].peice_index].color != c){
                            moves.push_back(move{p.square_num, x});
                            break;
                        } else {break;}                    
                }

                //Down 
                for(char x = p.square_num + 8; x < 63; x += 8){
                     if(this->squares[x].peice_index == 33){
                            moves.push_back(move{p.square_num, x});
                        } else if(this->peices[this->squares[x].peice_index].color != c){
                            moves.push_back(move{p.square_num, x});
                            break;
                        } else {break;}  
                }

                //Right
                for(char x = p.square_num + 1; x < p.square_num + (8 - (p.square_num % 8) ); x++){
                     if(this->squares[x].peice_index == 33){
                            moves.push_back(move{p.square_num, x});
                        } else if(this->peices[this->squares[x].peice_index].color != c){
                            moves.push_back(move{p.square_num, x});
                            break;
                        } else {break;}  
                }

                //Left
                for(char x = p.square_num - 1; x >= p.square_num - (p.square_num % 8); --x){
                    if(this->squares[x].peice_index == 33){
                            moves.push_back(move{p.square_num, x});
                        } else if(this->peices[this->squares[x].peice_index].color != c){
                            moves.push_back(move{p.square_num, x});
                            break;
                        } else {break;}  
                }
            } 
            else {

            }

        }
        if(p.type == KNIGHT){
            //Off sets = 15,17,
            //Knight
        }
        if(p.type == PAWN){
            //Spooky
            if(c == BLACK){
                
            } else {

            }
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

    // this->peices[32] = NULL;

    //Fill all squares
    for(char i = 0; i < this->squares.size(); i++){
        this->squares[i] = square{i, 33};
    }

    //Make squares index proper
    for(char i = 0; i < peices.size() - 1; i++){
        squares[peices[i].square_num].peice_index = i;
    }

}
board::~board()
{

}
