#include<stdio.h>
void main()
{
    int a[50],i,n,sum=0,avg=0,k=0,temp=0;
    printf("enter range\n");
    scanf("%d",&n);
    printf("Enter elements\n");
    for(int i=0;i<n;i++)
       scanf("%d",&a[i]);

     printf("NEW OBTAINED ARRAY\n");
  for(i=0;i<n;i++)
     {
        for(int j=i+1;j<n;j++)
        {
           if(a[i] > a[j])
             {
               temp = a[i];
               a[i] = a[j];
               a[j] = temp;
             }
        }
     
     printf("%d\n",a[i]);   
     }
    printf("MAXIMUM VALUE = %d\n",a[n-1]);
     printf("MINIIMUM VALUE = %d\n",a[0]);
    printf("Second largest Element will be=%d \t",a[n-2]);
}