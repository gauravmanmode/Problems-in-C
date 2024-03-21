#include<stdio.h>
int bitcount(unsigned x);
main()
{
    printf("%d", bitcount(9));

}
/*modified bitcount */
int bitcount(unsigned x)
{
    int b;

    for(b = 0; x != 0; x &= x - 1)
        ++b;

    return b;

}
/*
int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= (x - 1))
        if (x & 01)
            b++;
    return b;

}
*/