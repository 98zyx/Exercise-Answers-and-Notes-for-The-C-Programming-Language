#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
int buf[MAXWORD];
int bufp = 0;

struct pre
{
    char *pre_word;
    struct word *sw;
    int count;
    struct pre *left;
    struct pre *right;
};

struct word
{
    char *word;
    int count;
    struct word *left;
    struct word *right;
};

struct pre *addtree_pre(struct pre *, char *, int);
struct word *addtree_word(struct word *, char *);
struct pre *prealloc(char *, int);
struct word *wordalloc(char *);
int getch2(void);
void ungetch(int);
int getword(char *, int);

struct pre *prealloc(char *s, int n)
{
    struct pre *p = (struct pre *)malloc(sizeof(struct pre));
    char *pre_word = (char *)malloc(n * sizeof(char));
    pre_word = strncpy(pre_word, s, n);
    p->pre_word = pre_word;
    p->sw = wordalloc(s);
    p->count = 1;
    p->left = p->right = NULL;
    return p;
}

struct word *wordalloc(char *s)
{
    struct word *w = (struct word *)malloc(sizeof(struct word));
    char *word = (char *)malloc(strlen(s) * sizeof(char));
    word = strcpy(word, s);
    w->word = word;
    w->count = 1;
    w->left = w->right = NULL;
    return w;
}

struct pre *addtree_pre(struct pre *root, char *word, int n)
{
    int cond;
    if (root == NULL)
    {
        root = prealloc(word, n);
    }
    else if ((cond = strncmp(word, root->pre_word, n)) < 0)
    {
        root->left = addtree_pre(root->left, word, n);
    }
    else if (cond == 0)
    {
        root->count++;
        addtree_word(root->sw, word);
    }
    else
    {
        root->right = addtree_pre(root->right, word, n);
    }
    return root;

}

struct word *addtree_word(struct word *root, char *word)
{
    int cond;
    if (root == NULL)
    {
        root = wordalloc(word);
    }
    else if ((cond = strcmp(word, root->word)) < 0)
    {
        root->left = addtree_word(root->left, word);
    }
    else if (cond == 0)
    {
        root->count++;
    }
    else
    {
        root->right = addtree_word(root->right, word);
    }
    return root;
}
void treeprint_word(struct word *);
void treeprint_pre(struct pre *p)
{
    if (p != NULL)
    {
        treeprint_pre(p->left);
        printf("{\npre: %s count: %4d\n", p->pre_word, p->count);
        treeprint_word(p->sw);
        printf("}\n\n");
        treeprint_pre(p->right);
    }
}

void treeprint_word(struct word *p)
{
    if (p != NULL)
    {
        treeprint_word(p->left);
        printf("word: %s count: %4d\n", p->word, p->count);
        treeprint_word(p->right);
    }
}

int main()
{
    struct pre *root = NULL;
    char word[MAXWORD];
    while (getword(word, MAXWORD) != EOF)
    {
        if(isalpha(word[0]))
        {
            root = addtree_pre(root, word, 3);
        }
    }
    treeprint_pre(root);
    return 0;
}
int getch2()
{
    return (bufp > 0) ? buf[--bufp] : getchar();
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
                if (iscomment == 0 && *(w-1) == '/')
                {
                    iscomment = 1;
                }
                else if (iscomment == 1 && (c2 = getch2()) == '/')
                {
                    iscomment = 0;
                    *(w+1) = '/';
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
