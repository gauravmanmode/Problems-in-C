#include<stdio.h>

int power();

/* power function  version 2 */

main()
{
	int i;
/*
	for(i= 0; i < 10; ++i)
		printf("%d %d %3d \n", i, power(2,i), power(-3,i));
	return 0;
*/
	
	printf("%d %3d \n", power(2,0), power(3,2));

}

/* power: raise base to nth power n>=0 */

int power(int base, int n)

{
	int p;

	for(p = 2; n > 0; --n)
		p = p * base;
		return p;

}