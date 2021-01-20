#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort2(void *lineptr[], int left, int right,
            int (*comp)(void *, void *), int);
int numcmp(char *, char *);
int strcmp2(char *, char *);
int dcmp(char *, char *);
void preprocess(char **, int);

int main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0;
    int reverse = 0;
    int f = 0;
    int c = 0;
    int d = 0;
    while (--argc > 0 && *(*(++argv)) == '-')
    {
        while ((c = *(++*argv)) != '\0')
        {
            if (c == 'r')
            {
                reverse = 1;
            }
            if (c == 'n')
            {
                numeric = 1;
            }
            if (c == 'f')
            {
                f = 1;
            }
            if (c == 'd')
            {
                d = 1;
            }
            
        }
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        d : preprocess(lineptr, nlines);
        qsort2((void **)lineptr, 0, nlines - 1,
               (numeric ? (int (*)(void *, void *))numcmp : (f ? (int (*)(void *, void *))strcmp2 : (int (*)(void *, void *))strcmp)), reverse);
        writelines(lineptr, nlines);
        return 0;
    }
}
void preprocess(char **pp, int nlines)
{
    char *p = *pp; //p保存字符串的首地址
    int i = 0;
    while (nlines-- > 0)
    {
        char c;
        while ((c = *(*(pp)+i++)) != '\0')
        {
            if (isalnum(c) || c == ' ')
            {
                *p++ = c;
            }
        }
        *p = i = 0;
        p = *(++pp);
    }
}
int strcmp2(char *s1, char *s2)
{
    char c1, c2;
    while ((c1 = *s1++) != '\0' && (c2 = *s2++) != '\0')
    {
        if (isalpha(c1) && isalpha(c2))
        {
            if (islower(c1))
            {
                c1 = c1 - 'a';
            }
            else
            {
                c1 = c1 - 'A';
            }
            if (islower(c2))
            {
                c2 = c2 - 'a';
            }
            else
            {
                c2 = c2 - 'A';
            }
        }
        if (c1 > c2)
        {
            return 1;
        }
        else if (c1 < c2)
        {
            return -1;
        }
    }
    return 0;
}
int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
    {
        return -1;
    }
    else if (v1 > v2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
    {
        printf("%s\n", *(lineptr++));
    }
}
int getline2(char *s)
{
    int c, i = 0;
    while ((c = getchar()) != EOF && c != '\n')
    {
        *s++ = c;
        i++;
    }
    *s = '\0';
    return i;
}
int readlines(char *lineptr[], int nlines)
{
    int c, len, i = 0;
    char *p = (char *)malloc(1000 * sizeof(char));
    while (nlines-- > 0 && (len = getline2(p)) > 0)
    {
        char *s = (char *)malloc(len * sizeof(char));
        strcpy(s, p);
        *(lineptr++) = s;
        i++;
    }
    return i;
}
void qsort2(void *v[], int left, int right, int (*comp)(void *, void *), int reverse)
{
    int i, last;
    void swap(void *v[], int, int);
    if (left >= right)
    {
        return;
    }
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = last + 1; i <= right; i++)
    {
        if (reverse)
        {
            if ((*comp)(v[i], v[last]) > 0)
            {
                swap(v, ++last, i);
            }
        }
        else
        {
            if ((*comp)(v[i], v[last]) < 0)
            {
                swap(v, ++last, i);
            }
        }
    }
    swap(v, last, left);
    qsort2(v, left, last - 1, comp, reverse);
    qsort2(v, last + 1, right, comp, reverse);
}

void swap(void *v[], int i, int j)
{
    void *p = v[i];
    v[i] = v[j];
    v[j] = p;
}