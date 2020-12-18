#include "puzzle.h"

using namespace std;




vector<int> Puzzle::shuffleVector()
{
    vector<int> vector{0,1,2,3,4,5,6,7,8};
    for (int i = 0; i < 8; i++)
    {
        int swapIndex = i + rand() % (9-i);
        swap(vector[i], vector[swapIndex]);
    }

    return vector;
}


void Puzzle::emptyCageStack(int num, int cage)
{
    int oldStackNum = _possibilities[num-1][cage].getNumItems();
    //cout << oldStackNum << endl;

    for (int n = 0; n < oldStackNum; n++)
    {
        _possibilities[num-1][cage].pop();
        //cout << n << endl;
    }
}



void  Puzzle::updateCagePossibilities(int num, int cage)
/* THIS METHOD DOES NOT ALTER THE PUZZLE. takes input: (int) num 
and (int) cage. num is the number the program is attempting to add
to the puzzle. the cage is the number of the cage that is being
evaluataed. this method is used to delete the old stack
and creates a new one in place of the old. this stack is created in 
random order. finds the possible valid places for the num to be placed
and adds that place to the stack. nothing is returned. only the
_possibilities array is changed.*/
{
    vector<int> placeV;
    bool addToStack;
    int row;
    int col;
    int randIndex;

    int count = 0; //for testing

    //create the random factor 
    //add each possibility to the stack in a random fasion
    vector<int> random = this->shuffleVector();

    this->emptyCageStack(num, cage); //empties stack for the re-stack in following lines
    for (int i = 0; i < 9; i++) //checks if each space in cage is possible: updates stack
    {
        randIndex = random[i]; //picks random index inside this cage
        addToStack = false;
        placeV = this->getCageRowCol(cage, randIndex); //creates a vector returning row and col (random in cage)
        row = placeV[0];
        col = placeV[1];

        //assign num to correct puzzle place
        if (_puzzle[row][col] == 0)
        {
            _puzzle[row][col] = num;

            if (this->checkCol(col) && this->checkRow(row) && this->checkCage(cage))
            {
                addToStack = true;
                count++; //for testing
            }

            if (addToStack)
            {
                _possibilities[num-1][cage].push(&_puzzle[row][col]);
                //cout << i << " added to stack" << endl;
            }

            _puzzle[row][col] = 0;
        }
    }

    /* for (int i = 0; i < count; i++) //manipulates real puzzle and demonstrates how the possibilities
                                //function works. pops all items in stack so don't leave running!!!
    {                           
        *(_possibilities[num][cage].pop()) = i+1;
    } */
} 

void Puzzle::destroyOldNum(int num, int cage) //might not be needed
{
    int** cageList = this->getCage(cage);

    for (int i = 0; i < 9; i++)
    {
        if (*(cageList[i]) == num)
        {
            vector<int> placeV = this->getCageRowCol(cage, i);
            int row = placeV[0];
            int col = placeV[1];
            _puzzle[row][col] = 0;
            break;
        }
    }
}


bool Puzzle::fillCages(int num, bool backtracked)
{
    int cage = 0;
    int count = 0;

    if (backtracked)
    {
        cage = 8;
        count = 9;
    }
    

    bool isEmpty = false;
    vector<int> recordedVectorL; //this keeps track incase there is a backtrack, in order to delete all leftover 
                                 //implement to create better efficiency

    //if cage is not empty (fill puzzle has backtracked to previous num)
        //count--; **THIS MAY BE OPTIONAL DON'T KNOW YET**

    while (cage < 9)
    {
        if (count == cage)
        {
            //create new possibilities stack for this cage
            this->updateCagePossibilities(num, cage);
        }

        else
        {
            this->destroyOldNum(num, cage); //find previously placed num in current cage and set back to 0
            cout << " deleted" << endl;
        }
        

        isEmpty = _possibilities[num-1][cage].isEmpty(); //calls isEmpty() on stack

        if (isEmpty && cage == 0)//if stack is empty and cage is 0
        {
            //return false
            return false;
        }
            

        else if (isEmpty)//else if stack is empty
        {
            //backtrack a cage 
            cage--;
            cout << "backtracked";
        }
            

        else//else
        {
            *(_possibilities[num-1][cage].pop()) = num;//assign num to popped value in stack
            cage++;//increment cage
            count = cage;//set count equal to cage
        }
            
    }

    return true;
}





void Puzzle::fillPuzzle()
{
    int num = 1;
    bool backtracked = false;
    bool filledCage;

    while (num < 10)
    {
        filledCage = this->fillCages(num, backtracked);

        if (filledCage)
        {
            cout << "true" << endl;
            backtracked = false;
            num++;
        }
        else
        {
            this->print();
            cout << "false" << num << endl;
            backtracked = true;
            num--;
        }
    }
    this->print();
    cout << "Puzzle created!" << endl;
}