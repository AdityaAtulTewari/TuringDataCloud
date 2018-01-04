CC=g++
CFLAGS=-O3
new:
	@while [ -z "$$REPLY" ]; do \
		read -r -p "Enter Data Structure name or hit Ctrl+C to interrupt: " ; \
  done ; \
	if [ -a ./structures/$$REPLY/$$REPLY.c ] ; \
	then \
     echo This Structure already exists; \
		 exit 1; \
	fi; \
	mkdir ./structures/$$REPLY ./tests/$$REPLY; \
	touch ./structures/$$REPLY/$$REPLY.c ./structures/$$REPLY/$$REPLY.h ; \
	cpp=./tests/$$REPLY/$$REPLY; \
	cpp+=_test.cpp; \
	touch $$cpp; \
	blah="\n$$REPLY"; \
	blah+=':\n\t$$(CC) -c ./'; \
	blah+="structures/$$REPLY/$$REPLY.c"; \
	blah+='\n\t$$(CC) -c ./tests/main.cpp\n\t$$(CC) -c ./'; \
	blah+="./tests/$$REPLY/$$REPLY_test.cpp\n\t"; \
	blah+='$$(CC) '; \
	o=$$REPLY; \
	o+=_test.o; \
	blah+="$$REPLY.o main.o $$o -o $$REPLY"; \
	blah+="Test.out"; \
	blah+="\n\trm -rf *.o"; \
	echo  $$blah >> Makefile

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

