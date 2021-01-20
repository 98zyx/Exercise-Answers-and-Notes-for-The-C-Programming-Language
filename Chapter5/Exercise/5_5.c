#include <stdio.h>
#include <stdlib.h>
char *strncpy(char *, char *, int);
char *strncat(char *, char *, int);
int strncmp(char *, char *, int);

int main()
{
    char *s = (char *)malloc(1000 * sizeof(char));
    char *copy_s = s;
    int c;
    while ((c = getchar()) != '\n')
    {
        *s++ = c;
    }
    *s = '\0';
    char *t = (char *)malloc(1000 * sizeof(char));
    char *copy_t = t;
    while ((c = getchar()) != '\n')
    {
        *t++ = c;
    }
    *t = '\0';
    printf("%d\n", strncmp(copy_s, copy_t, 3));
    printf("%s\n", strncat(copy_s, copy_t, 3));
    printf("%s\n", strncpy(copy_s, copy_t, 3));
    
}

char *strncpy(char *s, char *t, int n)
{
    char *start = s;
    int i = 0;
    while (i++ < n && (*s++ = *t++) != '\0')
    {
        
    }
    return start;
}

char *strncat(char *s, char *t, int n)
{
    char *start = s;
    int i = 0;
    while (*s != '\0')
    {
        s++;
    }
    while (i++ < n && (*s++ = *t++) != '\0')
    {
        /* code */
    }
    return start;
}

int strncmp(char *s, char *t, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (*s > *t)
        {
            return 1;
        }
        else if (*s < *t)
        {
            return -1;
        }
    }
    return 0;
    
}