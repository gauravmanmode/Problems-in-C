#include <stdio.h>
void squeeze(char s[], int c);
int main() {

    char s[7] = "0x123f";
    squeeze(s, '1');
    printf("%s", s );
    return 0;
}
/*squeeze: delete all c from s*/
void squeeze(char s[], int c)
{
    int i, j;

    for(i = j = 0; s[i] != '\0'; ++i)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}//
// Created by ghm on 1/12/24.
//
