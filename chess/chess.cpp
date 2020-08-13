// chess.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "stdio.h"
#include <vector>

using namespace std;


enum TEAM {
	WHITE,
	BLACK,
};
enum PEICE_TYPE {
	PAWN,
	ROOK,
	BISHOP,
	KNIGHT,
	QUEEN,
	KING
};
class Position {
public:
	int x;
	int y;

	bool is_equal(Position p) {
		if (this->x = p.x && this->y == p.y) {
			return true;
		}
		else {
			return false;
		}
	}
	void set_position(int x, int y) {
		this->x = x;
		this->y = y;
	}
	Position(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}
};

class Peice {
public:
	Peice(PEICE_TYPE type = PAWN, Position p = Position(1,1), TEAM t = WHITE) {
		this->type = type;
		this->position = p;
		this->team = t;
	}


	PEICE_TYPE type;
	TEAM team;
	Position position;
	bool has_moved;



	//virtual std::vector<Position> get_moves();
	//virtual bool destroy();
};

class Pawn : Peice {
public:
	Pawn(int x = 0, int y = 1, TEAM t = WHITE) {
		this->has_moved = false;
		this->team = t;
		this->p = Position(x, y);

	}

	bool has_moved;
	TEAM team;
	Position p;
	PEICE_TYPE type = PAWN;

	/*
	std::vector<Position> get_moves() {
	if (team == WHITE && p.y < 7) {
	if (has_moved == false) {
	std::vector<Position> val = { Position(p.x,p.y + 1), Position(p.x,p.y + 2) };
	return val;
	}
	else {
	std::vector<Position> val = { Position(p.x,p.y + 1) };
	return val;
	}
	}
	else {
	std::vector<Position> val;
	return val;
	}
	if (team == BLACK && p.y > 0) {
	if (has_moved == false) {
	std::vector<Position> val = { Position(p.x,p.y - 1), Position(p.x,p.y - 2) };
	return val;
	}
	else {
	std::vector<Position> val = { Position(p.x,p.y - 1) };
	return val;
	}
	}
	else {
	std::vector<Position> val;
	return val;
	}
	}*/
};

class Board {
public:


	char board[8][8] = {
	{'R', 'N', 'B' ,'K' ,'Q' ,'B' ,'N' ,'R'},
	{'b', 'b', 'b' ,'b' ,'b' ,'b' ,'b' ,'b'},
	{'b', 'b', 'b' ,'b' ,'b' ,'b' ,'b' ,'b'},
	{'b', 'b', 'b' ,'b' ,'b' ,'b' ,'b' ,'b'},
	{'b', 'b', 'b' ,'b' ,'b' ,'b' ,'b' ,'b'},
	{'b', 'b', 'b' ,'b' ,'b' ,'b' ,'b' ,'b'},
	{'b', 'b', 'b' ,'b' ,'b' ,'b' ,'b' ,'b'},
	{'b', 'b', 'b' ,'b' ,'b' ,'b' ,'b' ,'b'}
	};

	char get_board(int x, int y) {
		return board[x][y];
	}

	void update_board(std::vector<Peice*> peices) {
		int length = peices.size();
		for (int i = 0; i < length; i++) {
			switch ((*peices).at(i).type) {
			case PAWN:
				board[peices.at(i).position.x][peices.at(i).position.y] = 'p';
				break;
			case QUEEN:
				board[peices.at(i).position.x][peices.at(i).position.y] = 'Q';
				break;
			case KING:
				board[peices.at(i).position.x][peices.at(i).position.y] = 'K';
				break;
			case ROOK:
				board[peices.at(i).position.x][peices.at(i).position.y] = 'R';
				break;
			case KNIGHT:
				board[peices.at(i).position.x][peices.at(i).position.y] = 'N';
				break;
			case BISHOP:
				board[peices.at(i).position.x][peices.at(i).position.y] = 'B';
				break;
			default:
				board[peices.at(i).position.x][peices.at(i).position.y] = 'b';
				break;
			}
		}
	}

	void draw_board() {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				switch (this->get_board(i, j)) {
				case 'p':
					printf("p");
					break;
				case 'Q':
					printf("Q");
					break;
				case 'K':
					printf("K");
					break;
				case 'N':
					printf("N");
					break;
				case 'B':
					printf("B");
					break;
				case 'R':
					printf("R");
					break;
				case 'b':
					if (((i % 2 == 0) && (j % 2 == 0)) || ((i % 2 == 1) && (j % 2 == 1))) {
						printf("%c", 178);
					}
					else {
						printf("%c", 177);
					}
				}
			}
			printf("\n");
		}
	}
		
	};

	int main()
	{
		std::vector<Peice*> peices;
		peices.push_back(new Peice());
		Board board = Board();
		board.update_board(peices);
		board.draw_board();
	}



	// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
	// Debug program: F5 or Debug > Start Debugging menu

	// Tips for Getting Started:
	//   1. Use the Solution Explorer window to add/manage files
	//   2. Use the Team Explorer window to connect to source control
	//   3. Use the Output window to see build output and other messages
	//   4. Use the Error List window to view errors
	//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
	//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
