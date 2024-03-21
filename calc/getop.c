// getop: get next operator or numeric operand
#include<ctype.h>
#include<stdio.h>
#include "calc.h"
extern int currvar;

// ex 4.11 modify getop so it doesnt need to use ungetch
/*

int getop(char s[])
{
    int i, c;

    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (isupper(c) || c=='r') {
        currvar = c;
        return VARIABLE;
    }
    if (!isdigit(c) && c!= ' ' && c!= '-')
        return c;
    else if (c=='-' && isdigit(c=getch()))
        ungetch(c);
    else if (!isdigit(c)) {
        ungetch(c);
        return '-';
    }

    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()));   // collect integer part
    if (c == '.')
        while (isdigit(s[++i] = c = getch()));  // collect fraction part
    s[i] = '\0';
    if (c!= EOF)
        ungetch(c);
    return NUMBER;
}
*/

// pointer version
int getop(char *s) {
    int c;
    while ((*s = c = getch()) == ' ' || c == '\t');
    *(++s) = '\0';

    if (isupper(c) || c == 'r') {
        currvar = c;
        return VARIABLE;
    }
    if (!isdigit(c) && c != ' ' && c != '-')
        return c;
    else if (c == '-' && isdigit(c = getch()))
        ungetch(c);
    else if (!isdigit(c)) {
        ungetch(c);
        return '-';
    }

    if (isdigit(c))
        while (isdigit(*s++ = c = getch()));   // collect integer part
    if (c == '.')
        while (isdigit(*s++ = c = getch()));  // collect fraction part
    *s = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;

}

