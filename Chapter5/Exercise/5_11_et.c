#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
    int N = 8;
    if (argc > 1)
    {
        printf("%d\n", argc);
        N = atoi(argv[1]);
        argv = argv + 1;
        argc = argc - 1;
        printf("%d\n", N);
    }
    argc = argc - 1;
    int c;
    int m = 0;
    int n = 0;
    argv++;
    while (argc-- > 0)
    {
        c = *(argv[0]++);
        if (c == '-')
        {
            m = atoi(argv[0]);
            printf("%d\n", m);
        }
        if (c == '+')
        {
            n = atoi(argv[0]);
            printf("%d\n", n);
        }
        argv++;
        printf("argc : %d\n", argc);
    }

    int rest = N;
    c = 0;
    char *input = (char *)malloc(10000*(sizeof(char)));
    int j = 0;
    int num_line = 1;
    while ((c = getchar()) != EOF)
    {
        if (num_line >= m && num_line <= n)
        {
            if (c == '\t')
            {
                int i;
                for (i = 0; i < rest; i++)
                {
                    *(input+j++) = ' ';
                }
                rest = N;
            }
            else
            {
                *(input+j++) = c;
                rest--;
                if (rest < 0 || c == '\n')
                {
                    rest = N;
                }
                if (c == '\n')
                {
                    num_line++;
                }
            }
        }
        else
        {
            *(input+j++) = c;
            if (c == '\n')
            {
                num_line++;
            }
        }
    }
    *(input+j) = '\0';
    printf("%s", input);
    free(input);
    return 0;
}