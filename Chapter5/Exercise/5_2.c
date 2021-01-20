#include "ch.h"
#include <ctype.h>
#include <stdlib.h>
int getfloat(double *);

int main()
{
    double *pd = (double *) malloc(sizeof(double));
    if (getfloat(pd))
    {
        printf("%f\n", *pd);
        return 0;
    }
    else
    {
        return -1;
    }
    
    
}

int getfloat(double *pd)
{
    int c, sign;
    double f = 1;
    while (isspace(c = getch()))
    {
        /* code */
    }
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
    {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getch();
    }
    for ( *pd = 0; isdigit(c); c = getch())
    {
        *pd = 10 * *pd + (c - '0');
    }
    if (c == '.')
    {
        c = getch();
    }
    for (; isdigit(c); c = getch())
    {
        *pd = 10 * *pd + (c - '0');
        f = 0.1 * f;
    }
    *pd = sign * *pd * f;
    if (c != EOF)
    {
        ungetch(c);
    }
    return c;
    
    
    
    
    
    
    
}


