/**
   Jocelin Darma
   12/03/2018
   Version 1.0

   This is the driver to test the functions
**/

#include "hashTable.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

hashTable* test = new hashTable(100);

/**
 * This function removes all the special characters in the string
 * @param str the string
 * @return string without special characters
 */
string removeSpecialChar(string str)
{
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] < 'A' || str[i] > 'Z' || str[i] < 'a' || str[i] > 'z')
        {
            str.erase(i,1);
        }
        return str;
    }
}

/**
 * This function inserts all words in the text file into the hash table
 * @param inFile file read
 * @param line
 */
void processFile(ifstream& inFile, string line)
{
    while(getline(inFile, line))
    {
        stringstream Word(line);
        string word;
        while(Word >> word)
        {
            word = removeSpecialChar(word);
            test->insert(word);
        }
    }
}

/**
 * This function search for a word and return the frequency of the word
 * @param outFile output file
 * @param word
 */
void searchWord(ofstream& outFile, string word)
{
    outFile << word << ": " << test->search(word) << endl;
}

int main() {
    ifstream inFile;
    ofstream outFile;
    string line;
    inFile.open("MiddleMarch.txt");
    outFile.open("P5Output.txt");
    processFile(inFile, line);
    test->display(outFile);
    outFile << endl;
    test->display25(outFile, 25);
    outFile << endl;
    searchWord(outFile, "medicine");
    searchWord(outFile, "poor");
    searchWord(outFile, "debt");
    searchWord(outFile, "marriage");
    searchWord(outFile, "bliss");

    return 0;
}
