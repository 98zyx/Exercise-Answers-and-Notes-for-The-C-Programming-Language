#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>

int getline2(char *line)
{
    int c, i = 0;
    while ((c = getchar()) != EOF && c != '\n')
    {
        *(line + i++) = c;
    }
    return i;
}
int buf = -2;
int getch()
{
    if (buf != -2)
    {
        int c = buf;
        buf = -2;
        return c;
    }
    else
    {
        return getchar();
    }
}

void ungetch(int c)
{
    buf = c;
}
int minscanf(char *fmt, ...)
{
    int matchnum = 0;
    va_list ap;
    va_start(ap, fmt);
    char *p, *s;
    int c;
    int *ip;
    double *dp;
    for (p = fmt; *p; p++)
    {
        while (isblank(c = getch()))
            ;
        while (isblank(*p))
            p++;
        if (*p != '%')
        {
            if (c != *p)
                return matchnum;
            else
                continue;
        }
        else
        {
            int flag = 1,  flag_deci = 0;
            double point = 10;
            switch (*++p)
            {
            case 'd':
            {
                ip = va_arg(ap, int *);
                if (c == '-' || c == '+')
                {
                    flag = (c == '-') ? -1 : 1;
                    c = getch();
                }
                while (isdigit(c))
                {
                    *ip = 10 * *ip + (c - '0');
                    c = getch();
                }
                ungetch(c);
                *ip = flag * *ip;
                matchnum++;
                break;
            }
            case 'f':
            {
                dp = va_arg(ap, double *);
                if (c == '-' || c == '+')
                {
                    flag = (c == '-') ? -1 : 1;
                    c = getch();
                }
                while (isdigit(c) || c == '.')
                {
                    if (isdigit(c))
                        *dp = 10 * *dp + (c - '0');
                    else if (c == '.')
                        flag_deci = 1;
                    point = (flag_deci == 1) ? 0.1 * point : point;
                    c = getch();
                }
                ungetch(c);
                *dp = *dp * flag * point;
                matchnum++;
                break;
            }
            case 's':
            {
                s = va_arg(ap, char *);
                while (!isblank(c))
                {
                    *s++ = c;
                    c = getch();
                }
                *s = '\0';
                matchnum++;
                break;
            }
            default:
                return matchnum;
            }
        }
    }
    va_end(ap);
    return matchnum;
}
int main()
{
    char line[1000];
    int year=0, month=0;
    int day = 0;
    char *monthname = (char *)malloc(10 * sizeof(char));
    if (scanf("%d %s %d", &day, monthname, &year) == 3)
        printf("valid : %d %s %d\n", day, monthname, year);
    else if (minscanf("%d/%f/%d", &month, &day, &year) == 3)
        printf("valid: %d/%f/%d\n", month, day, year);
    else
        printf("invalid\n");
        
    /*
    while (getline2(line) > 0)
    {
        if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
            printf("valid : %d %s %d\n", day, monthname, year);
        else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
            printf("valid: %s\n", line);
        else
            printf("invalid: %s\n", line);
    }
    */
}