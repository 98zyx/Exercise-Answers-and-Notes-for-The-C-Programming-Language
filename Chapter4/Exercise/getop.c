#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
    {
        /* code */
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
    {
        return c;
    }
    i = 0;
    char c2;
    if (c == '-')
    {
        c2 = getch();
        if (isdigit(c2))
        {
            s[i] = '-';
            c = c2;
            ungetch(c2);
        }
        else
        {
            ungetch(c2);
            return c;
        }
    }
    
    if (isdigit(c))
    {
        while (isdigit(s[++i] = c = getch()))
        {
            /* code */
        }
    }
    if (c == '.')
    {
        while (isdigit(s[++i] = c = getch()))
        {
            /* code */
        }
    }
    s[i] = '\0';
    if (c != EOF)
    {
        ungetch(c);
    }
    return NUMBER;
}