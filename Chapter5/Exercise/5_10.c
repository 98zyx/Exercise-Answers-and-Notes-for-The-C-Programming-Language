#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int sp = 0;
double val[MAXVAL];

int getop(char s[], char *t);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int main(int argc, char *argv[])
{
    int type;
    double op2;
    char s[MAXOP];
    int a = argc;
    char **b = argv;
    argv = b;
    argc = a;
    while (--argc > 0 && (type = getop(s, *++argv)) != EOF)
    {
        switch(type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                {
                    push(pop() / op2);
                }
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            case '%':
                op2 = pop();
                push((int)pop() % (int)op2);
                break;
            default:
                printf("error: unkown command %s\n", s);
                break;
        }
    }
    printf("\t%.8g\n", pop());
    return 0;
}


void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
}

double pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }
    
}

int getop(char s[], char *t)
{
    int i, c;
    int j = 0;
    while ((s[0] = c = *(t+j++)) == ' ' || c == '\t')
    {
        /* code */
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
    {
        return c;
    }
    i = 0;
    char c2;
    if (c == '-')
    {
        c2 = *(t+j++);
        if (isdigit(c2))
        {
            s[i] = '-';
            c = c2;
            j--;
        }
        else
        {
            return c;
        }
    }
    
    if (isdigit(c))
    {
        while (isdigit(s[++i] = c = *(t+j++)))
        {
            /* code */
        }
    }
    if (c == '.')
    {
        while (isdigit(s[++i] = c = *(t+j++)))
        {
            /* code */
        }
    }
    s[i] = '\0';
    return NUMBER;
}
