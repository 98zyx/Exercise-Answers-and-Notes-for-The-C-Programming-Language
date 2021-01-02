#include <stdio.h>
#define LIMIT 1000
void squeeze(char s1[], char s2[]);

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
    squeeze(s1, s2);
    printf("%s\n", s1);
    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j, k;
    i = k = j = 0;
    int flag = 0;
    for ( i = 0; s1[i] != '\0'; i++)
    {
        for (j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            s1[k++] = s1[i];
        }
        flag = 0;
    }
    s1[k] = '\0';
}