#include<stdio.h>
#include<string.h>
void ungets(char s[]);
int getch(void);
void ungetch(int);

main()
{
    char s[12] = "hello world";
    ungets(s);
    int k;
    while(k=getch())
        printf("  %c",k );



}


// getch-ungetch
#define BUFSIZE 100

char buf[BUFSIZE];      // buffer for getch
int bufp = 0;           // next free position in stack

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


// ungets:push back an entire string on input
void ungets(char s[])
{
    int i=strlen(s);
    while(i--)
        ungetch(s[i]);
}