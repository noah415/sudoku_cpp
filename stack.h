#ifndef STACK
#define STACK
#include <iostream>

using namespace std;

class Stack
{
    private:

        int* _stack[9];
        int _capacity;
        int _num_items;

    public:
        //constructor
        Stack();

        //stack methods
        void push(int* space);

        int* pop();

        bool isFull();
        bool isEmpty();

        int getNumItems();

        int* returnPointer(int pointerIndex);

};


#endif