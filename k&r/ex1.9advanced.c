 #include<stdio.h>

/* replace multiple blank by single in line v2  */

main()
 {

 	int c;
 	char k = ' ' ;

 	while ((c=getchar()) != EOF){
 		if (k != ' ' || c != ' ')
 			putchar(c);
 		k=c;
 	}
 	
 }
