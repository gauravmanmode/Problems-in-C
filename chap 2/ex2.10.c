#include<stdio.h>
int lower(int c);
main()
{
    printf("%c", lower(getchar()));
}

int lower(int c)
{
    return c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c;
}//
// Created by ghm on 1/13/24.
//
