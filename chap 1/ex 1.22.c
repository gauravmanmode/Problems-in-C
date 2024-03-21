#include<stdio.h>

#define TABWIDTH 4
#define COLUMNSIZE 8
#define MAXLINE 1000

int detab(char line[], int maxline);



/* fold long input lines */
main()
{	
	int i,j= 0;
	char s[COLUMNSIZE + 2];

	for (i = 0; (s[i] = getchar()) != EOF; ++i){
		if (s[i] == '\t'){
			j = i;
			while(i < TABWIDTH){
					s[i] = ' ';
				}
		}
		else{
		++j;
		}
		if (j == TABWIDTH)
			j = 0;

		if (i == COLUMNSIZE - 1){
			while(s[i] == ' ')
				--i;
			s[i + 1] = '\n';
			s[i + 2] = '\0';

			printf("%s",s);
			i = -1;
		}
	}
	s[i] = '\0';
	printf("%s",s);
}
