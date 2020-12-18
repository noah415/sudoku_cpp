#include "puzzle.h"

using namespace std;

Puzzle::Puzzle()
/* constructor for the puzzle class. creates an 
empty puzzle (filled with 0's) */
{
    fortest = 0;
    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            _puzzle[r][c] = 0;
        }
    }  

    //_possibilites[#][#] = #cagestack#;

}

void Puzzle::cleanPuzzle()
{
    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            _puzzle[r][c] = 0;
        }
    }
}



bool Puzzle::isFull()
{
    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            if (_puzzle[r][c] == 0) return false;
        }
    }

    return true;
}





//---------------------Testing----------------------------



void Puzzle::print()
{
    string boarder = "+-------+-------+-------+";
    for (int r = 0; r < 9; r++)
    {
        if (r%3 == 0)
        {
            cout << boarder << endl;
        }
        
        for (int c = 0; c < 9; c++)
        {
            if (c%3 == 0)
            {
                cout << "| ";
            }
            cout << _puzzle[r][c] << " ";
        }
        cout << "|" << endl;
    } 
    cout << boarder << endl << endl;
}

void Puzzle::printArr(int** array)
{
    for (int i = 0; i < 9; i ++)
    {
        cout << *(array[i]);
    }
    cout << "\n\n";
}