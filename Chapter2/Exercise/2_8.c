#include <stdio.h>
int rightrot(unsigned int x, int n);

int main()
{
    int x = 0b01;
    printf("%d\n", rightrot(x, 31));
    return 0;
}

int rightrot(unsigned int x, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        int bit = x & 1;
        x = x >> 1;
        bit = bit << 31;
        x = x | bit;
    }
    return x;
}