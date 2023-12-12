#include<stdio.h>

#define IN 1	
#define OUT 0
#define MAX 20

/* vertical histogram of length of words */

main()
{
	int c, state, i;
	int nword[MAX];

	for (i=0; i < MAX; ++i)
		nword[i]=0;

	i=0;
	state = OUT;
	while((c = getchar()) != EOF){
		++nword[i];
		if (c == ' ' || c == '\n' || c == '\t'){
			state = OUT;
			--nword[i];
			++i;
		}
		else if (state == OUT){
			state=IN;
		}

	}

	for (i = 0; i < MAX; ++i)
		printf(" \n\n %d", nword[i]); 

	for (int j = MAX; j > 0; --j){
		putchar('\n');
		for (i= 0; i < MAX; ++i){
			if (j - nword[i] > 0)
				putchar(' ');
			else
				putchar('|');


		}
	}



}