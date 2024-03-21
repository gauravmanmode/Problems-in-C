#include<stdio.h>

main()
{
	char s[10] = "123456";
	atoi(s);
	printf("%d", atoi(s));

}

/* atoi: convert s to integer */
int atoi(char s[])
{
	int n, i;
	n = 0;
	for(i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;


}