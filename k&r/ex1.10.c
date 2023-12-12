 #include<stdio.h>

/* replace tab backspace and backslash by \t \d \\ in line  */

main()
 {

 	int c;

 	while ((c=getchar()) != EOF){
 		char b = 0;
 		if (c == '\t'){
 			putchar('/');
 			putchar('t');
 			b=1;}
 		if (c == '\b'){
 			putchar('/');
 			putchar('b');
 			b=1;}
 		if (c == '\\'){
 			putchar('/');
 			putchar('/');
 			b=1;}
 		if ( b == 0)
 			putchar(c);
 	}

 	
 }
