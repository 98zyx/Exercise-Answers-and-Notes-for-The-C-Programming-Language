#include <stdio.h>

#define MAX_LENGTH 10

int main()
{
    int n_length[MAX_LENGTH];
    int i, j, k;
    for (i = 0; i < MAX_LENGTH; i++)
    {
        n_length[i] = 0;
    }
    int c;
    int word_length = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            if (word_length != 0)
            {
                n_length[word_length]++;
                word_length = 0;
            }
        }
        else
        {
            word_length++;
        }
    }

    for (k = 0; k < MAX_LENGTH; k++)
    {
        printf("%3d:", k);
        for (j = 0; j < n_length[k]; j++)
        {
            putchar('*');
        }
        printf("\n");
    }
    return 0;

}