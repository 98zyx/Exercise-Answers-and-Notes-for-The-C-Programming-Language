#include <stdio.h>

int bitcount(unsigned x);

int main()
{
    int x = 0b011111;
    printf("%d\n", bitcount(x));
    return 0;
}

int bitcount(unsigned x)
{
    int i = 0;
    while (x != 0)
    {
        x = x & (x - 1);
        i++;
    }
    return i;
}