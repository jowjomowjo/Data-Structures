/**
   CPSC 2430, P2.cpp
   Jocelin Darma
   10/16/2018
   Version 1.0

   Purpose: Driver to test the functions

   Assumptions:
   1. I put the 1025 inputs and 1023 outputs as constant as I assume
      it is not going to change throughout the program
**/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "LLQ.h"
#include "stlQ.h"
using namespace std;

//class constants
const int INPUT = 1025;
const int OUTPUT = 1023;

/**
 * This function tests the LLQ functions
 * @param testLL pass by reference to a LLQ
 */
void testLLQ(LLQ &testLL)
{
    while (testLL.getSize()!= INPUT) {
        testLL.enQ((rand() % 18) - 9);
    }
    for(int i = 0; i < OUTPUT; i++)
    {
        testLL.deQ();
    }
    cout << "Remaining values in List: " << endl;
    for(int i = 0; i < (INPUT-OUTPUT); i++)
    {
        cout << testLL.deQ() << endl;
    }
}

/**
 * This function tests the stlQ function
 * @param testQ pass by reference to a stlQ
 */
void testQ(stlQ &testQ)
{
    srand(time(NULL));
    while (testQ.getSize()!= INPUT) {
        testQ.enQ((rand() % 18) - 9);
    }
    for(int i = 0; i < OUTPUT; i++)
    {
        testQ.deQ();
    }
    cout << "Remaining values in Queue: " << endl;
    for(int i = 0; i < (INPUT-OUTPUT); i++)
    {
        cout << testQ.deQ() << endl;
    }
}

int main()
{
    auto startLL = std::chrono::high_resolution_clock::now();

    LLQ testLL1;
    testLLQ(testLL1);
    LLQ testLL2;
    testLLQ(testLL2);
    LLQ testLL3;
    testLLQ(testLL3);

    auto endLL = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_secondsLL = endLL-startLL;
    std::cout << "elapsed time: " << elapsed_secondsLL.count() << "s\n";


    auto startQ = std::chrono::high_resolution_clock::now();

    stlQ testQ1;
    testQ(testQ1);
    stlQ testQ2;
    testQ(testQ2);
    stlQ testQ3;
    testQ(testQ3);

    auto endQ = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_secondsQ = endQ-startQ;
    std::cout << "elapsed time: " << elapsed_secondsQ.count() << "s\n";

    return 0;
}
