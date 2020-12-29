#include <stdio.h>

int main()
{
    int num_space = 0;
    int num_tab = 0;
    int num_line = 0;
    int c = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            num_space++;
        }
        else if (c == '\t')
        {
            num_tab++;
        }
        else if (c == '\n')
        {
            num_line++;
        }
    }
    printf("number of space:%6d\n", num_space);
    printf("number of tab:  %6d\n", num_tab);
    printf("number of line: %6d\n", num_line);
    return 0;
}