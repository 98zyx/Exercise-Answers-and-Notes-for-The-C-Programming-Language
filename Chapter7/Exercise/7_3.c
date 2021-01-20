#include <stdarg.h>

void minprintf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    int ival;
    int i;
    int precision = -1;
    double dval;
    va_start(ap, fmt);
    for (p = fmt; *p; p++)
    {
        if (*p != '%')
        {
            putchar(*p);
            continue;
        }
        s:
        switch (*++p)
        {
        case 'd':
            ival = va_arg(ap, int);
            i = (precision != -1) ? printf("%*d", precision, ival) : printf("%d", ival);
            break;
        case 'f':
            dval = va_arg(ap, double);
            i = (precision != -1) ? printf("%*f", precision, dval) : printf("%f", dval);
            break;
        case 's':
            for (sval = va_arg(ap, char *); *sval; sval++, precision--)
                putchar(*sval);
            while (precision-- > 0) putchar(' ');
            break;
        case '*':
            precision = va_arg(ap, int);
            goto s;
        default:
            putchar(*p);
            break;
        }
        precision = -1;
    }
    va_end(ap);
}

int main()
{
    minprintf("%s|ssss|%*d\n", "abc", 10, 1);
}