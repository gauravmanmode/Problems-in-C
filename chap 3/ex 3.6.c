#include<stdio.h>
#include<string.h>
void reverse(char s[]);
void itoa(int n, char s[], int width);
main()
{
    char s2[100];
    itoa(142342345, s2, 6);
    printf("%s", s2);

}

void itoa(int n, char s[], int width)
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do{
        s[i++] = n%10 + '0';
    }while(n/=10);
    if (sign < 0)
        s[i++] = '-';
    while (i < width)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int temp;
    for(int i = 0, j = strlen(s) - 1; s[i] != '\0' && i<j; i++, j--)
        temp = s[j], s[j] = s[i], s[i] = temp;

}