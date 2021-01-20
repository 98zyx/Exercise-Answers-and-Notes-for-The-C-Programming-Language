#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 1000
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        exit(1);
    }
    char *s1 = (char *) malloc(MAXCHAR * sizeof(char));
    char *s2 = (char *) malloc(MAXCHAR * sizeof(char));

    FILE *fp1 = fopen(argv[1], "r");
    FILE *fp2 = fopen(argv[2], "r");

    char *t1 = fgets(s1, MAXCHAR, fp1);
    char *t2 = fgets(s2, MAXCHAR, fp2);
    while (t1 != NULL || t2 != NULL)
    {
        if (strcmp(s1, s2) != 0)
        {
            fputs(s1, stdout);
            fputs("\n", stdout);
            fputs(s2, stdout);
            break;
        }
        *s1 = '\0';
        *s2 = '\0';
        t1 = fgets(s1, MAXCHAR, fp1);
        t2 = fgets(s2, MAXCHAR, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    if (ferror(stdout))
    {
        fprintf(stderr, "%s : error", argv[0]);
    }
    exit(0);
}