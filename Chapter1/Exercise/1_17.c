#include <stdio.h>
#define MAXLINE 1000
#define THRESHOLD 10
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

/* print the longest input line */
main()
{
    int len;               /* current line length */
    int max;               /* maximum length seen so far */
    char line[MAXLINE];    /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    max = 0;
    while ((len = getline2(line, MAXLINE)) > 0)
    {
        int i = len-1;
        int flag_meet_word = 0;
        for (; i >= 0; i--)
        {
            if (line[i] == '\t' || line[i] == ' ')
            {
                if (flag_meet_word == 0)
                {
                    line[i] = '\0';
                }
            }
            else
            {
                if (line[i] != '\n')
                {
                    flag_meet_word = 1;
                }
            }
        }
        if (flag_meet_word == 1)
        {
            printf("%s", line);
        }
    }
    return 0;
}