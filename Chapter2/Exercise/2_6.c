#include <stdio.h>
#include <limits.h>
int setbits(int x, int p, int n, int y);

int main()
{
    int x = 0b101011;
    int p = 3;
    int n = 3;
    int y = 0b010110;
    printf("%d\n", setbits(x, p, n, y));
    return 0;
}

int setbits(int x, int p, int n, int y)
{
    unsigned int zero = 0;
    x = x & ((~zero) >> (32-p));
    y = y & ((~zero) >> (32-n));
    y = y << n;
    return x | y;
}