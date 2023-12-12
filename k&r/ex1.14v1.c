#include<stdio.h>

#define IN 1	
#define OUT 0
#define MAX 200

/*  histogram of different characters */

main()
{
	int c, i, j, k;
	int nchar[MAX];
	char ch[MAX];
	int found=0;

	for (i=0; i < MAX; ++i)				/* initialize nchar */
		nchar[i]=0;

	for (i=0; i < MAX; ++i)
		ch[i]=0;

	i = j = 0;

	while((c = getchar()) != EOF){

		for (int i=0; i <= j; ++i){						/* check and add char */
			if (ch[i]==c){		
				++nchar[i];
				++found;
			}	
		}

		if (found==0){
			ch[j]=c;
			++nchar[j];
			++j;
		}	

		found=0;

	}

/*	printf("%d", j);									debug

	for (i=0; i < j; ++i)
		printf("  %c %d ", ch[i], nchar[i] );

*/


	for (i = 0; i < j; ++i){							/* print histogram */

		printf(" \n  %c ", ch[i]);
		for(k = 0; k < nchar[i]; ++k)
			putchar('-');   
	}



}
 