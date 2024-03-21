#include<stdio.h>
#include<string.h>
#define MAXLINE 1000

int getline1(char *line, int max);

//find: print lines that match pattern from 1st argument
main(int argc, char *argv[])
{
    char line[MAXLINE];
    int found=0;

    if(argc!=2)
        printf("Usage: find pattern");
    else
        while(getline1(line, MAXLINE)>0)
            if(strstr(line, argv[1])!=NULL){
                printf("%s", line);
                found++;
        }

}
//main()
//{
//    char line[MAXLINE];
//    getline1(line, 100);
//    printf("%s", line);
//}
//
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