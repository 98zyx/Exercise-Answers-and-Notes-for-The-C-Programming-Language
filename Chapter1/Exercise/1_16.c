#include <stdio.h>
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
/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
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
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    if (max > 0) /* there was a line */
        printf("%s", longest);
    return 0;
}
