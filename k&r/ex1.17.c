#include<stdio.h>
#define MAXLINE 10  /* maximum input line size */
int getline(char line[], int maxline);
void copy(char to[], char from[]);


/* print longest input line v2  */
main()
{
	int len; /* current line length */
	int overflow = 0;
	char line[MAXLINE];  /* current input line */

	while((len = getline(line, MAXLINE)) > 0){
		if ((len == MAXLINE - 1) && line[MAXLINE - 2] != '\n'){					/* arbitrarily long line */
			overflow += 1;
			len = overflow * (MAXLINE - 1);
		}
		else if (overflow > 0){
			len = overflow * (MAXLINE - 1) + len - 1;
			overflow = 0;		
		}

		if (len >= 80)
			printf("\n%s", line);
	}
	
	return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}