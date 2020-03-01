#define TEST
#include <stdio.h>
#include <time.h>

extern int test_me();
extern int str_to_tm(char *, struct tm *);
  
/* function to convert a string to a time */

int test_str_to_tm()
{
    char * tstring = "2020-02-29 11:01:00am";
    struct tm dtime;
    int err;

    err = str_to_tm(tstring, &dtime);
    if (err)
     {
        printf("str_to_tm returned %d", err);
        return 1;
    }

    return 0;
}


int main()
{
/* Run the main function in the program being tested.
   This requires using objcopy to rename "main" to "test_me"

   test_me(); 
   printf("%s\n","World");
*/



printf("%d",test_str_to_tm());



}
