/**
   Jocelin Darma
   11/02/2018
   Version 1.0

   This is the driver to test functions

    Assumptions:
   1. I put in the inputs and loops as a constants assuming that it will always be 100 inputs
      and 10 loops everytime.
**/

#include "parityBST.h"
#include <iostream>
#include <fstream>
using namespace std;

//class constants
const int INPUTS = 100;
const int LOOPS = 10;
const bool EVEN = true;
const bool ODD = false;
const string OUTPUTFILE = "P3OutI1.txt";
const string OUTPUTFILE2 = "P3OutI2.txt";

/**
 * This function seeds initial construction of a parityBST where there is
 * 100 random inputs into a tree
 * @param inputs total number of inputs
 * @param tree
 */
void seedInitialConst(int inputs, parityBST* tree)
{
    while(inputs != 0)
    {
        tree->insert((rand() % 100) + 1);
        inputs--;
    }
}

/**
 * This function dumps the contents of a tree into an output file
 * @param outFile the file to be written on
 * @param tree
 */
void outputToFile(string outFile, parityBST* tree)
{
    ofstream file;
    file.open(outFile);
    tree->inorder(file);
}

/**
 * This function inserts and removes data values from a tree 10 times (20 actions total)
 * @param loops number of loops
 * @param tree
 */
void arbritaryInsertRemove(int loops, parityBST* tree)
{
    while(loops != 0)
    {
        tree->insert((rand() % 100) + 1);
        tree->deleteNode((rand() % 100) + 1);
        loops--;
    }
}

int main()
{
    parityBST* even = new parityBST(EVEN);
    seedInitialConst(INPUTS, even);
    outputToFile(OUTPUTFILE, even);
    arbritaryInsertRemove(LOOPS,even);
    outputToFile(OUTPUTFILE2, even);
    return 0;
}
