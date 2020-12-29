#include <stdio.h>
#define N 8

int main()
{
    int rest = N;
    int c;
    int num_space = 0;
    int before_space = 0;
    int distance_n = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            if(before_space == 0)
            {
                before_space = 1;
                distance_n = rest;
            }
            num_space++;
        }
        else
        {
            if (before_space == 1)
            {
                if (num_space >= distance_n)
                {
                    putchar('\t');
                    rest = 8;
                    num_space = num_space - distance_n;
                    int num_tab = num_space / N;
                    int k;
                    for (k = 0; k < num_tab; k++)   
                    {
                        putchar('\t');
                    }
                    num_space = num_space - num_tab * N;
                    k = 0;
                    for (; k < num_space; k++)
                    {
                        putchar(' ');
                        rest--;
                    }
                }
                else
                {
                    int j = 0;
                    for(; j < num_space; j++)
                    {
                        putchar(' ');
                        rest--;
                    }
                }
                before_space = 0;
                num_space = 0;
            }
            putchar(c);
            rest--;
            if (rest < 0 || c == '\n')
            {
                rest = N;
                distance_n = N;
            }
            
        }
    }
    return 0;
}