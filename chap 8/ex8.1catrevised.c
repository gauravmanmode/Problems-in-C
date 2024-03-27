#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

// cat: concatenate files, rewrite with open, read, write, close
main(int argc, char *argv[])
{
    int fd;
    void filecopy(int, int);
    char *prog = argv[0];           // program name for errors

    if (argc == 1)                  // no args: copy standard output
        filecopy(0, 1);
    else
        while (--argc > 0)
            if ((fd = open(*++argv, O_RDONLY, 0)) == -1){
                fprintf(stderr, "%s: can't open %s", prog, *argv);
                exit(1);
            } else {
                filecopy(fd, 1);
                close(fd);                 // close file after done
            }
    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    exit(0);

}

// filecopy: copy file ifp to ofp
void filecopy(int f1, int f2)
{
    int n;
    char buf[BUFSIZ];

    while((n = read(f1, buf, BUFSIZ)) > 0)
        if (write(1, buf, n) != n)
            fprintf(stderr, "error: write error on stdout");
}