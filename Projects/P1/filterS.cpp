/**
   Jocelin Darma
   10/04/2018
   version 1.0
   
   Purpose: 
    Function definitions for filterS
**/

#include "filterS.h"
#include <iostream>
using namespace std;

/**
 * Copy constructor
 * @param otherStack stack to be copied to
 */
filterS::filterS(const filterS& otherStack)
{
  maxSize = otherStack.maxSize;
  top = otherStack.top;
  stackList = new int[maxSize];
  for(int i = 0; i < top ; i++)
    {
      stackList[i] = otherStack.stackList[i];
    }
}

/**
 * Overloaded assignment operator
 * @param rhs object reference
 */
void filterS::operator=(const filterS& rhs)
{
  if(this != &rhs)
    {
      delete[] stackList;
      maxSize = rhs.maxSize;
      stackList = new int[maxSize];
      for(int i = 0; i < maxSize; i++)
        stackList[i] = rhs.stackList[i];
    }
  return;
}

// Destructor
filterS::~filterS()
{
  delete[] stackList;
}

/**
 * Checks if a stack is empty
 * @return true if empty, false otherwise
 */
bool filterS::isEmpty() const
{
  return top == 0;
}

/**
 * Checks if a stack is full
 * @return true if full, false otherwise
 */
bool filterS::isFull() const
{
  return top == maxSize;
}

/**
 * Gets the element at the top of a stack, prints out an error message if stack is empty
 * @return the element at the top of the stack
 */
int filterS::getTop() const
{
  if(isEmpty())
    {
      return -1;
    }

  return stackList[top - 1];
}

/**
 * Add elements into a stack, resize the stack if stack is full
 * @param num element to be added into the stack
 */
void filterS::push(int num)
{
  if(isFull())
    {
      resize();
    }
  if(filter(num))
    {
      stackList[top] = num;
      top++;
    }
}

/**
 * Remove an element from a stack
 */
void filterS::pop()
{
  if(isEmpty())
    {
      return -1;
    }
  top--;
}

/**
 * Filters the integer inputted by dividing it with X
 * @param num the element to be filtered
 * @return true if the number is not divisible by X (the divisior), false otherwise
 */
bool filterS::filter(int num)
{
  return num % X != 0;
}

/**
 * Doubles the size of a stack 
 */
void filterS::resize()
{
  int* temp = new int[maxSize *2];
  for(int i = 0; i < maxSize; i++)
    {
      temp[i] = stackList[i];
    }
  delete[] stackList;
  maxSize *= 2;
  stackList = temp;
}
