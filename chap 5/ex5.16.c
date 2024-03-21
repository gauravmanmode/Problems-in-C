#include<stdio.h>
#include<string.h>
#define MAXLINES 5000           // max lines to be sorted
char *lineptr[MAXLINES];        // pointers to text lines

int readlines(char *lineptr[], int nlines);
void writelines(char * lineptr[], int nlines);

void qsort1(void *lineptr[], int left, int right, int (*comp)(void *, void *), int order);
int numcmp(char *, char *);
int strcmp1(char *, char *);
int fold;                       
//sort input lines
main(int argc, char *argv[])
{
    int nlines;                 // number of input lines
    int numeric =0;             // 1 if numeric sort
    int order=1;                // -1 if reverse
    fold=0;          // 1 for case-insensitive
    char c;

    while(--argc>0 && (*++argv)[0] == '-')
        while(c = *++argv[0]){
            switch(c){
            case 'n':
                numeric=1;
                break;
            case 'r':
                order=-1;
                break;
            case 'f':
                fold=1;
                break;
            case 'd':
                break;              
            default:
            printf("sort: illegal option %c \n", c);
            break;

            }
    
    }
       
    if((nlines=readlines(lineptr, MAXLINES)) >= 0){
        qsort1((void **) lineptr, 0, nlines-1, (int (*)(void*, void*))(numeric ? numcmp : strcmp1), order);
        writelines(lineptr, nlines);
        return 0;
    }
    else{
        printf("input too big to sort /n");
        return -1;
    }

}

//qsort
void qsort1(void *v[], int left, int right, int (*comp)(void *, void *), int order)
{
    int i, last;
    void swap(void *v[], int, int);

    if(left>=right)                 // do nothing if less than two elements
        return;
    swap(v, left, (left+right)/2);
    last=left;
    for(i=left+1; i<=right; i++)
        if(order*(*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort1(v, left, last-1, comp, order);
    qsort1(v, last+1, right, comp, order);
}

#include<stdlib.h>

//numcmp: compare s1 and s2 numerically
int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1=atof(s1);
    v2=atof(s2);
    if(v1<v2)
        return -1;
    else if(v1>v2)
        return 1;
    else return 0;
}

//strcmp
int strcmp1(char *s, char *t)
{
    int i;
    extern int fold;
    char casediff;sort
    
    casediff=fold ? 'A'-'a' : 0;
    
    for( ; *s==*t || *s==casediff+ *t;  s++,t++)
        if (*s =='\0')
            return 0;
    return *s - *t;

}



void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i]=v[j];
    v[j]=temp;

}


#define MAXLEN 1000                                 // max length of input line
int getline1(char *, int);
char *alloc(int);

// readlines: read input lines
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines=0;
    while((len=getline1(line, MAXLEN)) > 0){
        if(nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else{
            line[len-1]='\0';                       // delete newline
            strcpy(p, line);
            lineptr[nlines++] = p;

        }
    }
    return nlines;
}

// writelines: write output lines
void writelines(char *lineptr[], int nlines)
{
    while(nlines-- > 0)
        printf("\n%s", *lineptr++);
    putchar('\n');

}

// getline: get input line into s
int getline1(char *s, int lim)
{
    char *os=s;
    int c;
    while(--lim>0 && (c=getchar())!=EOF && c!='\n')
        *s++=c;
    if(c=='\n')
        *s++=c;
    *s='\0';
    return s-os;
}

#define ALLOCSIZE 10000                             // size of available space
static char allocbuf[ALLOCSIZE];                    // storage for alloc
static char *allocp=allocbuf;                        // next free position

char *alloc(int n)                            // return pointer to n characters
{
    if(allocbuf+ALLOCSIZE-allocp > n) {       // it fits
        allocp += n;
        return allocp - n;          // old p
    }
    else                            // not enough room
        return 0;
}





