#include<stdio.h>

// struct _flags{
//     unsigned int READ : 1;
//     unsigned int WRITE : 1;
//     unsigned int ERR : 1;
// };

// main()
// {
//     // struct _flags flag = {0,1};
//     // printf("%d", flag.ERR);
//     int i = 0;
//     while (i++ < 27){
//         putchar('x');
//     }

// }

struct new{
    char a;
    double b;
};

main()
{
    struct new t;
    printf("%d", sizeof(t));
    //read(0, (char *) &t, sizeof(t));
    printf("%c", t.b);
}