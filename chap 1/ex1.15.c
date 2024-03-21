#include<stdio.h>

/* fahr to celsius conversion */

float celsiusof(float fahr);

main()
{	
	printf("fahr to celsius conv\n");
	for(int i = 0; i <= 300; i = i + 20)
		printf("%3d\t%6.1f\n", i, celsiusof(i));
		return 0;

}

float celsiusof(float fahr)
{	
	float celsius = (5.0/9.0)*(fahr - 32);
	return celsius;

}