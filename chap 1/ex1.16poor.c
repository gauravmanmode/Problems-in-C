#include<stdio.h>
#define MAXLINE 10  /* maximum input line size but forgot that last charcter itself indicates newline */

int getline(char line[], int maxline);
void copy(char to[], char from[]);


/* print longest input line */
main()
{
	int len; /* current line length */
	int max, omax;  /* maximum length seen so far */
	int newmax = 0;  /* store overflow max */
	int overflow = 0; 
	char line[MAXLINE];  /* current input line */
	char longest[MAXLINE]; /* longest line saved here */

	max = 0;
	while((len = getline(line, MAXLINE)) > 0){
		if (len == MAXLINE - 1 ){
		overflow += 1;
		omax = overflow * ( MAXLINE - 1 );
		if (omax > max)
			max = omax;
		}
		else if (overflow > 0 ){
		omax = overflow * ( MAXLINE - 1 )  + len -1 ;
		if (omax > max)
			max = omax;
		overflow = 0;
		copy(longest, line);

		}		
		else if (len < MAXLINE - 1){
			if (len > max){
				max = len;
				copy(longest, line);

			}
		}
		

	}
	if (max > 0) 	/* there was a line */
		printf("%s %d %d", longest, max, omax);
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
	s[i] == '\0';
	return i;
}

/* copy: copy 'from' into 'to' */
void copy(char to[], char from[])
{
	int i;

	i=0;
	while ((to[i] = from[i]) != '\0' )
	++i;

}