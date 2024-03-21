#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAXWORD 100
#define HASHSIZE 101
int record(char *);
void replace(char *);
int getword(char *, int);
int getword1(char *word, int lim);
struct nlist *lookup(char *);
struct nlist *install(char *, char *);
char *strdup1(char *);

struct nlist{                           // table entry
    struct nlist *next;                 // next entry in chain
    char *name;                         // defined name
    char *defn;                         // replacement text

};

static struct nlist *hashtab[HASHSIZE];     // pointer table

// #define processor: simple implementation 
main(){
    char word[MAXWORD];
    
    while(record(word) > 0);                // get all #defines
   // install ("hello", "hey"); 
    printf("\n done\n ");
    while(getword(word, MAXWORD) != EOF){
         // printf(" $%s$ ", word); 
         if (isalpha(word[0]))              // as name has same form as variable name
             replace(word);                  
    }

}

// getword with output also
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while(isspace(c=getch()))
        putchar(c);

    if(c!=EOF)
        *w++=c;
    if(!isalpha(c)){
        *w='\0';
        putchar(c);
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

int getch(void);
void ungetch(int);

// record: get #defines
int record(char *word)
{
    int c;
    char name[MAXWORD], defn[MAXWORD];
    while(isspace(c=getch()))                       // skip spaces
        ;       
    if(c == '#'){                                   // if starts with #
        getword1(word, MAXWORD);
        if(strcmp(word, "define") == 0){            // and is a define             
            getword1(name, MAXWORD);
            getword1(defn, MAXWORD);
            install(name, defn);
           // printf("%s%s", name, defn);
        }
        return 1;                                   // check again                                          
    }
    else{
        ungetch(c);
        return 0;                                   // do not check
    }
}

// getword without output
int getword1(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while(isspace(c=getch()))
        ;

    if(c!=EOF)
        *w++=c;
    if(!isalnum(c)){
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

// #define processor: replace names with replacement text
void replace(char *name)
{
    struct nlist *np;
    np = lookup(name); 
    if(np == NULL)                          // if is not in table
        printf("%s", name);                 // print as it is
    else                                    // else
        printf("%s", np->defn);             // replace text

}


// hash: form hash value from string s
unsigned hash(char *s)
{
    unsigned hashval;

    for(hashval=0; *s!='\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

// lookup: look for s in hashtab
struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np=hashtab[hash(s)]; np!=NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;                    // found
    return NULL;                          // not found

}

struct nlist *lookup(char *);
char *strdup1(char *);

// install: put (name, defn) in hashtab
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL){                // not found
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup1(name)) == NULL)            // no space or empty string
            return NULL;
        hashval = hash(name);                               // calculate index in array of pointer
        np->next = hashtab[hashval];                         // np->next points to old one  (for first one NULL)
        hashtab[hashval] = np;                              // pointer in hashtab points to latest block 
    } else  // already there
        free((void *) np->defn);
    if ((np->defn = strdup1(defn)) == NULL)
        return NULL;
    return np;
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

 

