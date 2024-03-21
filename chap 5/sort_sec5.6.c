#include<stdio.h>
#include<string.h>
#define MAXLINES 5000   // max #lines to be stored

char *lineptr[MAXLINES];
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);


// sort: sort input lines
main()
{
    int nlines;                                         // number of input lines read

    if ((nlines=readlines(lineptr, MAXLINES)) >= 0){
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else{
        printf("error: input line too big to sort\n");
        return 1;
    }

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
        printf("\n %s", *lineptr++);

}

// qsort: sort v[left]...v[right] into increasing order
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if(left>=right)                                     // do nothing if array contains
        return;                                         // less than two elements

    swap(v, left, (left+right)/2);
    last=left;
    for(i=left+1; i<=right; i++)
        if(strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);

}


// swap: interchange v[i] & v[j]
void swap(char *v[], int i, int j) {
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;

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






















































































