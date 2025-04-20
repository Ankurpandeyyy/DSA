#include<stdio.h>
void fact(long int);
void main()
{
    long int n1,f;
    printf("Enter the number for factorial\n");
    scanf("%ld",&n1);
    fact(n1);
    
      
}
void fact(long int x)
{
   long int f=1;
   for(int i=1;i<=x;i++)
    {
      f = f * i;  
    }
    printf("factorial is %ld",f);

}
