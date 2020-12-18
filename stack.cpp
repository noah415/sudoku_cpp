#include "stack.h"

using namespace std;

Stack::Stack()
{
    _capacity = 9;
    _num_items = 0;
}

bool Stack::isFull()
{
    return _num_items == _capacity;
}

bool Stack::isEmpty()
{
    return _num_items == 0;
}

void Stack::push(int* space)
{
    if (!this->isFull())
    {
        _stack[_num_items] = space;
        _num_items++;
    }
    else
    {
        throw runtime_error("Stack is full. Pop an item before trying to push.");
    }
}   

int* Stack::pop()
{
    if (!this->isEmpty())
    {
        _num_items--;
        return _stack[_num_items];
    }
    else
    {
        throw runtime_error("Stack is empty. Push an item before trying to pop.");
    }
    
}

int Stack::getNumItems()
{
    return _num_items;
}


int* Stack::returnPointer(int pointerIndex)
{
    return _stack[pointerIndex];
}