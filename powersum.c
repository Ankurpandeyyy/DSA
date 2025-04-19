#include<stdio.h>
void main()
{
    int i, j, sum=0 , p = 1, n ;
    printf("enter the value of n\n");
    scanf("%d",&n);

    for(i=1 ; i<=n ; i++)
    {
        p = 1 ;
        for(j=1 ; j<=i ; j++)
        {
            p = p * i ;
        }
        sum = sum + p ;
    }
    printf("sum = %d ",sum);
}