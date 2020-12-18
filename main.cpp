#include "puzzle.h"
#include <iostream>
#include <unistd.h>



using namespace std;

int main()
{
    srand(time(NULL)); //must declare the seed for random generators in the code
    Puzzle puzzle;
    /* cout << puzzle.fillCages(1,false);
    cout << puzzle.fillCages(2,false);
    puzzle.print(); */

    puzzle.fillPuzzle();

    puzzle.checkPuzzle() ? cout << "puzzle checker: is valid\n" : cout << "puzzle checker: is not valid\n";



    return 0;
}