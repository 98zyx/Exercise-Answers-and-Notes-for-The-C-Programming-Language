#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct list
{
    int n;
    struct list *next;
};

struct word
{
    char *wd;
    struct list *ls;
    struct word *left;
    struct word *right;
};

struct word *addtree(struct word *, char *, int);
struct list *addlist(struct list *, int);
struct word *wordalloc(char *, int);
struct list *listalloc(int);

struct word *addtree(struct word *w, char *s, int n)
{
    int cond;

    if (w == NULL)
    {
        return wordalloc(s, n);
    }
    else if ((cond = strcmp(s, w->wd)) < 0)
    {
        w->left = addtree(w->left, s, n);
    }
    else if (cond == 0)
    {
        w->ls = addlist(w->ls, n);
    }
    else
    {
        w->right = addtree(w->right, s, n);
    }
    return w;
}

struct list *addlist(struct list *ls, int n)
{
    if (ls == NULL)
    {
        return listalloc(n);
    }
    else
    {
        if (ls->next == NULL)
        {
            ls->next = listalloc(n);
        }
        else
        {
            addlist(ls->next, n);
        }
    }
    return ls;
}

struct word *wordalloc(char *wd, int n)
{
    struct word *w = (struct word *)malloc(sizeof(struct word));
    w->left = w->right = NULL;
    w->ls = listalloc(n);
    char *s = (char *)malloc((strlen(wd)+1) * sizeof(char));
    w->wd = strcpy(s, wd);
    return w;
}

struct list *listalloc(int n)
{
    struct list *ls = (struct list *)malloc(sizeof(struct list));
    ls->n = n;
    ls->next = NULL;
    return ls;
}

int getline2(char *, int);
int getword(char *, char *, int *);

int getline2(char *s, int lim)
{
    int c;
    int i = 0;
    while ((c = getchar()) != EOF && c != '\n' && --lim > 0)
    {
        *(s+i++) = c;
    }
    *(s+i) = '\0';
    return i;
}

int getword(char *dst_start, char *src, int *i)
{
    int c;
    char *dst = dst_start;
    while (isspace(c = *(src+(*i)++)))
    {
    }
    if (c != EOF)
    {
        *dst++ = c;
    }
    if (!isalpha(c))
    {
        *dst = '\0';
        return c;
    }
    while (isalpha((c = *(src+(*i)++))))
    {
        *dst++ = c;
    }
    *i = *i - 1;
    *dst = '\0';
    return dst_start[0];
}
void treeprint(struct word *);
void listprint(struct list *);

void treeprint(struct word *root)
{
    if (root != NULL)
    {
        treeprint(root->left);
        printf("\nword: %s\n", root->wd);
        listprint(root->ls);
        treeprint(root->right);
    }
}

void listprint(struct list *ls)
{
    if (ls != NULL)
    {
        printf("%d ", ls->n);
        listprint(ls->next);
    }
}
int main()
{
    struct word *root = NULL;
    char line[1000], word[1000];
    int len;
    int i = 0;
    int nline = 0;
    while ((len = getline2(line, 1000)) > 0)
    {
        while ((getword(word, line, &i)) != EOF && word[0] != '\0')
        {
            if (isalpha(word[0]))
            {
                root = addtree(root, word, nline);
            }
        }
        i = 0;
        nline++;
    }
    treeprint(root);
    printf("\n");
    return 0;
}


