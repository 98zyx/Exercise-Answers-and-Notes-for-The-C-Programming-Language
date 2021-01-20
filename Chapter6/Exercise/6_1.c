#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(struct key))
int buf[MAXWORD];
int bufp = 0;

struct key
{
    char *word;
    int count;
} keytab[] = 
{
    {"#define", 0},
    {"auto", 0},
    {"break", 0},
    {"case", 0},
};

int getch2(void);
void ungetch(int);
int getword(char *, int);
int binsearch(char *, struct key *, int);

int main()
{
    int n;
    char word[MAXWORD];
    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]))
        {
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
            {
                keytab[n].count++;
            }
        }
        else
        {
            printf("%s\n", word);
        }
        
    }
    for (n = 0; n < NKEYS; n++)
    {
        if (keytab[n].count > 0)
        {
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
        }
    }
    return 0;
}

int binsearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid])) < 0)
        {
            high = mid - 1;
        }
        else if (cond == 0)
        {
            return mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int getch2()
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    bufp < MAXWORD ? buf[bufp++] = c : 0;
}

int getword(char *word, int n)
{
    static i = 0;
    int c;
    char *w = word;
    int isstring = 0;
    while (isspace(c = getch2()))
    {
    }
    if (c != EOF)
    {
        *w++ = c;
    }
    if (!isalpha(c) && (c != '#') && (c != '"') && (c != '_') && (c != '/'))
    {
        *w = '\0';
        return c;
    }
    if (c == '"')
    {
        isstring = 1;
    }
    int iscomment = 0;
    for (; --n > 0; w++)
    {
        if (!isalnum(*w = getch2()) && !(*w == '_') && !(isstring && *w == '"'))
        {
            int c2 = -2;
            if (*w == '*')
            {
                if (iscomment == 0 && *(w-1) == '/')
                {
                    iscomment = 1;
                }
                else if (iscomment == 1 && (c2 = getch2()) == '/')
                {
                    iscomment = 0;
                    *(w+1) = '/';
                    w = w + 2;
                    break;
                }
                else
                {
                    ungetch(*w);
                    (c2 != -2) ? ungetch(c) : 0;
                    break;
                }
                       
            }
            else
            {
                ungetch(*w);
                break;   
            }
        }
    }
    *w = '\0';
    return word[0];
}
