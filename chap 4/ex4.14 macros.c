#include<stdio.h>
#define swap(t,x,y) {   t temp = x;                         \
                        x=y;                                \
                        y=temp; }

#define dprint(expr) printf(#expr " = %g\n", expr)



main()
{
    int x, y;
    dprint(x);
    x=2;
    y=3;
    swap(int,x,y)
    printf("%d %d", x,y);

}
