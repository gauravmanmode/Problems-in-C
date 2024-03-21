#include<stdio.h>
void printd(int n);
void itoa(int n, char s[]);
char s[10];
void reverse(char s[]);
main()
{   int n = 123;
    char s[] = "abc";
    reverse(s);
    printf("%s\n",s);

}

void itoa(int n, char s[])
{
   static int i=0;

    if(n < 0){
        s[i++] = '-';
        n = -n;
    }
    if (n/10)
        itoa(n/10,s);
    s[i++]= n%10 +'0';
    s[i]='\0';
}

void printd(int n)
{
    if (n<0){
        putchar('-');
        n = -n;
        }

if (n/10)
    printd(n/10);
putchar(n%10 + '0');

}

#include<string.h>
void reverse(char s[])
{
    static int i=0, j=0;
    if (++i < strlen(s)/2)
        reverse(s);
    s[i++] = s[strlen(s) - i];


}




