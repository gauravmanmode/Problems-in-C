#include<stdio.h>
#include<ctype.h>
#include<string.h>

// lower: 
main(int argc, char *argv[])
{
    if(strcmp(*argv, "./lower") == 0)
    {
        int c;

        while((c=getchar()) != EOF)
            putchar(tolower(c));

    } else if (strcmp(*argv, "./upper") == 0){

        int c;

        while((c=getchar()) != EOF)
            putchar(toupper(c));

    }

    return 0;
}