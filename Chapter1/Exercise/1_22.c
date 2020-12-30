#include <stdio.h>
#define N 8
#define MAXLINE 1000

int getline2(char s[], int lim)
{
    int c, i, j;
    for (i = 0, j = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    {
        if (j < lim - 1)
        {
            s[j++] = c;
        }
    }
    if (c == '\n')
    {
        if (j < lim - 1)
        {
            s[j++] = c;
        }
        i++;
    }
    s[j] = '\0';
    return i;
}

int main()
{
    int c = 0;
    int rest = 0;
    char new_line[N + 1];
    char line[MAXLINE];
    int i, j, k, len, flag_out;
    i = j = k = 0;
    for (i = 0; i < N + 1; i++)
    {
        new_line[i] = 0;
    }

    while ((len = getline2(line, MAXLINE)) > 0)
    {
        for (j = 0; j < len; j++)
        {
            new_line[rest] = line[j];
            rest++;
            if (rest == 8)
            {
                new_line[rest] = '\0';
                rest = 0;
                int flag_meet_word = 0;
                for (k = N - 1; k >= 0; k--)
                {
                    if (new_line[k] == ' ')
                    {
                        if (flag_meet_word == 0)
                        {
                            new_line[k] = '\0';
                        }
                    }
                    else
                    {
                        flag_meet_word = 1;
                    }
                }
                printf("%s\n", new_line);
                flag_out = 1;
            }
            else
            {
                flag_out = 0;
            }
        }
    }
    if (flag_out = 0)
    {
        new_line[rest] = '\0';
        printf("%s\n", new_line);
    }
    return 0;
}