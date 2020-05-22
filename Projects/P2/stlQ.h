/**
   CPSC 2430, stlQ.h
   Jocelin Darma
   10/16/2018
   Version 1.0

   This is the headers for stlQ, queue implementation using queue STL

   Assumptions:
   1. The flush() function is put as a private method because the client doesn't
      need to toggle around with that function
   2. I suppressed both the copy constructor and overload assignment operator because
      we don't want to copy a linked list or queue
**/

#ifndef P2_STLQ_H
#define P2_STLQ_H
#include <queue>
using namespace std;

/**
 * This is the method declarations for stlQ
 */
class stlQ
{
public:
    stlQ();
    ~stlQ();
    void enQ(int num);
    int deQ();
    bool isEmpty();
    void clear();
    int getSize();

private:
    //Suppressed
    stlQ(const stlQ &);
    void operator = (const stlQ &);

    int counter;
    void flush();
    queue<int> *myQueue;
};

#endif //P2_STLQ_H
