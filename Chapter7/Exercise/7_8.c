#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int *ip = (int *)malloc(sizeof(int));
    *ip = 1;
    free(ip);
    FILE *fp;
    char *prog = *argv;
    char *line = (char *)malloc(1000 * sizeof(char));
    int i = 1;
    while (--argc > 0)
    {
        if ((fp = fopen(*++argv, "r")) != NULL)
        {
            fprintf(stdout, "%s %d\n", *argv, i++);
            while (fgets(line, 1000, fp) != NULL)
            {
                fputs(line, stdout);
            }
            fputc('\f', stdout);
            fclose(fp);
        }
        else
        {
            fprintf(stderr, "%s error", prog);
            exit(1);
        }
    }
    if (ferror(stdout))
    {
        fprintf(stderr, "%s error", prog);
        exit(1);
    }
}