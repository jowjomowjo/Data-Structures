/**
 * Jocelin Darma
 * 11/02/2018
 * Version 1.0
 *
 * This is the headers for parityBST
 *
 * Assumptions:
 * 1. Assume that client will not copy a binary tree, therefore we suppress copy to prevent
 *    deep copying
 * 2. The constructor state will be even (true) or odd (false)
 */

#ifndef P3_PARITYBST_H
#define P3_PARITYBST_H
#include <fstream>
using namespace std;

/**
 * This is the method declaration for parityBST class
 */
class parityBST
{
private:
/**
 * Tree Node that includes a data value, left and right pointers
 */
    struct TNode{
        int data;
        int count;
        TNode *left, *right;
    };

    TNode *root, *current, *prev;
    bool state;
    parityBST(const parityBST&);
    void operator = (const parityBST&);

public:
    parityBST(bool state);
    ~parityBST();
    bool search(int num);
    void insert(int num);
    void deleteNode(int num);
    void preorder(TNode* root);
    void inorder(ofstream& file);
    void postorder(TNode* root);
    void clear(TNode* root);
};

#endif //P3_PARITYBST_H
