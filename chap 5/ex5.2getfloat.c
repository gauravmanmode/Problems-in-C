#include<stdio.h>
#include<ctype.h>
#define SIZE 50
#define printarr(s) {for(int i=0; i<SIZE; i++)      \
                        printf("%g,   ", s[i]);         \
}


int getch(void);
void ungetch(int);


main()
{
    int n, getfloat(float *pn);
    float array[SIZE];
    for(n=0; n<SIZE && getfloat(&array[n]) != EOF; n++)
        ;
    printarr(array)
}
// getint: get next integer from input
int getfloat(float *pn)
{
    int c, sign;
    float p;

    while(isspace(c=getch()))           // skip white space
        ;
    if(!isdigit(c) && c!= EOF && c!= '-' && c!= '+') {
        ungetch(c);                     // not a number
        putchar('-');
        return -1;
    }
    sign = (c == '-') ? -1 : 1;
    if (c=='+' || c=='-')
        c=getch();
    if (!isdigit(c))
        return 0;
    for(*pn=0; isdigit(c); c=getch())
        *pn=10* *pn + (c-'0');
    if (c=='.')
        c=getch();
    for(p=1; isdigit(c); c=getch()) {
        *pn = 10 * *pn + (c - '0');
        p*=10;
    }
    *pn = (*pn * sign) / p ;
    if (c!=EOF)
        ungetch(c);
    return c;

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

