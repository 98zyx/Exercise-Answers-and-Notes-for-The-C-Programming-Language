#include <stdio.h>
#define lim 1000
int main()
{
    int c, i, j;
    char s[lim];
    for ( j = 0; j < lim; j++)
    {
        s[j] = 0;
    }
    
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            break;
        }
        if (i >= lim -1)
        {
            break;
        }
        s[i++] = c;
    }
    return 0;
}