#include<stdio.h>
void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);

main()
{
    int v[3];
    v[0]=3;
    v[1]=2;
    v[2]=1;
    qsort(v, 0, 2);
    for(int i=0; i<3; i++)
        printf("%d", v[i]);
}
// qsort: sort in increasing order v[left] ... v[right]
void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int, int);

    if(left>=right)     // do nothing if the array contains
        return;         // less than two elements
    swap(v, left, (left+right)/2); // move partition elem to v[0]
    last = left;
    for(i =left+1; i<=right; i++)
        if(v[i]<v[left])
            swap(v, ++last, i);
    swap(v, last, left);    // restore partition elem
    qsort(v, left, last-1);
    qsort(v, last+1, right);

}
void swap(int v[], int i, int j)
{
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;

}//
// Created by ghm on 19/1/24.
//
