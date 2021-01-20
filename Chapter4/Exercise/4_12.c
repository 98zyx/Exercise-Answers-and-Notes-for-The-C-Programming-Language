#include <stdio.h>

int itoa(int, char *);
int reverse(int, char *, char *);
int main()
{
    int x = 232312124;
    char s[1000], t[1000];
    int pos = itoa(x, s);
    s[pos] = '\0';
    printf("%s\n", s);
    pos = reverse(0, s, t);
    t[pos] = '\0';
    printf("%s\n", t);
}

int itoa(int num, char *s)
{
    if (num == 0)
    {
        return 0;
    }
    else
    {
        int pos = itoa(num/10, s);
        s[pos] = num % 10 + '0';
        return pos + 1;
    }
}

int reverse(int num, char *s, char *t)
{
    if (s[num+1] == '\0')
    {
        t[0] = s[num];
        return 1;
    }
    else
    {
        int pos = reverse(num+1, s, t);
        t[pos] = s[num];
        return pos + 1;
    }
}

