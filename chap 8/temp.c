#include<stdio.h>

struct _flags{
    unsigned int READ : 1;
    unsigned int WRITE : 1;
    unsigned int ERR : 1;
};

main()
{
    struct _flags flag = {0,1};
    printf("%d", flag.ERR);
}.