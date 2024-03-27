#include<unistd.h>


#define EOF -1

// getchar: unbuffered single character version
int getchar(void)
{
    char c;

    return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}

void putchar1(char c)
{
    write(1, &c, 1);

}


main()
{
    int c;
    while((c = getchar())!= EOF)
        putchar1(c);
}
