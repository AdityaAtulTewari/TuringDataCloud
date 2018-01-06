cmake_minimum_required(VERSION 3.8)

project(TuringDataCloud)
SET(CMAKE_C_COMPILER /usr/bin/g++)
SET(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_VERBOSE_MAKEFILE off)

set(SOURCE_FILES
				structures/rbtree/rbtree.c
				structures/rbtree/rbtree.h
				structures/infarr/infarr.c
				structures/infarr/infarr.h
				)

set(RBTREE_TEST_FILES
				./tests/main.cpp
				./tests/catch.hpp
				./tests/rbtree/rbtree_test.cpp
				./structures/rbtree/rbtree.h
				./structures/rbtree/rbtree.c

				)
set(INFARR_TEST_FILES
				./tests/main.cpp
				./tests/catch.hpp
				./tests/infarr/infarr_test.cpp
				./structures/infarr/infarr.h
				./structures/infarr/infarr.c
				)

add_executable(rbtreeTest ${RBTREE_TEST_FILES})
add_executable(infarrTest ${INFARR_TEST_FILES})
