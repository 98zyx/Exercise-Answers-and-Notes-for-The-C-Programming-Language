#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int c;
    int lim = 10;
    if (argc < 2)
        return;
    int isx = strcmp(*(argv+1), "-x") == 0 ? 1 : 0;
    printf("%d\n", isx);
    while (lim-- > 0 && (c = getchar()) != EOF)
    {
        if (isgraph(c))
        {
            printf("%c", c);
        }
        else
        {
            if (isx)
            {
                printf("%x", c);
            }
            else
            {
                printf("%o", c);
            }
        }
    }
    printf("\n");
}