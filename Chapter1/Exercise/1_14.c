#include <stdio.h>
#define NUM_WORDS 128

int main()
{
    int i, j, k, c;
    int nums[NUM_WORDS];
    for (i = 0; i < NUM_WORDS; i++)
    {
        nums[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        nums[c]++;
    }

    for (k = 0; k < NUM_WORDS; k++)
    {
        printf("%6d:", k);
        for (j = 0; j < nums[k]; j++)
        {
            putchar('*');
        }
        printf("\n");
    }
    return 0;
}