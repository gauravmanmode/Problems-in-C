#include<stdio.h>
int strlen(char s[]);

int main()
{
	 
}


/*strlen; return length of  s*/
int strlen(char s[])
{
	int i;

	i = 0;
	while(s[i] != '\0')
		++i;
	return i;.
}