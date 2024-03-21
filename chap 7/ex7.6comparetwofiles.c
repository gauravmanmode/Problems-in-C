#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000

main(int argc, char *argv[])
{
    if (argc != 3){
        printf("comp: two args required");
        return 0;
    }

    FILE *fp1, *fp2;
    char s[MAX], t[MAX];
    
    if ((fp1 = fopen(*++argv, "r")) == NULL){                                          // or else opened
        fprintf(stderr, "unable to open file %s\n", *argv);
        return -1;
    }
    if ((fp2 = fopen(*++argv, "r")) == NULL){
        fprintf(stderr, "unable to open file %s\n", *argv);
        return -2;
    }

    while(strcmp(fgets(s, MAX, fp1), fgets(t, MAX, fp2)) == 0)
        ;
    printf("%s", s);                                                                   // print differed line

    fclose(fp1);                                                                       // clean up
    fclose(fp2);



        
    
}
