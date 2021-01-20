#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXWORD 100
int buf[MAXWORD];
int bufp = 0;
#define HASHSIZE 101
struct nlist
{
    struct nlist *next;
    char *name;
    char *defn;
};
static struct nlist *hashtab[HASHSIZE];
unsigned hash(char *);
struct nlist *lookup(char *);
struct nlist *install(char *, char *);
void undef(char *);
void printtab(void);
unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
    {
        hashval = hashval * 31 + *s;
    }
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
    struct nlist *np;
    int hashval = hash(s);
    for (np = hashtab[hashval]; np != NULL; np = np->next)
    {
        if (strcmp(np->name, s) == 0)
        {
            return np;
        }
    }
    return NULL;
}

struct nlist *install(char *name, char *defn)
{
    struct nlist *p;
    int hashval = hash(name);
    if ((p = lookup(name)) == NULL)
    {
        p = (struct nlist *)malloc(sizeof(struct nlist));
        if (p == NULL || (p->name = (char *)malloc((strlen(name) + 1) * sizeof(char))) == NULL)
        {
            return NULL;
        }
        else
        {
            p->name = strcpy(p->name, name);
            p->next = hashtab[hashval];
            hashtab[hashval] = p;
        }
    }
    else
    {
        free((void *)p->defn);
    }
    if ((p->defn = (char *)malloc((strlen(defn) + 1) * sizeof(char))) == NULL)
    {
        return NULL;
    }
    strcpy(p->defn, defn);
    return p;
}
int getch2()
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
int getch3()
{
    if (bufp > 0)
    {
        bufp--;
        return buf[0];
    }
    return getchar();
}

void ungetch(int c)
{
    bufp < MAXWORD ? buf[bufp++] = c : 0;
}

int getword(char *word, int n)
{
    static i = 0;
    int c;
    char *w = word;
    int isstring = 0;
    while (isspace(c = getch2()))
    {
    }
    if (c != EOF)
    {
        *w++ = c;
    }
    if (!isalpha(c) && (c != '#') && (c != '"') && (c != '_') && (c != '/'))
    {
        *w = '\0';
        return c;
    }
    if (c == '"')
    {
        isstring = 1;
    }
    int iscomment = 0;
    for (; --n > 0; w++)
    {
        if (!isalnum(*w = getch2()) && !(*w == '_') && !(isstring && *w == '"'))
        {
            int c2 = -2;
            if (*w == '*')
            {
                if (iscomment == 0 && *(w - 1) == '/')
                {
                    iscomment = 1;
                }
                else if (iscomment == 1 && (c2 = getch2()) == '/')
                {
                    iscomment = 0;
                    *(w + 1) = '/';
                    w = w + 2;
                    break;
                }
                else
                {
                    ungetch(*w);
                    (c2 != -2) ? ungetch(c) : 0;
                    break;
                }
            }
            else
            {
                ungetch(*w);
                break;
            }
        }
    }
    *w = '\0';
    return word[0];
}

void undef(char *name)
{
    struct nlist *p, *pre;
    int hashval = hash(name);
    for (p = hashtab[hashval], pre = hashtab[hashval]; p != NULL; p = p->next)
    {
        if (strcmp(p->name, name) == 0)
        {
            if (p != hashtab[hashval])
                pre->next = p->next;
            else
                hashtab[hashval] = p->next;
            free(p->defn);
            free(p->name);
            free((void *)p);
            break;
        }
        pre = p;
    }
}

void printtab(void)
{
    int i = 0;
    struct nlist *p;
    for (i = 0; i < HASHSIZE; i++)
    {
        for (p = hashtab[i]; p != NULL; p = p->next)
        {
            printf("%s %s\n", p->name, p->defn);
        }
    }
}

char *matchtab(char c)
{
    int i = 0;
    struct nlist *p;
    for (i = 0; i < HASHSIZE; i++)
    {
        for (p = hashtab[i]; p != NULL; p = p->next)
        {
            if ((p->name)[0] == c)
            {
                return p->name;
            }
        }
    }
    return NULL;
}

int main()
{
    char word[1000];
    int c;
    char out[1000];
    while ((c = getword(word, 1000)) != EOF)
    {
        if (strcmp(word, "#define") == 0)
        {
            while (isspace(getword(word, 1000)))
                ;
            char *name = (char *)malloc((strlen(word) + 1) * sizeof(char));
            strcpy(name, word);
            while (isspace(getword(word, 1000)))
                ;
            char *defn = (char *)malloc((strlen(word) + 1) * sizeof(char));
            strcpy(defn, word);
            install(name, defn);
            free(name);
            free(defn);
        }
    }
    printf("load program:\n");
    int i, j;
    i = j = 0;
    bufp = 0;
    int match = -1;
    char *pat;
    while ((c = getchar()) != EOF)
    {
        if (match == -1)
        {
            if ((pat = matchtab(c)) != NULL)
            {
                i++;
                ungetch(c);
                match = 1;
            }
            else
            {
                out[j++] = c;
            }
        }
        else
        {
            if (*(pat + i) == '\0')
            {
                char *d = lookup(pat)->defn;
                while (*d != '\0')
                {
                    out[j++] = *d++;
                }
                match = -1;
                i = 0;
            }
            if (c == *(pat + i++) && match != -1)
            {
                ungetch(c);
            }
            else
            {
                i = 0;
                if ((pat = matchtab(c)) != NULL)
                {
                    i++;
                    ungetch(c);
                    match = 1;
                }
                else
                {
                    out[j++] = c;
                }
            }
        }
    }
    if (pat != NULL && *(pat + i) == '\0')
    {
        char *d = lookup(pat)->defn;
        while (*d != '\0')
        {
            out[j++] = *d++;
        }
        match = -1;
    }
    out[j] = '\0';
    printf("%s", out);
}