CC=g++
CFLAGS=-O3

rbtree:
	$(CC) -c ./structures/rbtree/rbtree.c
	$(CC) -c ./tests/rbtree/rbtree_test-main.c
	$(CC) -c ./tests/rbtree/rbtree_test.c
	$(CC) rbtree.o rbtree_test-main.o rbtree_test.o -o rbTreeTest.out
	./rbTreeTest.out

clean:
	rm -rf *.o
	rm -rf *.out
