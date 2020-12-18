#include "puzzle.h"

using namespace std;

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