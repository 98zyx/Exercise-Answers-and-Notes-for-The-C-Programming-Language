#include <stdio.h>
int transformToCelsius(int f);

int main()
{
    int fahr = 123;
    int celsius = transformToCelsius(fahr);
    printf("%d\n", celsius);
    return 0;
}

int transformToCelsius(int f)
{
    return 5 * (f-32) / 9;
}