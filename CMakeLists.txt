cmake_minimum_required(VERSION 3.8)

project(TuringDataCloud)

#Include the proper C++ compilers in the bottom two spots
SET(CMAKE_C_COMPILER g++-7)
SET(CMAKE_CXX_COMPILER g++-7)
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

set(LINL_TEST_FILES
				./tests/main.cpp
				./tests/catch.hpp
				./tests/linl/linl_test.cpp
				./structures/linl/linl.h
				./structures/linl/linl.c
				)

add_executable(linlTest ${LINL_TEST_FILES})