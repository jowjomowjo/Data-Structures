/**
   Jocelin Darma
   12/03/2018
   Version 1.0

   This class represents the implementation of hashTable
**/

#include "hashTable.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;
/**
 * This is the constructor for hashTable. It constructs a hashTable that initializes an array of Node pointers with
 * table size of num.
 * @param num the number of buckets / table size of the HashTable
 */

hashTable::hashTable(int cap)
{
    buckets = cap;
    numOfUniqueWords = 0;
    capacity = cap;
    htable = new Node*[cap];
    for(int i = 0; i < cap; i++)
    {
        htable[i] = NULL;
    }
    arr = new Node*[cap];
    for(int i = 0; i < cap; i++)
    {
        arr[i] = NULL;
    }
}

/**
 * This is the destructor for hashTable
 */
hashTable::~hashTable()
{
    for(int i = 0; i < buckets; i++)
    {
        Node* temp = htable[i];
        while(temp != NULL)
        {
            Node* prev = temp;
            temp = temp->next;
            delete prev;
        }
    }
    delete[] htable;
}

/**
 * This function inserts a word to the htable. If the word existed, it will increment the frequency of the word
 * @param word the word to be inserted
 */
void hashTable::insert(string word)
{
    if(word.length() > 4)
    {
        word = convert(word);
        int index = hash(word);
        if(htable[index] == NULL)
        {
            Node* newNode = new Node();
            newNode->word = word;
            newNode->frequency = 1;
            newNode->next = NULL;
            htable[index] = newNode;
            return;
        }
        else
        {
            Node* temp = htable[index];
            Node* prev;
            while(temp)
            {
                prev = temp;
                if(temp->word == word)
                {
                    temp->frequency++;
                    return;
                }
                else {
                    temp = temp->next;
                }
            }
            Node* newNode = new Node();
            newNode->word = word;
            newNode->frequency = 1;
            prev->next = newNode;
            return;
        }
    }
}

/**
 * This function search if a particular word exists on the htable and returns the frequency of the word
 * @param word the word to be searched
 * @return the int value of the frequency of the word
 */
int hashTable::search(string word) {
    int index = hash(word);
    Node *temp = htable[index];

    while (temp != NULL) {
        if (temp->word == word) {
            return temp->frequency;
        }
        temp = temp->next;
    }
    return -1;
}

/**
 * This function returns the index to be stored in the htable
 * @param word the word to be hashed
 * @return the index number of the word
 */
int hashTable::hash(string word)
{
    return word.length() % buckets;
}

/**
 * This function returns the number of chains in a particular index
 * @param index the index
 * @return the number of chains / links the index has
 */
int hashTable::getNum(int index)
{
    int count = 0;
    if(htable[index] == NULL)
    {
        return count;
    }
    else
    {
        count++;
        Node* ptr = htable[index];
        while(ptr->next != NULL)
        {
            count++;
            ptr = ptr->next;
        }
    }
    return count;
}

/**
 * This function dumps the content of the hash table into an array. It will automatically resize when
 * the capacity is overloaded.
 */
void hashTable::dumpToArray()
{
    for(int i = 0; i < 1000; i++)
    {
        if(htable[i] != NULL)
        {
            Node* temp = htable[i];
            while(temp)
            {
                if(numOfUniqueWords == capacity)
                    resize();
                Node* newNode = new Node();
                newNode->word = temp->word;
                newNode->frequency = temp->frequency;
                arr[numOfUniqueWords] = newNode;
                numOfUniqueWords++;
                temp = temp->next;
            }
        }
    }
}

/**
 * This function sorts an array in ascending order
 * @param low
 * @param high
 */
void hashTable::quickSort(int low, int high)
{
    int pivot, i, j;
    if(low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while(i < j)
        {
            while(arr[i]->frequency <= arr[pivot]->frequency && i <=high) i++;
            while(arr[j]->frequency > arr[pivot]->frequency && j >=low) j--;
            if(i < j) swap(arr[i], arr[j]);
        }
        swap(arr[j],arr[pivot]);
        quickSort(low, j-1);
        quickSort(j+1, high);
    }
}

/**
 * This functions doubles the capacity of an array
 */
void hashTable::resize()
{
    Node** temp = new Node*[capacity * 2];
    for(int i = 0; i <= capacity; i++)
    {
        temp[i] = arr[i];
    }
    delete[] arr;
    capacity *= 2;
    arr = temp;
}

/**
 * This functions converts the string into all lowercase letters
 * @param word the word to be converted
 * @return the word with all lowercase letters
 */
string hashTable::convert(string word)
{
    for(int i = 0; i < word.length(); i++)
    {
        word[i] = tolower(word[i]);
    }
    return word;
}

/**
 * This function displays everything on the hash table
 * @param outFile
 */
void hashTable::display(ofstream &outFile)
{
    for(int i = 0; i < buckets; i++)
    {
        if(htable[i] != NULL)
        {
            Node* temp = htable[i];
            while(temp)
            {
                outFile << temp->word << " " << temp->frequency << endl;
                temp = temp->next;
            }
        }
    }
}

/**
 * This function displays the top 25 maximum frquency used words
 * @param outFile the file to be outputted to
 * @param num number of words to be outputted
 */
void hashTable::display25(ofstream& outFile, int num)
{
    dumpToArray();
    quickSort(0, numOfUniqueWords -1);
    for(int i = numOfUniqueWords - 1; i > numOfUniqueWords - num -1; i--)
    {
        outFile << numOfUniqueWords - i << " " << arr[i]->word << " " << arr[i]->frequency << endl;
    }
}
