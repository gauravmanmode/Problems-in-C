#include<stdio.h>
#include<string.h>
struct nlist *lookup(char *);
struct nlist *install(char *, char *);
void undef(char *, char *);

struct nlist{                           // table entry
    struct nlist *next;                 // next entry in chain
    char *name;                         // defined name
    char *defn;                         // replacement text

};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];     // pointer table

main(){
    install("IN", "1");
    install ("hello", "hey");
    undef("hello", "hey");
    struct nlist *np= lookup("hello");
    printf("%d\n", np);



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

// undef: remove a name and defn from table
void undef(char *name, char *defn)
{
    struct nlist *np, *prevnp = NULL;
    for (np = hashtab[hash(name)]; np != NULL; np = np->next){                  // find name in table
        if(strcmp(name, np->name) == 0){
            if (prevnp == NULL)                                                 // if it is the last block
                hashtab[hash(name)] = NULL;                                         // pointer in hash index points to NULL
            else                                                                // else
                prevnp->next = np->next;                                        // point to the next block
            }                                         
        prevnp = np;
    }

    free((void *) np);                                                          // free up the name defn block
    
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
