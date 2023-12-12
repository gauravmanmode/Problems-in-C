#include<stdio.h>
#define IN 1
#define OUT 0
#define YES 1
#define NO 0
#define VALID 2
/* does not work for ))( types also some problems with "" string */
/* check for syntax errors */
main()
{	
	char c, prevc;
	int incomment, instring, incharconst, escape;
	int paren, brack, brace;
	int charconstlength = 0;
	paren = brack = brace = 0;

	incomment = OUT;
	instring = OUT;
	incharconst = OUT;
	prevc = getchar();
	escape = NO;

	while ((c=getchar()) != EOF){

		if (incomment == OUT){
			
			if (instring == OUT){
				if (c == '(')
					++paren;
				else if (c == '[')
					++brack;
				else if (c=='{')
					++brace;
				else if (c == ')')
					--paren;
				else if (c==']')
					--brace;
				else if (c == '}')
					--brack;
			}
			else if (instring == IN || incharconst == IN){
				if (prevc == '\\' && c == '"' || c == '\'')
					escape = YES;
				else if (prevc == '\\' && c == '\n' || c == '\b' || c == '\t' || c == '\\')
					escape = VALID;
				else if (prevc == '\\')
					printf("\n invalid escape sequence %c ", c);

			}

			if (escape == NO && c == '\"'){
				if (instring == IN)
					instring = OUT;
				else 
					instring = IN;
			}
			if (incharconst == IN)
				++charconstlength;
			if (escape == NO && c == '\''){
				if (incharconst == IN){
					incharconst = OUT;
					if (charconstlength > 0)
						printf("\n character constant too long for its length");
					charconstlength = 0;
				}
				else 
					incharconst = IN;
				}
		}
			


		if (instring == OUT){
			if (prevc == '/' && c == '*' ){			
				incomment = IN;
				
			}
			else if (prevc == '*' && c == '/'){
				incomment = OUT;
			}

		}

		prevc = c;

	/*	printf(" %c %d ", c, instring); */

	}

	if(incomment == IN)
		printf("\n unterminated comment");
	if(instring == IN)
		printf("\n missing terminating \" charcter ");

	printf("\nunbalanced: parenthesis %d | brackets %d | braces %d ", paren, brack, brace); 
	return 0;
}
