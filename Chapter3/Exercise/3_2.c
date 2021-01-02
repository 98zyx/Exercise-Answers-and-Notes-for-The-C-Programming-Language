#include <stdio.h>
#define LIMIT 1000
void escape(char s[], char t[]);
void antiescape(char s[], char t[]);
int main()
{
    char s[LIMIT], t[LIMIT], x[LIMIT];
    int i, c;
    i = 0;
    while ((c = getchar()) != EOF)
    {
        s[i++] = c;
    }
    escape(s, t);
    printf("\n");
    printf("%s\n", t);
    antiescape(t, x);
    printf("%s\n", x);
    return 0;

}

void escape(char s[], char t[])
{
    int i, j;
    i = j = 0;
    while (s[i] != '\0')
    {
        switch(s[i])
        {
            case '\n':
            t[j++] = '\\';
            t[j++] = 'n';
            break;
            case '\t':
            t[j++] = '\\';
            t[j++] = 't';
            break;
            default:
            t[j++] = s[i];
            break;
        }
        i++;
    }
    t[j] = '\0';
}

void antiescape(char s[], char t[])
{
    int i, j;
    i = j = 0;
    while (s[i] != '\0')
    {
        switch(s[i] == '\\' && (s[i+1] == 'n' || s[i+1] == 't'))
        {
            case 1:
            if (s[i+1] == 'n')
            {
                t[j++] = '\n';
                i++;
            }
            else
            {
                t[j++] = '\t';
                i++;
            }
            break;
            default:
            t[j++] = s[i];
            break;
        }
        i++;
    }
    t[j] = '\0';
}