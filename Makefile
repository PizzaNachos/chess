output: chess.o board.o
	g++ ./target/chess.o ./target/board.o -o ./target/chess
chess.o:
	g++ -c chess.cpp -o ./target/chess.o
board.o:
	g++ -c board.cpp -o ./target/board.o
clean:
	rm ./target/*