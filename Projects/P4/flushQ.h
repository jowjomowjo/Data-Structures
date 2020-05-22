/**
   Jocelin Darma
   11/14/2018
   Version 1.0

   This is the headers for flushQ

    Assumptions:
   1. I did not suppress copy because we will need to copy the array when resizing
   2. I made the swap, resize, percolateDown, buildHeap and heapSort functions to be private
      with the assumption that we would want to do all that internally; client doesnt need those functions
   3. There is no isFull() function because capacity will automatically resize when array is full
**/

#ifndef P4_FLUSHQ_H
#define P4_FLUSHQ_H


/**
 * This is the method declaration for flushQ class
 */
class flushQ
{
public:
    flushQ(unsigned cap);
    ~flushQ();
    flushQ(const flushQ&);
    void operator=(const flushQ&);
    void enQ(int num);
    void deQ();
    bool isEmpty();
    bool isPrime(int num);
    int getSize();
    void deQNDisplay();
    void flush(int x);
    void flushOdd();

private:
    int *arr;
    int size;
    int capacity;
    void swap(int &x, int &y);
    void resize();
    void percolateDown(int n, int i);
    void buildHeap();
    void heapSort();
};

#endif //P4_FLUSHQ_H
