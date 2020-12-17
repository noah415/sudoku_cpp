#include "puzzle.h"
#include <iostream>

using namespace std;

int main()
{
    Puzzle puzzle;

    puzzle.updateCagePossibilities(1,0);
    puzzle.print();
    return 0;
}