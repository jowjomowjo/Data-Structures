/**
   Jocelin Darma
   12/03/2018
   Version 1.0

   This is the headers for hashTable

    Assumptions:
   1. I suppressed copy because I assume that the client will not want to copy a hashTable.
   2. Suppress copy is needed because I want to eliminate deep and shallow copy altogether, so the default copy constructor
      and assignment operator provided by the compiler cannot be used.
**/

#include <iostream>
using namespace std;

#ifndef P5_HASHTABLE_H
#define P5_HASHTABLE_H

class hashTable
{
private:
    struct Node
    {
        string word;
        int frequency;
        Node* next;
    };
    int buckets;
    int numOfUniqueWords;
    int capacity;
    Node** htable;
    Node** arr;
    hashTable(const hashTable&);
    void operator=(const hashTable& rhs);
    int hash(string word);
    string convert(string word);
    void resize();

public:
    hashTable(int cap);
    ~hashTable();
    void insert(string word);
    int search(string word);
    int getNum(int index);
    void dumpToArray();
    void quickSort(int low, int high);
    void display(ofstream& outFile);
    void display25(ofstream& outFile, int num);
};

#endif //P5_HASHTABLE_H
