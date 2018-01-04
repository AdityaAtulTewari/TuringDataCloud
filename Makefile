CC=g++
CFLAGS=-O3
new:
	@while [ -z "$$REPLY" ]; do \
		read -r -p "Type anything but Y or y to exit. [y/N]: " ; \
  done ; \
	mkdir ./structures/$$REPLY ./tests/$$REPLY; \
	touch ./structures/$$REPLY/$$REPLY.c ./structures/$$REPLY/$$REPLY.h ; \
	cpp=./tests/$$REPLY/$$REPLY; \
	cpp+=_test.cpp; \
	touch $$cpp; \
	blah="\n$$REPLY"; \
	blah+=':\n\t$(CC) -c ./'; \
	blah+="structures/$$REPLY/$$REPLY.c"; \
	blah+='\n\t$(CC) -c ./tests/main.cpp\n\t$(CC) -c ./'; \
	blah+="./tests/$$REPLY/$$REPLY_test.cpp\n\t"; \
	blah+='$(CC)'; \
	blah+="$$REPLY.o main.o $$REPLY_test.o -o $$REPLY"; \
	blah+="Test.out"; \
	blah+="\n\trm -rf *.o"; \
	echo $$blah >> Makefile

clean:
	rm -rf *.o
	rm -rf *.out

#Structures
rbtree:
	#Compile
	$(CC) -c ./structures/rbtree/rbtree.c
	#Make sure u include this on every single test using Catch
	$(CC) -c ./tests/main.cpp
	$(CC) -c ./tests/rbtree/rbtree_test.cpp
	#Link into file
	$(CC) rbtree.o main.o rbtree_test.o -o rbtreeTest.out
	#Remove object files
	rm -rf *.o

linl:
	#Compile
	$(CC) -c ./structures/linl/linl.c
	#Make sure u include this on every single test using Catch
	$(CC) -c ./tests/main.cpp
	$(CC) -c ./tests/linl/linl_test.cpp
	#Link into file
	$(CC) linl.o main.o linl_test.o -o linlTest.out
	#Remove object files
	rm -rf *.o
