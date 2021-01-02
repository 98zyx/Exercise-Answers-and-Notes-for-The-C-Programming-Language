#include <stdio.h>
#define LIMIT 1000
int any(char s1[], char s2[]);

int main()
{
    int i, c;
    char s1[LIMIT], s2[LIMIT];
    for ( i = 0; i < LIMIT-1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s1[i] = c;
    }
    s1[i] = '\0';
    for ( i = 0; i < LIMIT-1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s2[i] = c;
    }
    printf("%d\n", any(s1, s2));
    return 0;
}

int any(char s1[], char s2[])
{
    int i, j;
    i = j = 0;
    for (i = 0; s1[i] != '\0'; i++)
    {
        for (j = 0; j < s2[j]; j++)
        {
            if (s1[i] == s2[j])
            {
                return i;
            }
        }
    }
    return -1;
}