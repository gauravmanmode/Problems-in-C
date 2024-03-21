#include <stdio.h>
unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);
int main() {
    printf("%u", rightrot(9,3));
}
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return (x & ~(~(~0 << n) << p + 1 - n) )  |  ( (y &  ~(~0 << n)) << p + 1 - n ) ;
}

unsigned invert(unsigned x, int p, int n)
{
    return setbits(x, p, n, ~getbits(x, p, n));
}

unsigned rightrot(unsigned x, int n)
{
    int k = x;
    int p;
    /* get posn of most significant bit*/
    while(k != 1){
        k = k >> 1;
        ++p;
    }
    return setbits(x, p + n, n, getbits(x, n - 1 , n))  >> n;

}