#include <stdio.h>
int lower(int c);

int main()
{
    char c = 'C';
    printf("%c\n", lower(c));
    return 0;
}

int lower(int c)
{
    return c >= 'A' && c <= 'C' ? c - 'A' + 'a' : c;
}