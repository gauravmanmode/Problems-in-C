#include<stdio.h>
#define MAXLINE 1000

int main()
{
	char s[MAXLINE], c;
	int lim = MAXLINE ;
	for(int i = 0; i < lim - 1; ++i){
		if ((c=getchar()) != '\n'){
			if (c != EOF)
				s[i] = c;
		}
	}

	printf("%s", s);
}
