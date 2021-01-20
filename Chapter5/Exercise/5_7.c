#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];
int readlines(char *lineptr[], int nlines);
int readlines2(char *lineptr[], int maxlines, char *storeptr);
void writelines(char *lineptr[], int nlines);
#define MAXSIZE 10000

void qsort2(char *lineptr[], int left, int right);

int main()
{
    int nlines;
    char *storeptr = (char *) malloc(MAXSIZE * sizeof(char));
    if ((nlines = readlines2(lineptr, MAXLINES, storeptr)) >= 0)
    {
        qsort2(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error : input too big to sort\n");
        return 1;
    }
}


    
#define MAXLEN 1000
int getline2(char *, int);
int getline2(char *s, int maxsize)
{
    int c, i= 0;
    while (i < maxsize && (c = getchar()) != EOF && c != '\n')
    {
        i++;
        *s++ = c;
    }
    *s = '\0';
    return i;
}
char *alloc(int);
int readlines(char *lineptr[], int maxlines)
{
    static usedlen = 0;
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = getline2(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
        {
            return -1;
        }
        else
        {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

int readlines2(char *lineptr[], int maxlines, char *storeptr)
{
    static usedlen = 0;
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = getline2(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || ((usedlen + len) > MAXSIZE))
        {
            return -1;
        }
        else
        {
            line[len - 1] = '\0';
            strcpy((storeptr+usedlen), line);
            lineptr[nlines++] = storeptr+usedlen;
            usedlen += len;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
    {
        printf("%s\n", *lineptr++);
    }
}

void qsort2(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);
    if (left >= right)
    {
        return;
    }
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left+1; i <= right; i++)
    {
        if (strcmp(v[i], v[left]) < 0)
        {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort2(v, left, last-1);
    qsort2(v, last+1, right);
}

void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    }
    else
    {
        return 0;
    }
}

void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    {
        allocp = p;
    }
    
}