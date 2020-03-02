#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define __USE_XOPEN
#include <time.h>

/* struct tm {
   int tm_sec;         // seconds,  range 0 to 59          
   int tm_min;         // minutes, range 0 to 59           
   int tm_hour;        // hours, range 0 to 23             
   int tm_mday;        // day of the month, range 1 to 31  
   int tm_mon;         // month, range 0 to 11             
   int tm_year;        // The number of years since 1900   
   int tm_wday;        // day of the week, range 0 to 6    
   int tm_yday;        // day in the year, range 0 to 365  
   int tm_isdst;       // daylight saving time             
};
*/

char * str_to_tm(char * str_p, struct tm * tm_p)
{
    char * pos_p;
    char * res;

    /* Clear the time struct */
    memset(tm_p, 0, sizeof(struct tm));

    /* Read date-time if it is in ISO format */
    res = strptime(str_p, "%t%F%t%R%t", tm_p);

    if (!res) {
        /* If returned non-null then.. */
        /* Read time in 12 hour format */
        res = strptime(str_p, "%t%R%t%p%t", tm_p);
    }

    /* should return null if all the string was read */
    return res;
}

int main()
{
    printf("%s\n","Hello");
    return 0;
}
