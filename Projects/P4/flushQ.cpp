/**
   Jocelin Darma
   11/14/2018
   Version 1.0

   This class represents the implementation of flushQ
**/

#include "flushQ.h"
#include <iostream>
using namespace std;

/**
 * This is the constructor for flushQ. It constructs a flushQ that initializes a new array with capacity cap
 * and size to be zero
 * @param cap capacity of the array
 */
flushQ::flushQ(unsigned cap)
{
    arr = new int[cap];
    size = 0;
    capacity = cap;
}

/**
 * This is the destructor for flushQ
 */
flushQ::~flushQ()
{
    delete[] arr;
}

/**
 * This is the copy constructor
 * @param other the flushQ object to be copied
 */
flushQ::flushQ(const flushQ &other)
{
    capacity = other.capacity;
    size = other.size;
    arr = new int[capacity];
    for(int i = 1; i <= size ; i++)
    {
        arr[i] = other.arr[i];
    }
}

/**
 * This is the assignment operator function
 * @param rhs the flushQ object to be copied
 */
void flushQ::operator=(const flushQ &rhs)
{
    if (this != &rhs) {
        delete[] arr;
        capacity = rhs.capacity;
        size = rhs.size;
        arr = new int[capacity];
        for (int i = 1; i <= size; i++)
            arr[i] = rhs.arr[i];
    }
    return;
}

/**
 * This function swaps int x to y and vice versa
 * @param x first int value
 * @param y second int value
 */
void flushQ::swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

/**
 * This function doubles the capacity of an array and copies everything from the initial array into
 * the "doubled" array
 */
void flushQ::resize()
{
    int* temp = new int[capacity * 2];
    for(int i = 0; i <= size; i++)
    {
        temp[i] = arr[i];
    }
    delete[] arr;
    capacity *= 2;
    arr = temp;
}

/**
 * This function checks if the array is empty
 * @return true if empty and false otherwise
 */
bool flushQ::isEmpty()
{
    return size == 0;
}

/**
 * This function checks if the number passed into the parameter is a prime number or not
 * @param num the int value to be checked
 * @return true if its a prime number and false otherwise
 */
bool flushQ::isPrime(int num)
{
    if(num < 1) return false;
    for(int i = 2; i < num; i++)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}

/**
 * This function inserts / enqueues a value into an array. The number will only be inserted into the array if and
 * only if the number is not a prime number. It will also automatically resize the capacity of the array if the
 * array is full
 * @param num the number to be inserted into the array
 */
void flushQ::enQ(int num)
{
    if(isPrime(num) == false)
    {
        size++;
        if (size == capacity) {
            resize();
        }
        arr[size] = num;
        int i = size;
        while (i > 1 && arr[i] > arr[i / 2]) {
            swap(arr[i], arr[i / 2]);
            i = i / 2;
        }
    }
}

/**
 * This function removes / dequeues values from an array
 */
void flushQ::deQ()
{
    if(isEmpty())
        return;
    swap(arr[1], arr[size]);
    size--;
    percolateDown(size,1);
}

/**
 * This function bubbles down the array
 * @param n the size of the array
 * @param i the index / position of the array
 */
void flushQ::percolateDown(int n, int i)
{
    bool done = false;
    while (!done && 2*i <= n)
    {
        int left = 2*i;
        int right = 2*i+1;
        int largest = i;
        if (arr[left] > arr[i])
            largest = left;
        if ((right) <= n && arr[right] > arr[largest])
            largest = right;
        if (largest != i)
        {
            swap(arr[i],arr[largest]);
            i = largest;
        }
        else
            done = true;
    }
    return;
}

/**
 * This function creates a max heap
 */
void flushQ::buildHeap()
{
    for(int i = size/2; i > 1; i--)
    {
        percolateDown(size,i);
    }
}

/**
 * This function arranges the values into a sorted array
 */
void flushQ::heapSort()
{
    buildHeap();
    for(int i = size; i > 1; i--)
    {
        swap(arr[1], arr[i]);
        percolateDown(i-1,1);
    }
}

/**
 * This function gets the size / number of elements in the array
 * @return size of the array
 */
int flushQ::getSize()
{
    return size;
}

/**
 * This function prints out the first 5 values of the contents of the array
 */
void flushQ::deQNDisplay()
{
    buildHeap();
    for(int i = 1; i <= 5; i++)
    {
        cout << arr[i] << " ";
        deQ();
    }
    cout << endl;
}

/**
 * This function removes all multiple of x
 * @param x an integer value
 */
void flushQ::flush(int x)
{
    int i = 1;
    while(i <= size)
    {
        if(arr[i] % x == 0)
        {
            swap(arr[i], arr[size]);
            size--;
            percolateDown(size, 1);
            i = 0;
        }
        i++;
    }
}

/**
 * This function removes all odd values in an array
 * @param x integer value passed in
 */
void flushQ::flushOdd()
{
    int i = 1;
    while(i <= size)
    {
        if(arr[i] % 2 != 0)
        {
            swap(arr[i], arr[size]);
            size--;
            percolateDown(size, 1);
            i = 0;
        }
        i++;
    }
}
