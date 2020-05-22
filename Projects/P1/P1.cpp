/**
   Jocelin Darma
   10/04/2018
   version 1.0

   Purpose: 
    Testing driver
**/

#include <iostream>
#include <fstream>
#include "filterS.cpp"
using namespace std;

/**
 * Prints out contents of a stack
 * @param stack the stack who's content will be printed out
 */
void printStack(filterS stack)
{
  cout << "Stack contents: " << endl;
  while(!stack.isEmpty())
    {
      cout << stack.getTop() << " ";
      stack.pop();
    }
  cout << "\n";
}

/**
 * Main operation of the program
 * Reads in a text file containing random numbers, inputs filtered
 * numbers into a stack, prints out the contents of each stack
 */
int main()
{
  const string FILENAME = "P1Input.txt";

  filterS firstStack(2,50); //filterS initiliazed with X of 2 and maxSize of 50
  filterS secondStack(3); //filterS initiliazed with X of 3
  filterS thirdStack(5,8); //filterS initialized with X of 5 and maxSize of 8
  filterS fourthStack(10); //filterS initialized with X of 10

  // Reads in integer data from P1Input.txt file
  ifstream myfile;
  myfile.open(FILENAME.c_str());
  if(!myfile)
    {
      cout << "File does not exist!" << endl;
      return 1;
    }
  else
    {
      int input;
      //Stores all filtered integers into the filterS objects
      while(myfile >> input)
        {
          firstStack.push(input);
          secondStack.push(input);
          thirdStack.push(input);
          fourthStack.push(input);
        }
      myfile.close();
    }

  //Dumps filterS object contents to Console
  printStack(firstStack);
  printStack(secondStack);
  printStack(thirdStack);
  printStack(fourthStack);

  return 0;
}
