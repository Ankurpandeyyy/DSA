#include<stdio.h>
void main()
{
    int i=1,n,fact=1;
    printf("enter the number for getting factorial\n");
    scanf("%d",&n);
    while(i<=n)
    {
        fact = fact * i;
        i++;
    }
    printf("factorial will be :- %d",fact);
}