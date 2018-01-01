//
// Created by Aditya Tewari on 1/1/18.
//
#include "../../structures/rbtree/rbtree.h"
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

int c(void* v, void* d)
{
  return *((int*) v) - *((int*) d);
}

TEST_CASE("Test Tree Constructor and Destructor", "[tree][construct]")
{
  rbTree* t = createRBTree(c, NULL);
  REQUIRE(t);
  REQUIRE(t->compare);
  REQUIRE_FALSE(t->destruct);
  int i = 3; int j = 4;
  REQUIRE(t->compare(&i, &j) == -1);
  REQUIRE_FALSE(t->root);
  destructRBTree(t);
  REQUIRE_FALSE(t);
}