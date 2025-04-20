#include<stdio.h>
void main()
{
     int a[] = {11,22,33,44,55,66,77,88,99,112,224,336,408,600,702};
     int len = 15 , ele , i ;
     printf("Enter element to Search----");
     scanf("%d",&ele);
     i = binarywithRecursion(a , ele , 0 , 14);

     if(i!=-1)
       printf("Element found at index %d", i);
     else
        printf("Element NOT FOUND");
}
 int binarywithRecursion(int a[] , int ele , int b , int e)
{
    int mid;
    if(b > e)
      return -1 ;
    mid = (b + e)/2 ;
     
     if(ele == a[mid])
       return mid ;

    else if(ele > a[mid])
       binarywithRecursion(a , ele , mid+1 ,e);

    else
       binarywithRecursion(a , ele , b , mid-1);
}