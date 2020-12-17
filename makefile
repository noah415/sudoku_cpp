main: main.o puzzle.o stack.o fillPuzzleHelpers.o
	g++ main.o puzzle.o stack.o fillPuzzleHelpers.o -o main

main.o: main.cpp
	g++ -c main.cpp -std=c++11

puzzle.o: puzzle.cpp
	g++ -c puzzle.cpp -std=c++11

stack.o: stack.cpp
	g++ -c stack.cpp -std=c++11

fillPuzzleHelpers.o: fillPuzzleHelpers.cpp
	g++ -c fillPuzzleHelpers.cpp -std=c++11

clean:
	rm *.o main