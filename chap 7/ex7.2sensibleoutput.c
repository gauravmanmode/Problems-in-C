#include<stdio.h>
#include<string.h>
#define LENGTH 5                                      // line length

main()
{
    int c, length = 0;
    typedef char *String;
    String line;                
    char *l = line;
    for(; (c=getchar())!=EOF; line++)                  // store input in line
        *line=c;
    *line = '\0';
    
    while ((c=*l++) != '\0'){
        length++;
        length%=LENGTH;                                 // 0 after LENGTH
        if(c>=0 && c<=31)                              // non graphic characters in octal
            printf("o0%o", c);
        else if (c>=32 && c<=127)                       // as it is
            printf("%c", c);
        if(c=='\n')                                     // reset length
            length=0;
        if(length==0)                                   // if length print newline
            printf("\n");
    }
    printf("\n");
}