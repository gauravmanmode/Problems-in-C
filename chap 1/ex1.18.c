#include<stdio.h>
#define MAXLINE 1000  /* maximum input line size */
int getline(char line[], int maxline);
void copy(char to[], char from[]);


/* print longest input line v2  */
main()
{
	int len; /* current line length */
	char line[MAXLINE];  /* current input line */

	while((len = getline(line, MAXLINE)) > 0){

		if (line[0] == '\n')
			line[0] = '\0';
		else{
			while(line[len - 1] == ' ' || line[len - 1] == '\t' || line[len - 1] == '\n')
				--len;
			line[len] = '\n';
			line[len + 1] = '\0';
		}
		

		printf("%s", line);
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