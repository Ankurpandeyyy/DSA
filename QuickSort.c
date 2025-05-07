#include <stdio.h>

int partition(int a[] , int l , int h)
{
  int i,j,k,f=1 ;
  
  i=l+1 ;
  j = h ;
  k = a[l];

  while(f)
  {
    while(k > a[i] && i<=j)
    {
        i++;
    }
    while (k < a[j])
    {
        j--;
    }
    if(i<j)
    {
        int t=a[i];
        a[i] = a[j];
        a[j] = t ;
    }else
       f=0 ;
    
  }

  a[l] = a[j];
  a[j]=k ;

  return j ;
  
}

void quickSort(int a[] , int l , int h)
{
  int p ;
  if(l <= h)
  {
    p = partition(a,l,h);
    quickSort(a,l,p-1);
    quickSort(a , p+1 , h);
  }
}

int main()
 {
   
    int arr[100];
     int n ;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int l = 0 , h = n-1 ;
    quickSort(arr , l , h); 

    printf("\nSorted array\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
         }

         return 0 ;
 }