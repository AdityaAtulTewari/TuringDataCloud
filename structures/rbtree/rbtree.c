//
// Created by AdityaAtulTewari on 12/18/17
//

#include "rbtree.h"
#include <stdlib.h>

rbNode* createRBNode(void* data)
{
  rbNode* r = (rbNode*) malloc(sizeof(rbNode));
  r->color = 'r';
  r->data = data;
  r->left = NULL;
  r->right = NULL;
  return r;
}

void destructRBNode(rbNode* node, void (*destruct)(void*))
{
  if(node == NULL) return;
  if(node->left != NULL) destructRBNode(node->left, destruct);
  if(node->right != NULL) destructRBNode(node->right, destruct);
  if(destruct != NULL && node->data != NULL) destruct(node->data);
  free(node);
  return;
}

rbTree* createRBTree()
{
  rbTree* t = malloc(sizeof(rbTree));
  t->root = NULL;
  return t;
}

void destructRBTree(rbTree* tree, void (*destruct)(void *))
{
  destructRBNode(tree->root, destruct);
  free(tree);
}

bool findRBNode(void* data, rbTree* tree, int (*compare)(void*, void*))
{
  if(data == NULL) return false;
  if(compare == NULL) return false;
  if(tree == NULL) return false;
  if(tree->root == NULL) return false;
  int c = compare(data, tree->root->data);
  if(c == 0) return true;
  else if(c < 0) return hfindRBNode(data, tree->left, compare);
  else return hfindRBNode(data, tree->right, compare);
}

//this function is only safe when called within the findRBNode
bool hfindRBNode(void* data, rbNode* node, int (*compare)(void*, void*))
{
  if(node == NULL) return false;
  if(c == 0) return true;
  else if(c < 0) return hfindRBNode(data, tree->left, compare);
  else return hfindRBNode(data, tree->right, compare);
}
