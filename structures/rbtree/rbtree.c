//
// Created by AdityaAtulTewari on 12/18/17
//

#include "rbtree.h"
#include <stdlib.h>

rbNode* createRBNode(void* data)
{
  if(!data) return NULL;
  rbNode* r = (rbNode*) malloc(sizeof(rbNode));
  if(!r) return NULL;
  r->color = 'r';
  r->data = data;
  r->childs = (rbNode**) malloc(2*sizeof(rbNode));
  r->childs[0] = NULL;
  r->childs[1] = NULL;
  return r;
}

void destructRBNode(rbNode* node, void (*destruct)(void*))
{
  if(!node) return;
  for(int i = 0; i < 2; i++) if(node->childs[i]) destructRBNode(node->childs[i], destruct);
  if(destruct && node->data) destruct(node->data);
  free(node->childs);
  free(node);
  return;
}

rbTree* createRBTree(int (*compare)(void*, void*), void (*destruct)(void*))
{
  if(!compare) return NULL;
  rbTree* t = malloc(sizeof(rbTree));
  t->compare = compare;
  t->destruct = destruct;
  t->root = NULL;
  return t;
}

void destructRBTree(rbTree* tree)
{
  if(!tree) return;
  destructRBNode(tree->root, tree->destruct);
  free(tree);
}


//this function is only safe when called within the findRBNode
bool hfindRBNode(void* data, rbNode* node, int (*compare)(void*, void*))
{
  int c = compare(data, node->data);
  if(!node) return false;
  if(c == 0) return true;
  c = c > 0;
  return hfindRBNode(data, node->childs[c], compare);
}

bool findRBNode(void* data, rbTree* tree)
{
  if(!data) return false;
  if(!tree) return false;
  if(!tree->compare) return false;
  if(!tree->root) return false;
  int c = tree->compare(data, tree->root->data);
  if(c == 0) return true;
  c = c > 0;
  return hfindRBNode(data, tree->root->childs[c], tree->compare);
}

//Recursive insertion method to be called to handle the casework
rbNode* insertReRBNode(void* data, rbNode* p, rbNode* gp, rbNode* ggp);


rbNode* insertRBNode(void* data, rbTree* tree)
{
  if(!data) return NULL;
  if(!tree) return NULL;
  if(!tree->compare) return NULL;
  if(!tree->root)
  {
    tree->root = createRBNode(data);
    if(!tree->root) return NULL;
    tree->root->color = 'b';
    return tree->root;
  }
  int c = tree->compare(data, tree->root->data);
  if(c == 0)
  {
    if(data) tree->root->data = data;
    return tree->root;
  }
  else
  {
    c = c > 0;
    //If desired node is empty we know the root is black
    if(!tree->root->childs[c])
    {
      tree->root->childs[c] = createRBNode(data);
      if(tree->root->childs[c]) return tree->root->childs[c];
      return NULL;
    }
    //Handle recoloring
    if(tree->root->childs[!c] && tree->root->childs[0]->color == 'r' && tree->root->childs[1]->color == 'r')
    {
      for(int i = 0; i<2; i++) tree->root->childs[i]->color = 'b';
    }

    //Insert the node into the child
    return insertReRBNode(data, tree->root->childs[c], tree->root, NULL);
  }
}

rbNode* insertReRBNode(void* data, rbNode* p, rbNode* gp, rbNode* gpp)
{
  if(data == NULL) return NULL;

}

