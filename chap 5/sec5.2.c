#include<stdio.h>
void swap (int *px, int *py)
{
    int temp;
    temp = *px;
    *px =*py;
    *py = temp;

}

main()
{
    int a =3, b=5;
    swap(&a, &b);
    printf("%d %d", a ,b);
}