#include<stdio.h>

#define IN 1	
#define OUT 0

/* histogram of length of words */

main()
{
	int c, state;

	state = OUT;
	while((c = getchar()) != EOF){
		putchar('-');
		if (c == ' ' || c == '\n' || c == '\t'){
			state = OUT;
			putchar('\b');
			putchar('\n');
			
			
		}
		else if (state == OUT){
			state= IN ;


		}
	}
}