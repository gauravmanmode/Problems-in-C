#include<stdio.h>
int strend2(char *, char *);
void strcat1(char *, char *);
main()
{
    char a[50] = "giarvaragugav";
    char b[] = "raugav";
//    strcat1(a,b);
    printf("%d", strend2(a, b));
}


// strcat: concatenate t to end of s , s must be big enough
void strcat1(char *s, char *t)
{
    while(*s++!='\0')
        ;
    s--;
    while((*s++=*t++)!='\0');
}

// strend: returns 1 if t occurs at the end of s, otherwise zero
int strend1(char *s, char *t)
{
    int i=0;

    for(i=0; *(s+i)!='\0'; i++)
        for(int k=0; *(s+i+k)==*(t+k) && *(t+k)!='\0'; k++)
            if(*(t+k+1)=='\0')
                return 1;
    return 0;
}


// strend: v2
int strend2(char *s, char *t)
{
    int len=0;

    while(*s !='\0')                // go to end of s
        s++;
    s--;
    while(*t != '\0') {             // go to end of t , find len of t
        t++;
        len += 1;
    }
    t--;
    while(*s-- == *t--)             // check from backwards
        len--;

    if (len == 0)                   // if len t matches, return 1
        return 1;
    return 0;


}


