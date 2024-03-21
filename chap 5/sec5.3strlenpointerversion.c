#include<stdio.h>
#define p(s) printf("%d", s);

main()
{
    char a[] = "hello world";
    char *ip =&a;
    p(strlen(ip))

}

int strlen(char *s)
{
    int n;
    for(n=0; *s!='\0'; s++)
        n++;
    return  n;
}
