
#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAXWORD 100
#define MAX 10

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
struct tnode *talloc(void);
char *strdup1(char *);
int lineno = 0;                                             // current line number

struct tnode{               // the tree node
    char *word;             // points to the text
    int count;              // number of occurences
    int lines[10];
    struct tnode *left;     // left child
    struct tnode *right;    // right child

};

#define NNWORDS 5
char *noisewords[NNWORDS]={
    "the",
    "and",
    "to",
    "for",
    "is"
};

// word frequency count
main()
{

   // printf("%s", noisewords[0]);
    struct tnode *root;
    char word[MAXWORD];

    root=NULL;
    while(getword(word, MAXWORD) != EOF)
        if(isalpha(word[0]))        
            root = addtree(root, word);
    treeprint(root);
    return 0;
}



//addtree: add a node with w, at or below p
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if(p==NULL){                // a new word has arrived
        p=talloc();             // make a new node
        p->word=strdup1(w);
        p->lines[0]=lineno;
        p->count=1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0){
        p->lines[p->count]=lineno;                          // add line number
        p->count++;             // repeated word
    }
    else if (cond < 0)          // less than into left subtree
        p->left = addtree(p->left, w);
    else                        // greater than into right subtree
        p->right = addtree(p->right, w);
    return p;

}


// treeprint: in-order print of tree p
void treeprint(struct tnode *p)
{
    if(p!=NULL){
        treeprint(p->left);
        printf("%10s",p->word);
        for(int i=0; i<p->count; i++)                           // print line numbers
            printf(" %2d,", p->lines[i] + 1);
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

    while(isspace(c=getch())){                                          
        if(c=='\n')                                                           // count number of lines
            lineno++;
        ;
    }

    if(c!=EOF)
        *w++=c;
    if(!isalpha(c)){
        *w='\0';
        return c;
    }
    for(; --lim>0; w++)
        if(!isalnum(*w=getch())){
            ungetch(*w);
            break;
        }

    *w = '\0';
   // printf("%s\n", word);
    for(int i=0; i<NNWORDS; i++)                                              // filter out noise words                       
        if(strcmp(word, noisewords[i]) == 0)
                word[0]='!';                                                     // non alpha-numeric
    
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

