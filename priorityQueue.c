#include<stdio.h>

#define MAX 10 

int enqueue(int [] , int );
void dequeue(int [] , int);
void display(int [] , int);

int main()
{
    int pq[MAX] , r = 0 , ch ;
     do{
        printf("\n******************\n\n");
        printf("1.EnQueue\n2.DeQueue\n3.Display\n");
        printf("Enter your choice\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : r = enqueue(pq, r);
                     break ;
            case 2 : dequeue(pq , r);
                     break ;
            case 3 : display(pq , r);
                     break;
                     
        }
    }while(ch<=3 && ch>0);

    return 0;
}

int enqueue(int pq[] , int r )
{
   if(r == MAX)
      {
        printf("\n Overflow\n");
        
      }

    else{
        int p , v ;
        printf("\nEnter priority and value for inserting\n");
        scanf("%d%d",&p,&v);

        pq[r] = p ;
        pq[r+1] = v ;
        r = r+ 2 ;
    }

    return r ;
}

void display(int pq[] , int r)
{
    int hasdata = 0 ;
        printf("\nRequired Priority Queue\n");

          for (int i = 0; i < r; i += 2)
            {
                 if (pq[i] != 999)
                    {
                        printf("\t%d-%d\t", pq[i], pq[i + 1]);
                        hasdata = 1 ;
                    }
            }
    
    if(hasdata==0)
      {
        printf("\nNothing to show,,,Queue is empty--------\n");
        return ;
      }

}

void dequeue(int pq[] ,int r)
{
    int j=-1;

    if(r==0)
      {
        printf("\nUnderflow\n");
        return;
      }
      else{
        int min = 999;
        
        for(int i=0 ; i<r-1 ; i+=2)
        {
            if(pq[i]!=999)
            {
                if(min > pq[i])
                {
                    min = pq[i];
                    j = i ;
                }
            }
        }
        if(j==-1)
        {
            printf("\nAll elements are deleted--------\n");
            return ;

        }
        printf("\nHighest priority element\n");
        printf("\npriority\tvalue\n");
        printf("%d\t\t%d\n",pq[j],pq[j+1]);

        pq[j] = 999 ;
        pq[j+1] = -1 ;
        
      }
     
}

