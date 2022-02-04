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
        b->get_moves(WHITE);
    // }
    return 0;
}
