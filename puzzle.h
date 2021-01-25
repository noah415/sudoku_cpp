#ifndef PUZZLE
#define PUZZLE
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "stack.h"

using namespace std;

class Puzzle
{
    private:

        int fortest;
        int _puzzle[9][9];
        Stack _possibilities[9][9]; //[num][(cage#)stack]


        /* int _puzzle[9][9] = {{1,2,3,1,2,3,1,2,3}, //uncomment for test; (cage testing)
                                {4,5,6,4,5,6,4,5,6},
                                {7,8,9,7,8,9,7,8,9},
                                {1,2,3,1,2,3,1,2,3},
                                {4,5,6,4,5,6,4,5,6},
                                {7,8,9,7,8,9,7,8,9},
                                {1,2,3,1,2,3,1,2,3},
                                {4,5,6,4,5,6,4,5,6},
                                {7,8,9,7,8,9,7,8,9}}; */

    public:

        Puzzle();

        void cleanPuzzle();

        //getters
        int** getCage(int cage); //returns an array of pointers 
        int** getCol(int col);
        int** getRow(int row);

        //checkers

        //checker's pseudo code//
        /* make an array to hold pointers of appropriate places in puzzle being
                evaluated.
        create a vector that holds ints 1-9
        for every pointer in the array:
                create an int variable to hold the value of corresponding 
                        pointer in for-loop iteration
                subtract 1 from the value of the above int variable
                if the variable is less then 1 this means that the value
                        of pointer in array is a 0 so skip and continue
                use the int variable to index into the vector created
                if this value is -2, this means that a repeated value has
                        been found (return false)
                otherwise set the value of the index to -2
        return true */


        bool checkCages();
        bool checkCage(int cage);
        bool checkCols();
        bool checkCol(int col);
        bool checkRows();
        bool checkRow(int row);
        bool checkPuzzle();

        bool isFull(); //returns true if the puzzle is full

        //int* findPossibilities(int cage, int num); //creates an array of possibilities

        vector<int> shuffleVector();

        int getCageNum(int row, int col);


        /* This is my algorithm for the actual creating/solving of the puzzle.
         - there needs to be a 3d array that holds each stack(array of possibilities) for each cage for each cagenum
         - iteration by cagenum
         - start with 1 and work up to 9
         
         
         for each cagenum
         - create an array of stack classes
                - each stack class is representing the possible locations the cagenum can be put
                
         - find possibilities
         - put the pointers to the possible spots in the stack at random order
         - pop from the stack and move to next cage to repeat until cage 8 is completed
         - if stack is empty then backtrack to previous cage
         - if the first stack becomes empty then return to previous cagenum */

        void fillPuzzle(); //creates puzzle
        bool tryNum(int num); //tries to fill puzzle with cagenum
        void updateCagePossibilities(int num, int cage); //returns an array of pointers pointing to possible spots in puzzle
        void emptyCageStack(int num, int cage);
        bool fillCages(int num, bool backtracked);
        void destroyOldNum(int num, int cage);
        bool backTrackedNum(int num);
        
        vector<int> getCageRowCol(int cage, int index);


        //testing
        void print();
        void printArr(int** array);

};

#endif