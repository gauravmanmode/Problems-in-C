#include<stdio.h>
#include<stdlib.h>
int getch(void);
void ungetch(int);

main()
{
    int c = EOF;
    ungetch(c);
    printf("%d\n", getch());



}


// getch-ungetch
#define BUFSIZE 100
// replace unsigned char by int as unsigned char cannot store -1
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

