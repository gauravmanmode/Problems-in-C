#include<unistd.h>
#include<fcntl.h>

// get: read n bytes from position pos
int get(int fd, long pos, char *buf, int n)
{
    if (lseek(fd, pos, 0) >= 0)             // get to pos
        return read(fd, buf, n);
    else 
        return -1;
}

main()
{
    int fd;
    char buf[100];
    fd = open("a", O_RDONLY, 0);
    int n = get(fd, 5, buf, 7);
    write(1, buf, n);
}