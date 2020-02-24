#include <stdio.h>

extern int test_me();

int main()
{
   test_me(); 
   printf("%s\n","World");
}
