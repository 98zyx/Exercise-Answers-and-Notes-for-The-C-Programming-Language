#include <stdio.h>

int main()
{
    int c = 0;
    int flag = 0;
    while ((c = getchar()) != EOF)
    {
        if (flag == 0)
        {
            if (c == ' ')
            {
                flag = 1;
            }
            putchar(c);
        }
        else
        {
            if (c != ' ')
            {
                flag = 0;
                putchar(c);
            }
        }
    }
    return 0;
}