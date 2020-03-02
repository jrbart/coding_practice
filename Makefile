.PHONY: clean all git

all: challenge test 

objects = challenge.o test.o

challenge : challenge.o 
	gcc challenge.c -o challenge

challenge.o : challenge.c
	gcc -c challenge.c

test*.o : t/test*.c
	gcc -c t/test*.c

test : challenge.o test*.o
	objcopy --redefine-sym main=test_me challenge.o
	#gcc test.o challenge.o -o test
	gcc test_time_good.o challenge.o -o test


clean :
	- rm *.o
	- rm test
	- rm challenge

git :
	git add .
	git commit
