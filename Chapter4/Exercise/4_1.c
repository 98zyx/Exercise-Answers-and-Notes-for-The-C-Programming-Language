#include <stdio.h>
#include <string.h>
#define LIMIT 1000
int strrindex(char s[], char t[]);
int main()
{
    int c, i;
    i = 0;
    char s[LIMIT], t[LIMIT];
    while ((c = getchar()) != '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';
    i = 0;
    while ((c = getchar()) != '\n')
    {
        t[i++] = c;
    }
    t[i] = '\0';
    printf("%d\t", strrindex(s, t));
    return 0;
}

int strrindex(char s[], char t[])
{
    int n = strlen(s);
    int m = strlen(t);
    int i, j, k;
    int found = 1;
    for (i = n - 1; i >= m - 1; i--)
    {
        for (j = m - 1, k = 0; j >= 0; j--, k++)
        {
            if (s[i-k] != t[j])
            {
                found = 0;
                break;
            }
        }
        if (found)
        {
            return i-k+1;
        }
        found = 1;
    }
    return -1;
}