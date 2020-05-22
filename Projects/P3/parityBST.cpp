/**
   Jocelin Darma
   11/02/2018
   Version 1.0

   This class represents the implementation of a parityBST
**/

#include <iostream>
#include <stack>
#include "parityBST.h"

/**
 * This is the constructor for parityBST. It constructs a parityBST that initializes the root, current
 * and previous to be a null pointer and accepts a boolean parameter to determine the state odd or even.
 * @param even true if even false otherwise
 */
parityBST::parityBST(bool even)
{
    root = 0;
    current = 0;
    prev = 0;
    state = even;
}

/**
 * This is the destructor for parityBST
 */
parityBST::~parityBST()
{
    clear(root);
    return;
}


/**
 * This function search for the node in a tree that has data value of the number passed in the parameter
 * @param num data value to be searched for
 * @return the node with data value of num
 */
bool parityBST::search(int num) {
    if (!root) return false;
    TNode *prev = 0;
    current = root;
    while (current && current->data != num) {
        prev = current;
        if (current->data > num)
            current = current->left;
        else
            current = current->right;
    }
    return current;
}

/**
 * This function inserts a node with data value num at the bottom of the tree
 * @param num data value of node to be inserted
 */
void parityBST::insert(int num) {
    TNode *temp = new TNode;
    temp->data = num;
    temp->left = temp->right = 0;

    bool done = false;
    prev = 0;
    current = root;

    if (!root)
    {
        root = temp;
        return;
    }

    while(current && !done)
    {
        prev = current;
        if(current->data > num)
        {
            current = current->left;
        }
        else if(current->data = num)
        {
            (current->count)++;
            done = true;
        }
        else
        {
            current = current->right;
        }
    }

    if(num < prev->data)
    {
        prev->left = temp;
    }
    else if(num > prev->data)
    {
        prev->right = temp;
    }
}

/**
 * This function deletes a node from the tree
 * There is 3 cases where deleting may occur: a leaf node, a node with one child
 * or a node with two children
 * @param num data value of the node to be deleted
 */
void parityBST::deleteNode(int num)
{
    if((num % 2 == 0) != state) return;
    if(!search(num)) return;

    TNode* delP = current;
    TNode* parent = prev;

    if(delP->count > 0)
    {
        (delP->count)--;
    }

    bool left = (delP == parent->left);

    //Leaf node
    if (!delP->left && !delP->right)
    {
        if (delP == root)	root = 0;
        else if (left)		parent->left = 0;
        else				parent->right = 0;
    }
    //One child
    else if (!delP->left || !delP->right )
    {
        TNode* child = (delP->left) ? delP->left :  delP->right;
        if (delP == root) 	root = child;
        else if (left)		parent->left = child;
        else				parent->right = child;
    }
    //Two children
    else
    {
        TNode*	swapP = root->left;
        while(swapP->right)
        {
            swapP = swapP->right;
        }

        if (swapP == delP)
        {
            delP->data = delP->left->data;
            delP->left = delP->left->left;
            delP = swapP->left;
        }
        else
        {
            delP->data = swapP->right->data;
            delP = swapP->right;
            swapP->right = delP->left;
        }
    }
    delete delP;
}

/**
 * This function prints out contents of a tree in preorder traversal
 * @param root root of the tree
 */
void parityBST::preorder(TNode *root)
{
    if(!root) return;
    cout << root->data << " ";
    postorder(root->left);
    postorder(root->right);
}

/**
 * This function outputs all contents of a tree in inorder traversal into an output file
 * @param file file to be outputted to
 */
void parityBST::inorder(ofstream& file)
{
    TNode* current = root;
    stack <TNode*> s;
    while (!s.empty() || current)
    {
        if (current)
        {
            s.push(current);
            current = current->left;
        }
        else
        {
            if (!s.empty())
            {
                current = s.top();
                s.pop();
                file << current->data << " " << "count: " << current->count << endl;
                current = current->right;
            }
        }
    }
}

/**
 * This function prints out the content of a tree is postorder traversal
 * @param root root of the tree
 */
void parityBST::postorder(TNode *root)
{
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

/**
 * This function clears all nodes in a tree
 * @param root root of the tree
 */
void parityBST::clear(TNode* root)
{
    if(!root) return;
    clear(root->left);
    clear(root->right);
    delete root;
    return;
}
