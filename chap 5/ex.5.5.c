#include<stdio.h>
#define SIZE 50
#define printarrd(s) for(int i=0; i<SIZE; i++) \
                        printf("%d ",s[i] );
char *strncpy1(char *, char *, int);
char *strncat1(char *, char *, int);
int strncmp1(char *, char *, int);
main()
{
    char a[SIZE] = "hel";
    char *b = "heoqy";
 //   printf("%s\n",  strncpy1(a, b, 10) );
  //  printarrd(a);
    printf("%d\n",  strncmp1(a, b, 4) );
}



char *strncpy1(char *s,char *t, int n)
{
    char *origs=s;                          // store original pointer s to return
    while((*s=*t) != '\0' && n>0) {
        s++;
        t++;
        n--;
    }
    while(n--)
        *s++ = '\1';
    return origs;
}

char *strncat1(char *s, char *t, int n)
{
    char *origs=s;                              // store original pointer s to return
    while(*s!='\0')
        s++;
    while((*s=*t)!='\0' && n>0){
        s++;
        t++;
        n--;
    }
    *s='\0';
    return origs;
}

int strncmp1(char *s, char *t, int n)
{
    for(; *s==*t && n>0; s++, t++) {
        n--;
        if (*s == '\0' || n == 0)
            return 0;
    }
    return *s - *t;

}
