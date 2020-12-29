#include <stdio.h>
#define N 8

int main()
{
    int rest = N;
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            int i;
            for (i = 0; i < rest; i++)
            {
                putchar(' ');
            }
        }
        else
        {
            putchar(c);
            rest--;
            if (rest < 0 || c == '\n')
            {
                rest = N;
            }
        }
    }
    return 0;
}