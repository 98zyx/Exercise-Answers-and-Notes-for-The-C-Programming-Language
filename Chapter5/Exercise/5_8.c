#include <stdio.h>
#include <stdlib.h>
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main()
{
    int day = day_of_year(1998, 8, 15);
    printf("%d\n", day);
    int *pd = (int *) malloc(sizeof(int));
    int *pm = (int *) malloc(sizeof(int));
    month_day(1998, day, pm, pd);
    printf("%d : %d\n", *pm, *pd);
}
int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (month < 0 || month > 12)
    {  
        return -1;
    }
    if (day < 0 || day > daytab[leap][month])
    {
        return -1;
    }
    for (i = 1; i < month; i++)
    {
        day += daytab[leap][i];
    }
    return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (leap)
    {
        if (yearday < 0 || yearday > 366)
        {
            return -1;
        }
    }
    else
    {
        if (yearday < 0 || yearday > 365)
        {
            return -1;
        }
    }
    
    for (i = 1; yearday > daytab[leap][i]; i++)
    {
        yearday -= daytab[leap][i];
    }
    *pmonth = i;
    *pday = yearday;
}