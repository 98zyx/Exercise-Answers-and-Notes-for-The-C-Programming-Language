#include <stdio.h>
#include <string.h>
#include <limits.h>
#define LIMIT 1000
void itoa(int n, char s[])
{
    int i, sign;
    i = sign = 0;
    if (n < 0)
    {
        sign = 1;
    }
    do
    {
        s[i++] = n % 10 > 0 ? n % 10 + '0' : -(n % 10) +'0'; 
    } while ((n /= 10) != 0);
    if (sign)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int main()
{
    int min = INT_MIN; /*因为负0代表了负数的最小值，所以Int的负数比正数多一位，即-2^32=符号位为1其余为0*/
    char s[LIMIT];
    itoa(min, s);
    printf("%s\n", s);
    return 0 ;
}