#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLINE 1000
int getline1(char *, int);

main(int argc, char *argv[])
{
    FILE *fp;
    char line[MAXLINE];
    char *pattern;
    long lineno;
    int c, except=0, number=0, found=0;

    while(--argc>0 && (*++argv)[0] == '-')
        while(c = *++argv[0])
            switch(c){
            case 'x':
                except=1;
                break;
            case 'n':
                number=1;
                break;
            default:
                printf("find: illegal option %c\n", c);
                argc=0;
                found=-1;
                break;
        }
    if(argc == 0){
        printf("Usage: find -n -x pattern\n");
        exit(0);
    }


    pattern = *argv;
    argc--;
    if (argc == 0){                                                              // no file in argument
        fp = stdin;
        goto run;
    }
    for(; argc-- > 0; ){                                                        // for named files
        if ((fp = fopen(*++argv, "r")) == NULL){
            fprintf(stderr, "unable to open file%s\n", *argv);
            exit(1);
        }

        run:
            lineno = 0;
            while(fgets(line, MAXLINE, fp) != NULL) {
                lineno++;
                if((strstr(line, pattern)!=NULL)!=except){
                    if(number)
                        printf("%ld  ", lineno);
                    printf("%s", line);
                    found++;
                }
            }
            fclose(fp);
    }
    return found;


}



int getline1(char *s, int lim)
{
    char*os = s;                            // original pointer
    int c;
    while(--lim>0 && (c=getchar())!=EOF && c!= '\n')
        *s++=c;
    if(c=='\n')
        *s++=c;
    *s='\0';
    return s - os;

}