#include <stdio.h>
int invert(int x, int p, int n);

int main()
{
    printf("%d\n", invert(0b111, 1, 1));
}

int invert(int x, int p, int n)
{
    unsigned int y = ~0;
    y = y >> (32 - n);
    y = y << p;
    return x ^ y;
}