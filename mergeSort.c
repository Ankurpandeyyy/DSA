#include<stdio.h>
#define max 50 

void mergesort(int[] , int , int);
void merge(int [], int , int, int);

int main()
{
 int arr[max],n ;
 printf("\nEnter range of array\t");
 scanf("%d",&n);

 printf("\nEnter array elements\n");
 for(int i=0 ; i<n ; i++)
    scanf("%d",&arr[i]);
 
 mergesort(arr , 0 , n-1);
 printf("\nSORTED ARRAY\n");
 for(int i=0 ; i<n ; i++)
    printf("%d ",arr[i]);
    
    return 0 ;
}

void mergesort(int a[] , int start , int end)
{
   int mid ;
   if(start < end)
   {
      mid = (start+end)/2 ;
      mergesort(a,start,mid);
      mergesort(a,mid+1,end);

      merge(a,start,mid,end);
   }
}

void merge(int a[] , int start , int mid , int end)
{
    int tmp[max];
    int i=start , j=mid+1 , k=0; 

    while(i<=mid && j<=end)
    {
        if(a[i] < a[j])
              tmp[k++] = a[i++];
        else
              tmp[k++]=a[j++];
    }

    while(i<=mid)
    {
        tmp[k++]=a[i++];
    }

    while(j<=end)
    {
        tmp[k++]=a[j++];
    }
     
    k=0;
    for(int i=start ; i<=end ; i++)
    {
        a[i] = tmp[k++];
    }
}