#include<stdio.h>
#include<string.h>
void reverse(char s[]);
void itob(int n, char s[], int base);
main()
{
    // largest - value 2147483648
    char s2[100];
    itob(12, s2, 2);
    printf("%s", s2);

}
// only for positive numbers for minus just prefic sign
void itob(int n, char s[], int b)
{
    int i, sign, d;

    i = 0;
    do{
        s[i++] = 9 < n%b && n%b <= 16 ? n%b - 10 + 'A' : n%b + '0';
    }while(n/=b);
    if ( sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int temp;
    for(int i = 0, j = strlen(s) - 1; s[i] != '\0' && i<j; i++, j--)
        temp = s[j], s[j] = s[i], s[i] = temp;

}//
// Created by ghm on 1/14/24.
//
