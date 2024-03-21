#include<stdio.h>
#define MAXLINE 1000
int getline(char line[], int maxline);
void reverse(char s[]);

main()
{	
	int len;
	char line[MAXLINE];
	while (getline(line,MAXLINE) > 0){
		reverse(line);
		printf("%s", line);
	}
}

void reverse(char s[])
{
	/* length of s */
	int i;
	for (i = 0; s[i] != '\0'; ++i)
		;
	int len = i - 2;
	char temp;
	for (i = 0; i <= len / 2 ; ++i){
		temp = s[i];
		s[i] = s[len - i];
		s[len - i] = temp;
	}


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