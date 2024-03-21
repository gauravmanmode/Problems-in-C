
#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAXWORD 100
#define MAX 1000
#define skip(k,l) if(c==k) while((c=getch())!=l) ;
struct tnode *addtree(struct tnode *, char *);
void treelist(struct tnode *);
int getword(char *, int);
struct tnode *talloc(void);
char *strdup1(char *);
void qsort1(struct tnode *list[], int, int);
int i=0;

struct tnode{               // the tree node
    char *word;             // points to the text
    int count;              // number of occurences
    struct tnode *left;     // left child
    struct tnode *right;    // right child

};
struct tnode *list[MAX];

// word frequency count
main()
{
    struct tnode *root;
    char word[MAXWORD];

    root=NULL;
    while(getword(word, MAXWORD) != EOF)
        if(isalpha(word[0]))        
            root = addtree(root, word);  
    treelist(root);                                             // print the tree in a list           
    qsort1(list, 0, i-1);                                       // sort with frequency of occurence
    for(int j=i-1; j>=0; j--)                                   // print in decreasing order
        printf("%4d %s\n", list[j]->count, list[j]->word);
    return 0;
}



//addtree: add a node with w, at or below p
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if(p==NULL){                // a new word has arrived
        p=talloc();             // make a new node
        p->word=strdup1(w);
        p->count=1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;             // repeated word
    else if (cond < 0)          // less than into left subtree
        p->left = addtree(p->left, w);
    else                        // greater than into right subtree
        p->right = addtree(p->right, w);
    return p;

}

// treelist: put the tree in a list
void treelist(struct tnode *p)
{
    if(p!=NULL){
        treelist(p->left);
        list[i++]=p;
     // printf("%4d %s\n", p->count, p->word);  
        treelist(p->right);
    }
}

//qsort: sort v[left]...v[right] into increasing order
void qsort1(struct tnode *v[], int left, int right)
{
    int i, last;
    void swap(void *v[], int, int);

    if(left>=right)                 // do nothing if less than two elements
        return;
    swap(v, left, (left+right)/2);
    last=left;
    for(i=left+1; i<=right; i++)
        if(v[i]->count < v[left]->count)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort1(v, left, last-1);
    qsort1(v, last+1, right);
}


#include<stdlib.h>

//talloc: make a tnode
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

// strdup: make a duplicate of s
char *strdup1(char *s)
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
        while (!(c!='*' && (c=getch())!='/'))        // 
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

void swap(void *v[], int i, int j)              // swaps two pointers
{
    void *temp;

    temp = v[i];
    v[i]=v[j];
    v[j]=temp;

}
