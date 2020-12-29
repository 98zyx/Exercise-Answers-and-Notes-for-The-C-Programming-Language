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
void reverse(char s[], char t[], int slen)
{
    int i;
    int flagLine = 0;
    if (s[slen-1] == '\n')
    {
        flagLine = 1;
        slen = slen - 1;
        t[slen] = '\n';
    }
    for (i = 0; i < slen; i++)
    {
        t[i] = s[slen-1-i];
    }
    if (flagLine)
    {
        t[slen+1] = '\0';
    }
    else
    {
        t[slen] = '\0';
    }
    
}
main()
{
    int len;               /* current line length */
    int max;               /* maximum length seen so far */
    char line[MAXLINE];    /* current input line */
    char re[MAXLINE];
    while ((len = getline2(line, MAXLINE)) > 0)
    {
        reverse(line, re, len);
        if (len > 0)
        {
            printf("%s", re);
        }
    }
    return 0;
}