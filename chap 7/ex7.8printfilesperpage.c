#include<stdio.h>
#include<stdlib.h>
#define MAXLINE 1000

main(int argc, char *argv[])
{
    FILE *fp;
    char line[MAXLINE];
    int pagecount = 0;

    system("date");
    while(--argc > 0 && (fp = fopen(*++argv, "r")) != NULL){
        printf("\n\t\t %s page %d \t \t \n", *argv, ++pagecount);
        while(fgets(line, MAXLINE, fp) != NULL)
            fputs(line, stdout);
    }
    if(argc != 0){
        printf("\nerror: unable to open file %s ", *argv);
        return 0;
    }

}