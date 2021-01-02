#include <stdio.h>
int binsearch(int x, int v[], int n);

int main()
{
    int v[5] = {0, 1, 2, 3, 4};
    printf("%d\n", binsearch(3, v, 5));
}

int binsearch(int x, int v[], int n)
{
    int mid, low, high;
    low = 0;
    high = n - 1;
    while (low <= high && v[mid] != x)
    {
        mid = (low + high) / 2;
        if (v[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return v[mid] == x ? mid : -1;
}