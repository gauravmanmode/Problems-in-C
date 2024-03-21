#include<stdio.h>

#define TABSTOPS 4
#define MAXLINE 1000

int detab(char line[], int maxline);

/* here, char s[] is line buffer of size TABSTOPS  */

/* entab */
main()
{
	int i, space = 0;
	char c;
	char s[TABSTOPS];

	for (int i = 0; (s[i] = getchar()) != EOF; ++i){
		if (s[i] == ' '){
			++space;
			if (s[TABSTOPS - 1] == ' ' && space > 0){
				putchar('t');
				s[TABSTOPS - 1] = '0';
			}
		}

		else{
			while(space > 0){
				putchar('0');
				--space;
				}
			putchar(s[i]);
		}


		if (i == TABSTOPS - 1){
			i = space = 0;
			}

	}

}

