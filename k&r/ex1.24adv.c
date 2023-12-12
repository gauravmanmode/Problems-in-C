#include<stdio.h>
#define IN 1
#define OUT 0
#define YES 1
#define NO 0
#define VALID 2
#define MAX 100

/*gets location only for (() not for ))(   */
/* check for syntax errors */
main()
{	
	char c, prevc;
	int incomment, instring, escape;
	int paren, brack, brace;
	paren = brack = brace = 0;
	int parenloc[MAX];
	int charno, lineno;
	charno = lineno = 0;

	incomment = OUT;
	instring = OUT;
	prevc = getchar();

	while ((c=getchar()) != EOF){


		if (incomment == OUT){
			
			if (instring == OUT){
				if (c == '('){
					++paren;	
					parenloc[paren] = (100 * lineno) + charno;
					}
				else if (c == '[')
					++brack;
				else if (c=='{')
					++brace;
				else if (c == ')'){
					parenloc[paren];
					--paren;
					}
				else if (c==']')
					--brace;
				else if (c == '}')
					--brack;
			}
			else if (instring == IN){
				if (prevc == '\\' && c == '\"' || c == '\'' )
					escape = YES;
				else if (prevc == '\\' && c == '\n' || c == '\b' || c == '\t' || c == '\\')
					escape = VALID;

			}

			if (c == '"' || c == '\'' && escape == NO){
				if (instring == IN)
					instring = OUT;
				else 
					instring = IN;
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
		++charno;
		if (c == '\n'){
			++lineno;
			charno = 0;
		}
			printf(" %c %d ", c, charno); 
	}

	printf(" %d \n", paren);
	printf("%d %d %d ", paren, brack, brace); 
	while(paren > 0){
		printf(" %d ", parenloc[paren]);
		--paren;
	}
	return 0;
}
