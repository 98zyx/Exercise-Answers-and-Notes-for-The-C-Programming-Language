#include <stdio.h>
#define LIMIT 1000
void expand(char s1[], char s2[]);

int main()
{
    char s1[LIMIT], s2[LIMIT];
    int c, i;
    i = 0;
    while ((c = getchar()) != EOF)
    {
        s1[i++] = c;
    }
    expand(s1, s2);
    printf("%s\n", s2);
    return 0;
}

void expand(char s1[], char s2[])
{
    int i, j, k;
    i = j = k = 0;
    while (s1[i] != EOF)
    {
        char c1 = s1[i];
        char c2 = s1[i+1];
        char c3 = s1[i+2];
        if (s1[i] >= 'a' && s1[i] <= 'z' && s1[i+1] == '-' && s1[i+2] >= 'a' && s1[i+2] <= 'z' )
        {
            for ( j = 0; j <= c3 - c1; j++)
            {
                s2[k++] = s1[i] + j;
            }
            i += 3;
        }
        else if (s1[i] >= 'A' && s1[i] <= 'Z' && s1[i+1] == '-' && s2[i+2] >= 'A' && s1[i+2] <= 'Z')
        {
            for ( j = 0; j < s1[i+2] - s1[i]; j++)
            {
                s2[k++] = s1[i] + j;
            }
            i += 3;
        }
        else if ((s1[i] >= '0' && s1[i] <= '9') && s1[i+1] == '-' && (s2[i+2] >= '0' && s1[i+2] <= '9'))
        {
            for ( j = 0; j < s1[i+2] - s1[i]; j++)
            {
                s2[k++] = s1[i] + j;
            }
            i += 3;
        }
        else
        {
            s2[k++] = s1[i++];
        }
    }
    s2[k] = '\0';
}