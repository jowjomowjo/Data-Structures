/**
   CPSC 2430, LLQ.cpp
   Jocelin Darma
   10/16/2018
   Version 1.0

   This class represents the Linked List implementation of queue
**/

#include <iostream>
#include "LLQ.h"
using namespace std;

/**
 * This is the constructor for LLQ. It constructs a LLQ that initializes the
 * head and null as a null pointer and let the size and counter be null.
 * The head stores to the first node of a Linked List and the tail
 * stores the last node of a Linked List
 */
LLQ::LLQ()
{
    head = tail = nullptr;
    size = 0;
    counter = 0;
}

/**
 * This is the destructor for LLQ
 */
LLQ::~LLQ()
{
    clear();
}

/**
 * This enQ function creates a new Node with data value num and inserts the
 * Node to the end of the Linked List. The elements added will be "flushed"
 * to remove all negative values every 10 insertion
 * @param num the data value of the Node to be added
 */
void LLQ::enQ(int num)
{
    Node *temp = new Node;
    temp->data = num;
    temp->next = nullptr;
    if (head == nullptr && tail == nullptr)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = tail->next;
    }
    tail->next = 0;
    size++;
    counter++;

    if(counter % 10 == 0)
    {
        flush();
    }
}

/**
 * This deQ function removes a Node from the head (front) of a Linked List
 * and returns the integer data value of the removed Node
 * @return the int data value of the removed Node
 */
int LLQ::deQ()
{
    if(isEmpty())
    {
        return 0;
    }
    Node *temp = head;
    head = head->next;
    int value = temp->data;
    delete temp;
    size--;
    return value;
}

/**
 * The isEmpty function checks to see if a Linked List is empty
 * @return true if the linked list is empty and false otherwise
 */
bool LLQ::isEmpty()
{
    return (head == nullptr && tail == nullptr);
}

/**
 * This clear function clears a Linked List and initializes the head and
 * tail as a null pointer
 */
void LLQ::clear()
{
    head = tail = nullptr;
}

/**
 * This getSize function returns the size of a Linked List
 * @return size of the linked list
 */
int LLQ::getSize()
{
    return size;
}

/**
 * This flush method removes all elements containing negative values in
 * the Linked List by traversing the elements from the head to the tail
 */
void LLQ::flush()
{
    tail = head;
    Node *previous = nullptr;
    Node *temp = nullptr;

    while(tail && tail->data < 0)
    {
        temp = head;
        head = head->next;
        tail = head;
        delete temp;
        size--;
    }
    while(tail->next)
    {
        previous = tail;
        tail = tail->next;
        if(tail->data <0) {
            previous->next = tail->next;
            temp = tail;
            tail = previous;
            delete temp;
            size--;
        }
    }
}
