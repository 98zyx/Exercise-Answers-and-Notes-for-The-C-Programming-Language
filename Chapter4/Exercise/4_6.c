#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
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
void ungets(char *);

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
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
            case 's':
                push(sin(pop()));
                break;
            case 'e':
                push(exp(pop()));
                break;
            case 'p':
                op2 = pop();
                push(pow(pop(), op2));
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

double peek()
{
    return sp >= 1 ? val[sp-1] : 0;    
}

void exchange()
{
    if (sp > 1)
    {
        double p1 = pop();
        double p2 = pop();
        push(p1);
        push(p2);
    }
}

void clean()
{
    sp = 0;
}

int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
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
        c2 = getch();
        if (isdigit(c2))
        {
            s[i] = '-';
            c = c2;
            ungetch(c2);
        }
        else
        {
            ungetch(c2);
            return c;
        }
    }
    
    if (isdigit(c))
    {
        while (isdigit(s[++i] = c = getch()))
        {
            /* code */
        }
    }
    if (c == '.')
    {
        while (isdigit(s[++i] = c = getch()))
        {
            /* code */
        }
    }
    s[i] = '\0';
    if (c != EOF)
    {
        ungetch(c);
    }
    return NUMBER;
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

void ungets(char *s)
{
    if (bufp + strlen(s)+1 <BUFSIZE)
    {
        int i;
        for (i = 0; i <= strlen(s); i++)
        {
            ungetch(s[i]);
        }
    }
    
}