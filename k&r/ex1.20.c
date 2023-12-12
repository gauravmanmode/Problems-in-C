#include<stdio.h>

#define TABSTOPS 4
#define MAXLINE 1000

int detab(char line[], int maxline);

/* detab */
main()
{
	int i = 0;
	char c;

	while ((c = getchar()) != EOF ){
			if (c == '\t'){
				while(i < TABSTOPS){
					putchar('0');
					++i;
				}
			}
			else{
				putchar(c);
				++i;
			}
			if (i == TABSTOPS)
				i = 0;
	}

}

