#include<stdio.h>
#define max 10 

void quick_sort(int[] , int , int);

main()
{
    int a[max];
    int i, n ;

    printf("Enter the range of array\t");
    scanf("%d",&n);

    printf("Enter %d elements of array",n);

    for(i=0 ; i<n ; i++)
       scanf("%d",&a[i]);

    quick_sort(a,0,n-1);
    printf("\nSorted Array\n");
    for(i=0 ; i<n ; i++)
       printf("%d ",a[i]);
}

void quick_sort(int a[] , int lb , int ub)
{
    int i=lb , j=ub , key = a[lb] , t=0 ;

    while(lb >= ub)
       return ;

    while(i<j)
    {
        while(key >= a[i] && i<j)
             i++;
        while(key < a[j])
             j--;

        if(i<j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t ;
        }
    }

    a[lb] = a[j];
    a[j] = key ;

    quick_sort(a , lb , j-1);
    quick_sort(a ,j+1 , ub);
}