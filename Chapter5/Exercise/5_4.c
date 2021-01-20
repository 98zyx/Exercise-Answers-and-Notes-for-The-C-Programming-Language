#include <stdio.h>
#include <string.h>
int strend2(char *s, char *t);
int main()
{
    char *s = "12345";
    char *p = "34";
    printf("%d\n", strend2(s, p));
    return 0;
}

int strend2(char *s, char *t)
{
    int n = strlen(s);
    int m = strlen(t);
    s = s + n - m;
    int i;
    for(i = 0; i < m; i++)
    {
        if (*s++ != *t++)
        {
            return 0;
        }
    }
    return 1;
    
}