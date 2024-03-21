#include<stdio.h>
#include<ctype.h>
void shellsort(int v[], int n);
main()
{
    int v[10];
    for (int i = 0; i < 10; ++i)
        printf("%d", v[i] = 10 - i);
    putchar('\n');
    shellsort(v, 10);
    for (int i = 0; i < 10; ++i)
        printf("%d", v[i]);

}
void shellsort(int v[], int n)
{
    int i, j, gap, temp;
    for(gap = n/2; gap > 0; gap/=2)
        for(i = gap; i < n; i++)
            for(j=i-gap; j>=0 && v[j]>v[j + gap]; j-=gap){
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }

}
