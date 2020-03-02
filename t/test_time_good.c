#define TEST
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

extern int test_me();
extern char * str_to_tm(char *, struct tm *);

/* print time from tm struct */
int print_tm(struct tm * dt){
    char buf[255];

    strftime(buf, sizeof(buf), "%d %b %Y %H:%M", dt);
    printf("%s\n",buf);
}
  
/* function to convert a string to a time */

int test_str_to_tm1()
{
    char * tstring = "2020-02-29 11:01";
    struct tm dtime;
    char * err;
    
    err = str_to_tm(tstring, &dtime);
    
    print_tm(&dtime);
    printf("err %s\n",err);
    return 0;
}

int test_str_to_tm2()
{
    char * tstring = "11:01 pm";
    struct tm dtime;
    char * err;
    
    err = str_to_tm(tstring, &dtime);
    
    print_tm(&dtime);
    printf("err %s\n",err);
    return 0;
}

/* This requires using objcopy to rename "main" to "test_me" */
int main()
{
printf("%d\n",test_str_to_tm1());
printf("%d\n",test_str_to_tm2());

return 0;
}
