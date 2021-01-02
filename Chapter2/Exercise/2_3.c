#include <stdio.h>
#define LIMIT 1000
int htoi(char s[]);

int main()
{
    int i, c;
    char s[LIMIT];
    for ( i = 0; i < LIMIT; i++)
    {
        s[i] = 0;
    }
    for (i = 0; i < LIMIT - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }
    s[i] = '\0';
    int res = htoi(s);
    printf("%d\n", res);
    return 0;
}

int htoi(char s[])
{
    int i = 0;
    int res = 0;
    while (s[i] != '\0')
    {       
        if (s[i] <= '9' && s[i] >= '0')
        {
            res = res * 16 + (s[i] - '0');
        }
        if (s[i] <= 'F' && s[i] >= 'A')
        {
            res = res * 16 + (s[i] - 'A' + 10);
        }
        if (s[i] <= 'f' && s[i] >= 'a')
        {
            res = res * 16 + (s[i] - 'a' + 10);
        }
        i++;
    }
    return res;
    
}