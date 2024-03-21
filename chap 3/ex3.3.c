#include<stdio.h>
void expand(char s1[], char s2[]);
main()
{
    char s1[20] = "gaurava-z";
    char s2[100];
    expand(s1,s2);
    printf("%s", s2);
}
void expand(char s[], char t[])
{
    int i, j, k  = 0;
    switch(s[i]+s[i+1]-s[i+2]){
        case ('a'+'-'-'z'):
            for(k=0; s[i] + k <= s[i+2]; k++, j++)
                t[j] = s[i] + k;
            break;

    }




}
//
// Created by ghm on 1/13/24.
//
