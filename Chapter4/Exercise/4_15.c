#include <stdio.h>
#define swap(t, x, y) {t z = x; x = y; y = z;}

int main()
{
    double a = 0.1;
    double b = 1;
    swap(double, a, b)
    printf("%f\n", a);
    printf("%f\n", b);
}