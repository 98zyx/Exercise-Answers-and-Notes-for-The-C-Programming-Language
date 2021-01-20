#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 1000

char *pat = "Hello, world!";
int main(int argc, char *argv[])
{
    FILE *fp;
    char *prog = argv[0];
    char *line = (char *)malloc(MAXCHAR * sizeof(char));
    if (argc > 1)
    {
        while (--argc > 0)
        {
            if ((fp = fopen(*++argv, "r")) != NULL)
            {
                while (fgets(line, MAXCHAR, fp) != NULL)
                {
                    if (strstr(line, pat) != NULL)
                    {
                        fputs(line, stdout);
                        fputs("\n", stdout);
                    }
                }
                fclose(fp);
            }
            else
            {
                fprintf(stderr, "%s error", prog);
                exit(1);
            }
        }
    }
    else
    {
        while ((line = fgets(line, MAXCHAR, stdin)) != NULL)
        {
            if (strstr(pat, line) != NULL)
            {
                fputs(line, stdout);
            }
        }
    }
    if (ferror(stdout))
    {
        fprintf(stderr, "%s error", prog);
        exit(1);
    }
    return 0;
}