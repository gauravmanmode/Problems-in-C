#include <stdio.h>
void strcat(char s1[], char s2[]);
int main() {

    char s1[7] = "0x123f";
    char s2[7] = "12";
    strcat(s1, s2);
    printf("%s", s1 );
    return 0;
}
/*squeeze: delete all c from s*/
void strcat(char s[], char t[])
{
    int i, j;

    i = j = 0;
    while(s[i] != '\0')
        i++;
    while((s[i++] = t[j++]) != '\0')
        ;
}//
// Created by ghm on 1/13/24.
//
