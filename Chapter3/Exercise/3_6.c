#include<stdio.h>
#define LIMIT 1000
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itob(int n, char s[], int b, int m)
{
    if (b < 2 && b > 36)
    {
        return;
    }
    
    int i = 0;
    int nextb = b;
    do
    {
        switch ((n % nextb) / (nextb / b) >= 0 && (n % nextb) / (nextb / b) <= 9)
        {
        case 1:
            s[i++] = '0' + (n % nextb) / (nextb / b);
            break;
        case 0:
            s[i++] = (n % nextb) / (nextb / b) - 10 + 'A';
            break;            
        }
        n = n - n % nextb;
        nextb = nextb * b;
    } while (n != 0);
    while (i < m)
    {
        s[i++] = '0';
    }
    s[i] = '\0';
    reverse(s);
}

int main()
{
    int n = 15464;
    char s[LIMIT];
    itob(n, s, 18, 7);
    printf("%s\n", s);
    return 0;
}