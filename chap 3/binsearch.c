#include<stdio.h>
int binsearch(int x, int v[], int n);
main()
{
    int v[10];
    for (int i = 0; i <= 9; ++i)
        v[i] = i + 3;
    printf("%d", binsearch(9, v, 10));

}
/* modified binserach */

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while(low < high) {
        printf("%d ",mid = (low + high) / 2);
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (mid)
        return mid;
    else
        return -1;

}

/*

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while(low <= high) {
        printf("%d, ",mid = (low + high) / 2);
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;

}
*/
