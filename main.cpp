#include "puzzle.h"
#include <iostream>
#include <unistd.h>



using namespace std;

int main()
{
    srand(time(NULL)); //must declare the seed for random generators in the code
    Puzzle puzzle;

    puzzle.fillPuzzle();

    puzzle.checkPuzzle() ? cout << "puzzle checker: is valid\n" : cout << "puzzle checker: is not valid\n";



    return 0;
}