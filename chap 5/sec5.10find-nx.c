#include<stdio.h>
#include<string.h>
#define MAXLINE 1000
int getline1(char *, int);

main(int argc, char *argv[])
{
    char line[MAXLINE];
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
    if(argc!=1)
        printf("Usage: find -n -x pattern\n");
    else
        while(getline1(line, MAXLINE)>0) {
            lineno++;
            if((strstr(line, *argv)!=NULL)!=except){
                if(number)
                    printf("%ld  ", lineno);
                printf("%s", line);
                found++;
            }
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