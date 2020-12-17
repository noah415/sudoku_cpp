#include "puzzle.h"

using namespace std;

void  Puzzle::updateCagePossibilities(int num, int cage)
{
    vector<int> placeV;
    bool addToStack;
    int row;
    int col;

    //create the random factor 
    //add each possibility to the stack in a random fasion
    vector<int> random = this->shuffleVector();


    for (int i = 0; i < 9; i++) //checks if each space in cage is possible: updates stack
    {
        
        addToStack = false;
        placeV = this->getCageRowCol(cage, i); //creates a vector returning row and col
        row = placeV[0];
        col = placeV[1];

        //assign num to correct puzzle place
        if (_puzzle[row][col] == 0)
        {
            _puzzle[row][col] = num;

            if (this->checkCol(col) && this->checkRow(row) && this->checkCage(cage))
            {
                addToStack = true;
            }

            if (addToStack)
            {
                //_possibilites[num][cage].push(&_puzzle[row][col]);
                cout << i << " added to stack" << endl;
            }

            _puzzle[row][col] = 0;
        }
    }
}