 #include<stdio.h>

/* ount characters in input */

main()
 {
 	long nc;

 	nc=0;
 	while (getchar() !=EOF)
 		++nc;
 	printf("%ld\n",nc);
 }