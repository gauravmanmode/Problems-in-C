#include <stdio.h>
int any(char s1[], char s2[]);
int main() {

    char s1[7] = "0x123f";
    char s2[7] = "12";

    printf("%d", any(s1, s2) );
    return 0;
}
/*squeeze: delete all c from s*/
int any(char s1[], char s2[])
{
    int i, k, found;
    found = 0;
    for(k = 0; s2[k] != '\0' && found == 0 ; ++k) {
        for (i = 0; s1[i] != '\0' && found == 0; i++)
            if (s1[i] == s2[k])
                found = 1;
    }
    return i-1;
}//
// Created by ghm on 1/12/24.
//
//
// Created by ghm on 1/12/24.
//
