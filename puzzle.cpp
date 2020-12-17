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



int** Puzzle::getCage(int cage)
/* takes the cage number and creates an array 
of pointers to the correct addresses to 
cooresponding units in cage. */
{
    if (cage < 0 || cage > 8)
    {
        throw runtime_error("Cage must be int between -1 and 9.");
    }

    //create a double pointer array
    int** cageList = new int*[9];

    int startCol = (cage%3)*3;
    int endCol = startCol + 3;
    int startRow = (cage/3)*3;
    int endRow = startRow + 3;
    int index = 0;

    //cout << startCol << " " << endCol << endl;
    //cout << startRow << " " << endRow << endl;

    for (int r = startRow; r < endRow; r++)
    {
        for (int c = startCol; c < endCol; c++)
        {
            //cout << _puzzle[r][c];
            cageList[index] = &_puzzle[r][c];
            index++; 
        }
        //cout << endl;
    }
    //cout << "\n\n";
    return cageList;
}


int** Puzzle::getCol(int col)
/* returns a pointer to a list of pointers of corresponding 
input puzzle column. */
{
    if (col < 0 || col > 8)
    {
        throw runtime_error("Col must be int between -1 and 9.");
    }

    int** colList = new int*[9];
    
    for (int r = 0; r < 9; r++)
    {
        //cout << _puzzle[r][col];
        colList[r] = &_puzzle[r][col];
    }
    //cout << endl;

    return colList;
}


int** Puzzle::getRow(int row)
/* returns a pointer to a list of pointers of corresponding
input puzzle row. */
{
    if (row < 0 || row > 8)
    {
        throw runtime_error("Row must be int between -1 and 9.");
    }

    int** rowList = new int*[9];
    
    for (int c = 0; c < 9; c++)
    {
        //cout << _puzzle[row][c];
        rowList[c] = &_puzzle[row][c];
    }
    //cout << "\n\n";

    return rowList;
}


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
    cout << endl;
    delete[] array; */

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

    /* for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl; */
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

vector<int> Puzzle::shuffleVector()
{
    srand(time(NULL));
    vector<int> vector{1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < 8; i++)
    {
        int swapIndex = i + rand() % (9-i);
        swap(vector[i], vector[swapIndex]);
    }

    return vector;
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

int Puzzle::getCageNum(int row, int col)
{
    return (col/3) + ((row/3)*3);
}

vector<int> Puzzle::getCageRowCol(int cage, int index)
{
    vector<int> vector;

    int startrow;
    int startcol;
    int row;
    int col;

    startrow = (cage/3)*3;
    startcol = (cage%3)*3;

    int addcol = index%3;
    int addrow = index/3;

    /* cout << startrow << endl;
    cout << startcol << endl;
    cout << addrow << endl;
    cout << addcol << endl; */

    row = startrow + addrow;
    col = startcol + addcol;

    vector.push_back(row);
    vector.push_back(col);

    return vector;
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