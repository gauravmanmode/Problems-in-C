#include <stdio.h>
void squeeze(char s1[], char s2[]);
int main() {

    char s1[7] = "0x123f";
    char s2[7] = "0x123f";
    squeeze(s1, s2);
    printf("%s", s1 );
    return 0;
}
/*squeeze: delete all c from s*/
void squeeze(char s1[], char s2[])
{
    int i, j, k;
    for(k = 0; s2[k] != '\0'; ++k) {
        for (i = j = 0; s1[i] != '\0'; ++i)
            if (s1[i] != s2[k])
                s1[j++] = s1[i];
    }
    s1[j] = '\0';
}//
// Created by ghm on 1/12/24.
//
