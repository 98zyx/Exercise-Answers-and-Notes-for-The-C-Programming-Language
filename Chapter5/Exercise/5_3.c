#include <stdio.h>
#include <stdlib.h>
int strcat(char *, char *);

int main()
{
    char *s = (char *) malloc(100*sizeof(char));
    *s = '1';
    *(s+1) = '2';
    *(s+2) = '\0';
    char *t = "12345";
    //strcat(s, t);
    strcat(s, t);
    printf("%s\n", s);
    return 0;
}

int strcat(char *s, char *t)
{
    while (*s != '\0')
    {
        s++;
    }
    while ((*s++ = *t++) != '\0')
    {
    }
    //*s = '\0';
    return 0;
}
