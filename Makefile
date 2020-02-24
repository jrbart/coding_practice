objects = challenge.o test.o

challenge : challenge.o 
	gcc challenge.c -o challenge

challenge.o : challenge.c
	gcc -c challenge.c

test.o :
	gcc -c t/test.c

test : challenge.o test.o
	objcopy --redefine-sym main=test_me challenge.o
	gcc test.o challenge.o -o test

clean :
	- rm *.o
	- rm test
	- rm challenge
