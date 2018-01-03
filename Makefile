CC=g++
CFLAGS=-O3

rbtree:
	#Compile
	$(CC) -c ./structures/rbtree/rbtree.c
	#Make sure u include this on every single test using Catch
	$(CC) -c ./tests/main.c
	$(CC) -c ./tests/rbtree/rbtree_test.c
	#Link into file
	$(CC) rbtree.o main.o rbtree_test.o -o rbTreeTest.out
	#Run File
	./rbTreeTest.out

clean:
	rm -rf *.o
	rm -rf *.out
