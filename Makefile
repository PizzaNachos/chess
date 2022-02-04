output: chess.o board.o
	g++ --std=c++17 ./target/chess.o ./target/board.o -o ./target/chess
chess.o:
	g++ --std=c++17 -c chess.cpp -o ./target/chess.o
board.o:
	g++ --std=c++17 -c board.cpp -o ./target/board.o
clean:
	rm ./target/*

release: 
	g++ -O3 --std=c++17 chess.cpp board.cpp -o ./target/chess_release