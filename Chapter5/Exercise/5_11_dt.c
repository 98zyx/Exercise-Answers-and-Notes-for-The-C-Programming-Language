#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int N = 8;
    int rest = N;
    if (argc > 1)
    {
        printf("%d\n", argc);
        N = atoi(argv[1]);
        argc = argc - 1;
        argv--;
        printf("%d\n", N);
    }
    argv++;
    argc--;
    int c;
    int m = 0;
    int n = 0;
    while (argc-- > 0)
    {
        if ((c = *argv[0]++) == '-')
        {
            m = atoi(argv[0]);
        }
        if ((c = *argv[0]++) == '+')
        {
            n = atoi(argv[0]);
        }
        argv++;
    }
    c = 0;
    int num_line = 1;
    int num_space = 0;
    int before_space = 0;
    int distance_n = 0;
    char *p = (char *)malloc(1000 * sizeof(char));
    int j = 0;
    while ((c = getchar()) != EOF)
    {
        if (num_line >= m && num_line <= n)
        {
            if (c == ' ')
            {
                if (before_space == 0)
                {
                    before_space = 1;
                    distance_n = rest;
                }
                num_space++;
            }
            else
            {
                if (c == '\n')
                {
                    num_line++;
                }
                
                if (before_space == 1)
                {
                    if (num_space >= distance_n)
                    {
                        *(p+j++) = '\t';
                        rest = 8;
                        num_space = num_space - distance_n;
                        int num_tab = num_space / N;
                        int k;
                        for (k = 0; k < num_tab; k++)
                        {
                            *(p+j++) = '\t';
                        }
                        num_space = num_space - num_tab * N;
                        k = 0;
                        for (; k < num_space; k++)
                        {
                            *(p+j++) = '\t';
                            rest--;
                        }
                    }
                    else
                    {
                        int j = 0;
                        for (; j < num_space; j++)
                        {
                            *(p+j++) = '\t';
                            rest--;
                        }
                    }
                    before_space = 0;
                    num_space = 0;
                }
                *(p+j++) = c;
                rest--;
                if (rest < 0 || c == '\n')
                {
                    rest = N;
                    distance_n = N;
                }
            }
        }
        else
        {
            *(p+j++) = c;
            if (c == '\n')
            {
                num_line++;
            }
        }
    }
    *(p+j) = '\0';
    printf("%s", p);
    free(p);
    return 0;
}