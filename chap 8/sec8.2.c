#include<stdio.h>
#include<unistd.h>
#define BUFSIZ 10
main()      // copy input to output
{
    ///printf("hello");
char buf[BUFSIZ];
int n;

while((n = read(0, buf, BUFSIZ)) > 0){
    printf("%d\n", n);
    write(1, buf, n);
}
return 0;

}
