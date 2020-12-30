#include <stdio.h>

int main()
{
    int c, lastc;
    int in_comment = 0;
    int in_string = 0;
    while ((c = getchar()) != EOF)
    {       
        if (c == '"')
        {
            if (in_string == 0)
            {
                if (in_comment == 0)
                {
                    putchar(c);
                    lastc = c;
                }
                
                in_string = 1;
            }
            else
            {
                if (in_comment == 0)
                {
                    putchar(c);
                    lastc = c;
                }
                in_string = 0;
            }
        }
        else if (in_string == 1)
        {
            if (in_comment == 0)
            {
                putchar(c);
                lastc = c;
            }
        }
        else
        {
            if (c == '*' && lastc == '/')
            {
                in_comment = 1;
            }
            else if (c == '/' && lastc == '*')
            {
                in_comment = 0;
            }
            else
            {
                if (in_comment == 0)
                {
                    if (lastc == '/')
                    {
                        putchar(lastc);
                        putchar(c);
                    }
                    else
                    {
                        if (c == '/')
                        {
                            lastc = c;
                        }
                        else
                        {
                            putchar(c);
                            lastc = c;
                        }
                    }
                }
                else
                {
                    lastc = c;
                }
                
            }
        }
    }
}