#include<stdio.h>
void main()
{
    int i, j, sum=0 , fact = 1, n ;
    printf("enter the number for factorial\n");
    scanf("%d",&n);

    for(i=1 ; i<=n ; i++)
    {
        fact = 1 ;
        for(j=1 ; j<=i ; j++)
        {
            fact = fact * j ;
        }
        sum = sum + fact ;
    }
    printf("sum = %d ",sum);
}