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


TEST_CASE("Tree Declaration", "[tree][construct][destruct]")
{
  WHEN("A Tree was Defined")
  {
    rbTree* t = createRBTree(c, NULL);
    THEN("The the tree is checked")
    {
      REQUIRE(t);
      REQUIRE(t->compare);
      REQUIRE_FALSE(t->destruct);
      REQUIRE_FALSE(t->root);
    }
    AND_THEN("The function within is checked")
    {
      int i = 3; int j = 4;
      REQUIRE(t->compare(&i, &j) == -1);
    }
    AND_THEN("Destructed")
    {
      destructRBTree(t);
    }
  }
}

TEST_CASE("Node Decleration", "[node][construct][destruct]")
{
  GIVEN("A Node was Defined")
  {
    WHEN("The Node Exists")
    {

    }
  }
}
