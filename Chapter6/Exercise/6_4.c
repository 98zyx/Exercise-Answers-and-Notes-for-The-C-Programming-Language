#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct dlist
{
    struct dlist *last;
    struct dlist *next;
    char *word;
    int count;
};

struct dlist *addnode(struct dlist *, char *);
struct dlist *findnode(struct dlist *, char *);
struct dlist *nodealloc(char *);
struct dlist *schedulenode(struct dlist *, struct dlist *);
void nodeprint(struct dlist *);

struct dlist *addnode(struct dlist *root, char *s)
{
    if (root == NULL)
    {
        return nodealloc(s);
    }
    else
    {
        struct dlist *n = findnode(root, s);
        if (n == NULL)
        {
            struct dlist *new = nodealloc(s);
            root = schedulenode(root, new);
        }
        else
        {
            n->count++;
            if (n->last != NULL)
                n->last->next = n->next;
            if (n->next != NULL)
                n->next->last = n->last;
            n->next = NULL;
            n->last = NULL;
            root = schedulenode(root, n);
        }
    }
    return root;
}

struct dlist *findnode(struct dlist *root, char *s)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        if (strcmp(root->word, s) != 0)
        {
            return findnode(root->next, s);
        }
        else
        {
            return root;
        }
    }
}

struct dlist *nodealloc(char *s)
{
    struct dlist *n = (struct dlist *)malloc(sizeof(struct dlist));
    n->count = 1;
    char *d = (char *)malloc((strlen(s)+1) * sizeof(char));
    n->word = strcpy(d, s);
    n->last = n->next = NULL;
    return n;
}

struct dlist *schedulenode(struct dlist *root, struct dlist *new)
{
    if (root == new)
    {
        return root;
    }
    if (root == NULL)
    {
        return new;
    }
    if (root->count >= new->count)
    {
        root->next = schedulenode(root->next, new);
        root->next->last = root;
    }
    else
    {
        new->next = root;
        root = new;
    }
    return root;
}

void nodeprint(struct dlist *n)
{
    if (n != NULL)
    {
        printf("%s : %4d\n", n->word, n->count);
        nodeprint(n->next);
    }
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

int main()
{
    
    char line[1000], word[1000];
    int len, nline;
    int i = 0;
    nline = 0;
    struct dlist *root = NULL;
    while((len = getline2(line, 1000)) > 0)
    {
        while (getword(word, line, &i) != EOF && word[0] != '\0')
        {
            if (isalpha(word[0]))
            {
                root = addnode(root, word);
            }
        }
        i = 0;
        nline++;
    }
    printf("\n");
    nodeprint(root);
    return 0;
    
}