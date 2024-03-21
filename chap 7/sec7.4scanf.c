#include<stdio.h>
#include<stdlib.h>

// getline: get line into t, return length
int getline1(char t[], int lim)
{
    int c,i;
    i=0;
    while(--lim>0 && (c=getchar()) != EOF && c!='\n')
        t[i++]=c;
    if (c=='\n')
        t[i++]=c;
    t[i]='\0';
    return i;

}
main()
{
    // int n, k;
    // scanf("%d%d", &n, &k);
    // printf("%d%d", n, k);

    char line[100];
    char c;
    float f;
    getline1(line, sizeof(line));
    if (sscanf(line, "%f", &f) == 1)
        printf("%f", f);
    else if (sscanf(line, "%c", &c))
        printf("%c", c);


}

