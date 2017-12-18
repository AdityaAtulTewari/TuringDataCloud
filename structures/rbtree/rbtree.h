//
// Created by AdityaAtulTewari on 12/18/17.
//

//Header Guard
#ifndef RBTREE_H
#define RBTREE_H

typedef char bool;
#define true 0x1
#define false 0x0
typedef struct rbTreeNode rbNode;

struct rbTreeNode
{
  char      color;
  void*     data;
  rbNode*   left;
  rbNode*   right;
};

typedef struct rbTree
{
  rbNode*   root;
} rbTree;

//Constructs a node assigns it's children to 0 and sets the color to 'r' (red)
rbNode* createRBNode(void* data);

//Destroys a node and all of it's children
void destructRBNode(rbNode* node, void (*destruct)(void*));

//Construct an empty rbTree
rbTree* createRBTree();

//Destruct an rbTree
void destructRBTree(rbTree* tree, void (*destruct)(void*));

//Inserts a node into the red black tree returns null if succeeded, else self
rbNode* insertRBNode(rbNode* target, rbTree* tree, int (*compare)(void*, void*));

//Deletes a node from the tree, returns rbNode deleted or null if none deleted
rbNode* deleteRBNode(rbNode* target, rbTree* tree, int (*compare)(void*, void*));

//Finds a node in the tree
bool findRBNode(void* data, rbTree* tree, int (*compare)(void*, void*));



#endif


