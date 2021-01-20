#include <stdio.h>
#define isupper1(A) ((A >= 'A' && A <= 'Z') ? (1) : (-1))

int isupper2(unsigned c)
{
    return (c >= 'A' && c <= 'Z') ? 1 : -1;
}

int main()
{
    char c = 'A';
    char d = '1';
    printf("%d\n", isupper1(c));

    printf("%d\n", isupper2(d));
}