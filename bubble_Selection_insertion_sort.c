#include<stdio.h>

main()
{
    
    int a[7] = {30,20,10,45,23,66,44};
    int n=7 ;

    // printf("\nBubble sort\n");
    // for(int i=0 ; i<n ; i++)
    // {
    //     for(int j=0 ; j<n-i-1 ; j++)
    //     {
    //         if(a[j]>a[j+1])
    //         {
    //             int t = a[j];
    //             a[j] = a[j+1];
    //             a[j+1] = t ;
    //         }
    //     }
    // }


    // printf("\nSelection sort\n");
    // for(int i=0 ; i<n-1 ; i++)
    // {
    //     int min = i;
    //     for(int j=i+1 ; j<n ; j++)
    //     {
    //        if(a[min]>a[j])
    //        {
    //         min = j;
    //        }
    //     }
    //     int t= a[i];
    //     a[i] = a[min] ;
    //     a[min] = t ;
    // }


    printf("\nInsertion Sort\n");
    for(int i=1 ; i<n ; i++)
    {
        int key = a[i];
        int j = i-1 ;
        while(j>=0 && key<a[j])
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key ;
    }

    for(int i=0 ; i<n ; i++)
    {
        printf("%d ",a[i]);
    }
}