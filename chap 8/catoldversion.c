#include<stdio.h>
#include<stdlib.h>

// cat: concatenate files, version 2
main(int argc, char *argv[])
{
    FILE *fp;
    void filecopy(FILE *, FILE *);
    char *prog = argv[0];           // program name for errors

    if (argc == 1)                  // no args: copy standard output
        filecopy(stdin, stdout);
    else
        while (--argc > 0)
            if ((fp = fopen(*++argv, "r")) == NULL){
                fprintf(stderr, "%s: can't open %s", prog, *argv);
                exit(1);
            } else {
                filecopy(fp, stdout);
                fclose(fp);                 // close file after done
            }
    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    exit(0);

}

// filecopy: copy file ifp to ofp
void filecopy(FILE *ifp, FILE *ofp)
{
    int c;

    while((c = getc(ifp)) != EOF)
        putc(c, ofp);
}