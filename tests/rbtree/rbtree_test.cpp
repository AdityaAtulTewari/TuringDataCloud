//
// Created by AdityaAtulTewari on 1/1/18.
//

#include "../catch.hpp"
#include "../../structures/rbtree/rbtree.h"

//additional libraries

int c(void* v, void* d)
{
  return *((int*) v) - *((int*) d);
}


TEST_CASE("Tree Declaration", "[rbtree][tree][construct][destruct]")
{
  GIVEN("A Tree is simply defined.")
  {
    rbTree* t;
    t = createRBTree(c, NULL);
    WHEN("The tree exists.")
    {
      REQUIRE(t);
      THEN("The trees components are properly defined.")
      {
        REQUIRE(t->compare);
        REQUIRE_FALSE(t->destruct);
        REQUIRE_FALSE(t->root);
      }
      AND_THEN("The comparator function within works and exists.")
      {
        int i = 3;
        int j = 4;
        REQUIRE(t->compare(&i, &j) == -1);
      }
      AND_THEN("The tree is destructed.")
      {
        destructRBTree(t);
      }
    }
  }
  GIVEN("A NULL comparator into tree declaration.")
  {
    rbTree* t;
    t = createRBTree(NULL, NULL);
    WHEN("The tree is checked.")
    {
      THEN("The tree pointer has a NULL value.")
      {
        REQUIRE_FALSE(t);
      }
      AND_THEN("Try and destruct the point.")
      {
        destructRBTree(t);
      }
    }
  }
}

TEST_CASE("Node Declaration", "[rbtree][node][construct][destruct]")
{
  GIVEN("A simply defined tree Node Pointer.")
  {
    rbNode* n;
    int i = 3;
    n = createRBNode(&i);
    WHEN("The the node exists.")
    {
      REQUIRE(n);
      THEN("The node's components are checked")
      {
        REQUIRE(n->data);
        REQUIRE_FALSE(n->childs);
        REQUIRE(n->color == 'r');
        REQUIRE(*((int*) n->data) == 3);
      }
      AND_THEN("The node is destructed")
      {
        destructRBNode(n, NULL);
      }
    }
  }
  GIVEN("A NULL pointer for data")
  {
    rbNode* n = createRBNode(NULL);
    WHEN("The node is checked.")
    {
      THEN("The node pointer has a NULL value.")
      {
        REQUIRE_FALSE(n);
      }
      AND_THEN("The node is destructed.")
      {
        destructRBNode(n, NULL);
        free(n);
      }
    }
  }

}
