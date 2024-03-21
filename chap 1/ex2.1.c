#include<stdio.h>
#include<limits.h>
#include<float.h>

/*ranges of data types*/
main()
{
	printf("range of char %d to %d\n", CHAR_MIN, CHAR_MAX );
	printf("range of signed char %d to %d\n", SCHAR_MIN, SCHAR_MAX );
	printf("range of unsigned char %d to %d\n", 0, UCHAR_MAX );

	printf("range of int %d to %d\n", INT_MIN, INT_MAX );
	printf("range of signed int %d to %d\n", INT_MIN, INT_MAX );
	printf("range of unsigned int %d to %u\n", 0, UINT_MAX );

	printf("range of short %d to %d\n", SHRT_MIN, SHRT_MAX );
	printf("range of signed short %d to %d\n", SHRT_MIN, SHRT_MAX );
	printf("range of unsigned short %d to %d\n", 0, USHRT_MAX );

	printf("range of long %d to %u\n", LONG_MIN, LONG_MAX );
	printf("range of signed long %d to %d\n", LONG_MIN, LONG_MAX );
	printf("range of unsigned long %d to %u\n", 0, ULONG_MAX );

	printf("\nrange of float %e to %e\n", FLT_MIN, FLT_MAX );
	printf("range of float exp %d to %u\n", FLT_MIN_EXP, FLT_MAX_EXP );
	printf("range of float %d", FLT_MANT_DIG);

	printf("\n\nrange of double %e to %e\n", DBL_MIN, DBL_MAX );
	printf("range of double exp %d to %u\n", DBL_MIN_EXP, DBL_MAX_EXP );
	printf("range of double %d\n", DBL_MANT_DIG);

	printf("%d %e", FLT_ROUNDS, FLT_EPSILON);
	printf("%d %e", FLT_ROUNDS, FLT_EPSILON);


	char i, max, min  = 0;
	--i;
	while(i < 0){ 
		--i;
		if (i < min)
			min = i;
		}
	printf("\n%d\n", min);

	i = 0;
	++i;
	while(i > 0){
		++i;
		if (i > max)
			max = i;
	}

	printf("\n%d\n", max);

	return 0;
	
}