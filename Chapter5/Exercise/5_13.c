#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000
char* getline2(void);
int main(int argc, char *argv[]) //argv是个形参指针，是一个指向字符串数组的指针，没有定义一个数组
{
    int n = 10;
    if (argc > 1)
    {
        if ((*++argv)[0] == '-')
        {
            n = atoi(++argv[0]);
        }
    }
    int len;
    char *s[MAXLINE];//指针数组只保存了地址
    int num_line = 0;
    while ((s[num_line++] = getline2()) != NULL)
        ;
    num_line--;
    if (num_line >= n)
    {
        while (n > 0)
        {
            printf("%s\n", *(s+num_line-n--));
        }
    }
    else
    {
        while (num_line > 0)
        {
            printf("%s\n", *(s+num_line---1));
        }
        
    }
    
    return 0;
}

char* getline2(void)
{
    int c;
    int len = 0, i = 0;
    char *p = (char *) malloc(MAXLINE * sizeof(char));
    while ((c = getchar()) != '\n' && c != EOF)
    {
        *(p+i++) = c;
    }
    if (i == 0)
    {
        return NULL;
    }
    
    *(p+i) = '\0';
    return p;
}
