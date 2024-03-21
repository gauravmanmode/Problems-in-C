#include<stdio.h>
#include<ctype.h>
void reverse(char *);
int strindex1(char *s, char *t);
main()
{
    char a[]="hellheyo";
    char *b = "hey";
//    reverse(a);
  //  printf("%d", strindex1(a,b));
    *b++='2';
    b--;
    printf("%s", b);
}

/*

int getline(char *s, int MAXLINE)
{
    int c, i;
    i=0;
    char *origs=s;
    while(--lim>0 && (c=getchar())!=EOF && c!='\n')
        *s++=c;
    if(c=='/n')
        *s++=c;
    *s='\0';
    return s - origs;

}

int atoi(char *s)
{
    int val;
    int sign;

    for(; isspace(*s); s++)                  // skip white space
        ;
    sign = (*s=='-') ? -1 : 1;
    if(*s=='-' || *s=='+')
        s++;
    for(val=0; isdigit(*s); s++)
        val=10*val+(*s-'0');
    return val;

}

void itoa(int n , char *s)
{
    int sign;
    unsigned int k;
    if((sign=n)<0)
        k=-n;
    do{
        *s++=n%10+'0';
    }while((n/=10)>0);
    if(sign<0)
        *s++='-';
    *s='\0';

}
*/


void reverse(char *s)
{
    int c;
    char *start=s;
    while(*s!='\0')
        s++;
    s--;
    char *end=s;

    for(int len=(end-start)/2; len>0; len--) {
        c = *start;
        *start = *end;
        *end = c;
        start++;
        end--;
    }
    }


//strindex: return index of t in s , -1 if none
int strindex1(char *s, char *t)
{
    char *ts;                                   // where t starts in s
    char *ot=t;                                 // points to starting of t
    char *os=s;                                 // satrrting of s
    for(; *s!='\0'; s++){
        for(ts=s, t=ot; *t!='\0' && *ts==*t; ts++,t++)
            ;
        if((t-ot)>0 && *t=='\0')
            return s-os;
    }
    return -1;

}

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
        while (isdigit(*(++s) = c = getch()));   // collect integer part
    if (c == '.')
        while (isdigit(*(++s) = c = getch()));  // collect fraction part
    *s = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;

}











}