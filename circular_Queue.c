#include<stdio.h>
#include<stdlib.h>
#define max 10

int Cenqueue(int[] , int , int);
int Cdequeue(int[] , int , int);
void display(int[] , int , int);
int Cpeek(int[] , int);

int main()
{
  int f=-1 , r=-1 , ch ,ele;
  int cq[max];
  do
  {
    printf("\n*****************************");
    printf("\n1.Add_Element\n2.Delete_Element\n3.display\n4.Peek\n");
    printf("\nEnter Choice\t");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1 :r = Cenqueue(cq , f , r);
                if(f==-1)
                   f=0 ;
                break;
        case 2 : f = Cdequeue(cq , f , r);
                if(f==-1)
                  r=-1 ;
                 break;
        case 3 :  display(cq , f, r);
                  break;
        case 4 : ele = Cpeek(cq,f);
                  if(ele!=-1)
                    printf("\nPeekeed element = %d",ele);
                 break;

    }
  }while(ch<=4 && ch>0);
return 0 ;
}

int Cenqueue(int cq[] , int f , int r)
{
  if((r+1) % max == f)
  {
    printf("\nOverFlow\n");
  }
  else{
    int n ;
    printf("\nEnter the element\t");
    scanf("%d",&n);
    r = (r+1)%max ;
    cq[r] = n ;
    printf("\nElement inserted\n");
  }
  return r ;
}


int Cdequeue(int cq[] ,int f ,int r)
{
  if(f==-1)
    printf("\nQueue is Empty---\n");
  else if(f==r)
   {
    int x = cq[f];
    printf("\nDeleted element = %d",x);
    f = -1 ;
   }else
   {
    int x = cq[f];
    f = (f+1)%max ;
    printf("\nDeleted element = %d",x);
   }
   return f ;
}

void display(int cq[] , int f , int r)
{
    if(f==-1)
      printf("\nQueue is Empty----\n");
    else{
        printf("\n Circular Queue*****\n");
        while(f != r)
        {
            printf("%d ",cq[f]);
            f = (f+1) % max ;
        }
        printf("%d ",cq[f]);
    }
}

int Cpeek(int cq[] , int f)
{
  if(f==-1){
    printf("\nQueue is empty-------\n");
    return -1 ;
  }

   return cq[f];
}