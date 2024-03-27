#include<unistd.h>
#include<stdio.h>

// getchar: simple buffered version
int getchar1(void)
{
    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n;

    if (n == 0){     // buffer is empty
        n = read(0, buf, sizeof buf);
        bufp = buf;
    }

    return --n >= 0 ? (unsigned char) *bufp++ : EOF;
}

 
main()
{
    int c;
    while((c = getchar())!= EOF)
        putchar(c);
}
