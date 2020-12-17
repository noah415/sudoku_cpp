//#include "puzzle.h"
#include <iostream>

using namespace std;

int main()
{
    int test[3] = {1,2,3};
    int * test1[3];

    test1[0] = &test[0];

    (*test1[0])++;

    cout << test[0] << "\t"  << *test1[0] << endl;
    return 0;
}