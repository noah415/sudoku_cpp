#include "puzzle.h"

using namespace std;

bool Puzzle::checkCage(int cage)
/* returns true if the specified input cage is
fount valid. */
{
    int** array = this->getCage(cage);
    vector<int> nums = {1,2,3,4,5,6,7,8,9};

    for (int i = 0; i < 9; i++)
    {
        int indexOf = (*array[i])-1;
        if (indexOf < 0) continue; 

        if (nums[indexOf] == -2)
        {
            return false;
        }

        nums[indexOf] = -2;
        
    }

    /* for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl; */
    delete[] array;

    return true;
}



bool Puzzle::checkCages()
/* uses checkCage() to check each cage in the puzzle.
returns false if 1 cage is found invalid. */
{
    for (int i = 0; i < 9; i++)
    {
        if (!this->checkCage(i))
        {
            return false;
        }
    }
    return true;
}


bool Puzzle::checkCol(int col)
/* uses check */
{
    int** array = this->getCol(col);
    vector<int> nums = {1,2,3,4,5,6,7,8,9};

    for (int i = 0; i < 9; i++)
    {
        int indexOf = (*array[i])-1;
        if (indexOf < 0) continue;

        if (nums[indexOf] == -2)
        {
            return false;
        }

        nums[indexOf] = -2;
    }

    /* for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;*/
    delete[] array; 

    return true;
}


bool Puzzle::checkCols()
{
    for (int i = 0; i < 9; i++)
    {
        if (!this->checkCol(i))
        {
            return false;
        }
    }
    return true;
}


bool Puzzle::checkRow(int row)
{
    int** array = this->getRow(row);
    vector<int> nums = {1,2,3,4,5,6,7,8,9};

    for (int i = 0; i < 9; i++)
    {
        int indexOf = (*array[i])-1;
        if (indexOf < 0) continue;

        if (nums[indexOf] == -2)
        {
            return false;
        }
        nums[indexOf] = -2;
    }

    delete[] array;

    return true;
}


bool Puzzle::checkRows()
{
    for (int i = 0; i < 9; i++)
    {
        if (!this->checkRow(i))
        {
            return false;
        }
    }
    return true;
}


bool Puzzle::checkPuzzle()
{
    return this->checkRows() && this->checkCols() && this->checkCages();
}










