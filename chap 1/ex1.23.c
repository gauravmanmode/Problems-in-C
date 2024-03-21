#include<stdio.h>

#define IN 1
#define OUT 0 

/* remove comments from C program */
main()
{	
	char c, prevc;
	int state, instring;

	state = OUT;
	instring = OUT;
	prevc = getchar();
	putchar(prevc);
	while ((c=getchar()) != EOF){

		if (state == OUT)
			putchar(c);

		if (c == '"' || c == '\'' ){
			if (instring == IN)
				instring = OUT;
			else 
				instring = IN;
		}

		if (instring == OUT){
			if (prevc == '/' && c == '*' ){			
				printf("\b \b");						/*here is used \b \b which goes one back types space goes one back and makes overwrite*/
				state = IN;
				
			}
			else if (prevc == '*' && c == '/'){
				printf("\b \b");
				state = OUT;
			}

		}

		prevc = c;
	}
	
	return 0;
}
