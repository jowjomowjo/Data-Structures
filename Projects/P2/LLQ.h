/**
   Jocelin Darma
   10/16/2018
   version 1.0

   This is the headers for LLQ, the Linked List implementation of a Queue

   Assumptions:
   1. The flush() function is put as a private method because the client doesn't
      need to toggle around with that function
   2. I suppressed both the copy constructor and overload assignment operator because
      we don't want to copy a linked list or queue
**/

#ifndef P2_LLQ_H
#define P2_LLQ_H

/**
 * This is a linked list node to store a queue entry
 * it contains an integer data value and a pointer to the next Node
 */
struct Node
{
    int data;
    Node *next;
};

/**
 * This is the method declarations for LLQ
 */
class LLQ
{
public:
    LLQ();
    ~LLQ();
    void enQ(int num);
    int deQ();
    bool isEmpty();
    void clear();
    int getSize();

private:
    //Suppressed
    LLQ(const LLQ &);
    void operator = (const LLQ &);

    Node *head, *tail;
    int size, counter;
    void flush();
};

#endif //P2_LLQ_H
