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

        Stack();

        void push(int* space);

        int* pop();

        bool isFull();
        bool isEmpty();

};


#endif