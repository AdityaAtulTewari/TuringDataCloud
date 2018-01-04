CC=g++
CFLAGS=-O3

rbtree:
	#Compile
	$(CC) -c ./structures/rbtree/rbtree.c
	#Make sure u include this on every single test using Catch
	$(CC) -c ./tests/main.cpp
	$(CC) -c ./tests/rbtree/rbtree_test.cpp
	#Link into file
	$(CC) rbtree.o main.o rbtree_test.o -o rbTreeTest.out
	#Remove object files
	rm -rf *.o

clean:
	rm -rf *.o
	rm -rf *.out
