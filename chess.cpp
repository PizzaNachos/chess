#include "chess.h"
#include "board.h"
#include <iostream>

int main(){
    board* b = new board();
    b->print();

    // int start, end;
    // while ((std::cin >> start) && (std::cin >> end)){
        // b->make_move(start,end);
        // b->print();
    int moves_num = 0;
    std::vector<move> current_moves = b->get_moves(WHITE);
    std::cout << "#Moves: " << current_moves.size() << std::endl;
    for(move m : current_moves){
        made_move mo = b->make_move(m);
        b->print();
        b->unmake_move(mo);
    }

    return 0;
}
