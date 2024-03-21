
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAXWORD 100
#define skip(k,l) if(c==k) while((c=getch())!=l) ;

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
int isvariable(char *);
struct tnode *talloc(void);
char *strdup1(char *);
int k;                                                  // number of characters to check

char *type[]={
    "int",
    "char",
    "float",
    "void"
};

#define TYPE (sizeof type/sizeof type[0])

struct tnode{               // the tree node
    char *word[10];         // array for group of identical names
    int count;              // number of occurences
    struct tnode *left;     // left child
    struct tnode *right;    // right child

};

// word frequency count
main(int argc, char *argv[])
{
    extern int k;
    k = atoi(argv[1]);
    struct tnode *root;
    char word[MAXWORD];

    root=NULL;
    while(isvariable(word) != EOF)
        if(isalpha(word[0]))        
            root = addtree(root, word);
    treeprint(root);
    return 0;
}


// isvariable: check if is variable or not
int isvariable(char *w)
{
    int r;
    r = getword(w, MAXWORD);
    for(int i=0; i<TYPE; i++)
        if(strcmp(w, type[i])==0)
            r = getword(w, MAXWORD);
    
    return r;
            
}


//addtree: add a node with w, at or below p
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond, cond2;
    extern int k;

    if(p==NULL){                // a new word has arrived
        p=talloc();             // make a new node
        p->word[0]=strdup1(w);  // first word of the group
        p->count=1;
        p->left = p->right = NULL;
    } else if ((cond2 = strncmp(w, p->word[0], k) == 0)){       // is compared with the first k charcters of the first word of group
        p->word[p->count]=strdup1(w);                           // word is identical in first k characters is added in the same group
        p->count++;             
       
    }
    else if ((cond = strcmp(w, p->word[0])) < 0){          // less than into left subtree
        p->left = addtree(p->left, w);                     // if not identical word is added into the next node
    }
    else if (cond > 0)                        // greater than into right subtree
        p->right = addtree(p->right, w);      // if not identical word is added into the next node
    return p;

}


// treeprint: in-order print of tree p
void treeprint(struct tnode *p)
{
    if(p!=NULL){
        treeprint(p->left);
        for(int i=0; i<p->count; i++)
            printf("%4d %s\n", p->count, p->word[i]);
        putchar('\n');
        treeprint(p->right);
    }
}


#include<stdlib.h>

//talloc: make a tnode
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup1(char *s)   // make a duplicate of s
{
    char *p;

    p = (char *) malloc(strlen(s)+1);  // +1 for \0
    if (p!=NULL)
        strcpy(p,s);
    return p; 
}

int getch(void);
void ungetch(int);

// getword: get next word or chracter from input
int getword(char *word, int lim)
{
    

    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while(isspace(c=getch()))
        ;
    skip('\"', '\"');            // skip strings

    skip('#', '\n');             // skip preprocessor lines

    if (c=='/' && (c=getch())=='*'){     // skip comments
        c=getch();
        while (!(c!='*' && (c=getch())!='/'))
            ;
    }

    if(c!=EOF)
        *w++=c;
    if(!isalpha(c) && c!='_'){
        *w='\0';
        return c;
    }
    for(; --lim>0; w++)
        if(!isalnum(*w=getch())){
            ungetch(*w);
            break; 
        }

    *w = '\0';
    return word[0];

}


// getch-ungetch
#define BUFSIZE 100

int buf[BUFSIZE];      // buffer for getch
int bufp = 0;           // next free position in buf

int getch(void)         // get a possibly(pushed back) character
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}


void ungetch(int c)     // push character back on input
{
    if(bufp>=BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++]=c;
}

