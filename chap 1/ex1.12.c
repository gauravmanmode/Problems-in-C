#include<stdio.h>

/* count lines, words and characters in input  */


#define IN 1     /* inside a word */
#define OUT 0	 /* outside a word */


main()
 {

 	int c, nl, nw, nc;
 	int state;

 	state = OUT;
 	nl=nw=nc=0;

 	while((c=getchar()) != EOF){
 		putchar(c);
 		if (c == ' ' || c == '\n' || c == '\t'){
 			state = OUT;
 			putchar('\n');
 			}
 		else if (state == OUT)
 			state = IN;
 			 
		

	}
	




 }


