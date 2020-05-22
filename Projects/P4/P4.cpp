/**
   Jocelin Darma
   11/14/2018
   Version 1.0

   This is the driver to test the functions
**/

#include <iostream>
#include <cstdlib>
#include "flushQ.h"
using namespace std;

// class constant
const int CAPACITY = 10;
const int EXTRA_INPUT = 10;

/**
 * This function enqueues values into the flushQ object
 * @param testQ
 */
void enqNums(flushQ &testQ)
{
    int input = CAPACITY + EXTRA_INPUT;
    while(testQ.getSize() != input)
    {
        testQ.enQ((rand() % 100));
    }
}

/**
 * This function dequeues half of the flushQ object's contents
 * @param testQ
 */
void deqNums(flushQ &testQ)
{
    for(int i = 0; i <= (testQ.getSize()/2); i++)
    {
        testQ.deQ();
    }
}

int main() {
    flushQ testQ(CAPACITY);

    enqNums(testQ);
    testQ.flush(2);
    deqNums(testQ);
    enqNums(testQ);
    testQ.flushOdd();
    testQ.deQNDisplay();

    return 0;
}
