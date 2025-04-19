#include<stdio.h>
void main()
{
    int i,num,count=0;
    printf("enter number for checking its prime or not\n");
    scanf("%d",&num);

    for(i=2;i<num;i++)
    {
        if(num%i == 0)
        {
            count++;
        }
    }
    if(count == 0)
    printf("%d is prime number",num);
    else
    printf("%d is not a prime number\n",num);
}