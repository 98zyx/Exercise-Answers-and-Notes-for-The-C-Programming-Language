#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define LIMIT 1000
double atof(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') 
    {
        i++;
    }
    for (val = 0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.')
    {
        i++;
    }
    for ( power = 1.0; isdigit(s[i]) ; i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    int e = 0;
    int sign2 = 1;
    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
    }
    if (s[i] == '-' || s[i] == '+')
    {
        if (s[i] == '-')
        {
            sign2 = -1;
            i++;
        }
        else
        {
            i++;
        }
    }
    
    for (; isdigit(s[i]); i++)
    {
        e = 10 * e + (s[i] - '0');
    }
    e = sign2 * pow(10, e);
    return (sign * val / power) * e;
}

int main()
{
    char s[LIMIT];
    int c, i;
    i = 0;
    while ((c = getchar()) != EOF)
    {
        s[i++] = c;
    }
    printf("%f\n", atof(s));
}