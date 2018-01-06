//
// Created by AdityaAtulTewari on 1/1/18.
//

#include "../catch.hpp"
#include <string.h>
#include "../../structures/rbtree/rbtree.h"


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
}

TEST_CASE("Node Declaration", "[rbtree][node][construct][destruct]")
{
  GIVEN("A tree Node Pointer")
  {
    rbNode* n;
    WHEN("The Node is defined")
    {
      int i = 3;
      n = createRBNode(&i);
      THEN("The node is and its components were defined")
      {
        REQUIRE(n);
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
}
