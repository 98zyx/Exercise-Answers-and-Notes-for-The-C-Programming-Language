#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int sp = 0;
double val[MAXVAL];

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int main()
{
    int type;
    double op2;
    char s[MAXOP];
    int end = 0;
    while (end != 1 && (type = getop(s)) != EOF)
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
            case '=':
                printf("\t%.8g\n", pop());
                end = 1;
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

int getop(char s[])
{
    scanf("%s", s);
    if (isdigit(s[0]))
    {
        return NUMBER;
    }
    else
    {
        return s[0];
    }
    
}

char buf[BUFSIZE];
int bufp = 0;
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp < BUFSIZE)
    {
        buf[bufp++] = c;
    }   
}