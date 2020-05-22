/**
   CPSC 2430, stlQ.cpp
   Jocelin Darma
   10/16/2018
   Version 1.0

   This class represents the implementation of queue using the queue STL
**/

#include <iostream>
#include "stlQ.h"

/**
 * This is the constructor for stlQ. It creates a new queue for integers.
 */
stlQ::stlQ()
{
    myQueue = new queue<int>;
}

/**
 * This is the destructor for stlQ
 */
stlQ::~stlQ()
{
    clear();
}

/**
 * This enQ function adds an element num into the queue.
 * The elements added will be "flushed" for every 10 inserts in order to
 * remove all negative values
 * @param num the element to be added into the queue
 */
void stlQ::enQ(int num)
{
    myQueue->push(num);
    counter++;
    if(counter % 10 == 0)
    {
        flush();
    }
}

/**
 * This deQ function remove the next element on the queue
 * and return the int value of the removed element
 * @return the int value of the removed element
 */
int stlQ::deQ()
{
    int num = myQueue->front();
    myQueue->pop();
    return num;
}

/**
 * This isEmpty function checks to see if the queue is empty
 * @return true if queue is empty and false otherwise
 */
bool stlQ::isEmpty()
{
    return myQueue->empty();
}

/**
 * This clear function pops all the elements in the queue, leaving an empty queue
 */
void stlQ::clear()
{
    while(!myQueue->empty())
    {
        myQueue->pop();
    }
}

/**
 * This getSize function returns the size of the queue
 * @return
 */
int stlQ::getSize()
{
    return myQueue->size();
}

/**
 * This flush function removes all negative values from the queue
 */
void stlQ::flush()
{
    int temp;
    int size = myQueue->size();
    for(int i = 0; i < size; i++)
    {
        if(myQueue->front() >= 0)
        {
            temp = myQueue->front();
            myQueue->pop();
            myQueue->push(temp);
        }
        else
        {
            myQueue->pop();
        }
    }
}
