#include<stdio.h>

main()
{

/*
    #define KEYWORD 1
    #define EXTERNAL 2
    #define STATIC 4
    static char flags;
    //flags |= EXTERNAL;          // turn on external
    //flags &= ~STATIC;           // turn off static
    flags |= STATIC;
    flags &= ~EXTERNAL;

  //  if((flags & EXTERNAL) == 0)
  //      printf("%s", "not external");

    */

    struct {
        unsigned int is_keyword : 1;
        unsigned int is_extern : 2;
        unsigned int is_static : 1;
    } flags;

    flags.is_extern=3;
    flags.is_static=0;
  
    if(flags.is_static == 0)
        printf("%s", "isstatic not");

    

}