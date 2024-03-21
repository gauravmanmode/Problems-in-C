#include<stdio.h>

main()
{
    typedef int Length;
    typedef int Integer;
    Length a;
    Integer b;



    typedef char *String;
    String p = "hello"; 
   // printf("%s", p);

    // typedef strcut tnode *Treeptr;
    // typedef strcut tnode{
    //     char *word;             // points to the text
    //     int count;              // number of occurences
    //     Trreptr left;           // left child
    //     Treeptr right;          // right child
    // } Treenode;

    // typedef int (*PFI)(char *, char *);

    // PFI strcmp, numcmp;

    union u_tag{
        int ival;
        float fval;
        char *sval;
    } u = {.fval={9.0}}; 
    u.ival = 3;
   // u.fval=5.0;
   // u.ival = 6;


    printf("%d %f\n", u.ival, u.fval);
