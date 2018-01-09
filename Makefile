#change this line depending on where your compiler is
CC=g++-7
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
	echo  $$blah >> Makefile; \
	up=`echo $$REPLY| tr [a-z] [A-Z]`; \
	h="//\n//\n//\n\n#ifndef $$up"; \
	h+="_H\n#define $$up"; \
	h+="_H\n\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n\n//Code Goes Here\n\n#ifdef __cplusplus\n}\n#endif\n#endif"; \
	echo $$h >> ./structures/$$REPLY/$$REPLY.h; \
	c="//\n//\n//\n\n#include \"$$REPLY.h\"\n\n//Code Goes Here\n\n"; \
	echo $$c >> ./structures/$$REPLY/$$REPLY.c; \
	pp="//\n//\n//\n\n#include \"../catch.hpp\"\n#include \"../../structures/$$REPLY/$$REPLY.h\"\n\n//Code Goes Here\n"; \
	echo $$pp >> $$cpp; \
	cm="\n\nset($$up"; \
	cm+="_TEST_FILES\r\n\t\t\t\t./tests/main.cpp\r\n\t\t\t\t./tests/catch.hpp\r\n\t\t\t\t$$cpp\r\n\t\t\t\t./structures/$$REPLY/$$REPLY.h\r\n\t\t\t\t"; \
	cm+="./structures/$$REPLY/$$REPLY.c\r\n\t\t\t\t)\r\n\r\nadd_executable($$up"; \
	cm+=' $${'; \
	cm+="$$up"; \
	cm+="_TEST_FILES})"; \
    f="./CMakeLists.txt"; \
    echo $$cm >> $$f

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