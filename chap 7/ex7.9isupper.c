#include<stdio.h>
#define isupper(c) c>65 && c<90 ? 1 : 0

// int isupper(int c)
// {
//     return c-65>0 && 90-c>0 ? 1 : 0;
// }

main()
{
    printf("%d\n", isupper('c'));
}