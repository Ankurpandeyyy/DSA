#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data ;
  struct node *next ;
}node ;

node *front = NULL ; 

node* enqueue(node* , int);
void dequeue();
void display();

int main()
{
  node *rear = NULL ;
  int ch , n , ele ;
  do
  {
    printf("\n*****************************");
    printf("\n1.Add_Element\n2.Delete_Element\n3.display\n4.EXIT()\n");
    printf("\nEnter Choice\t");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1 :printf("\nEnter data for Inserting\t");
                scanf("%d",&n); 
                rear = enqueue(rear,n);
                break;
        case 2 : dequeue();
                if(front==NULL)
                    rear = NULL ;
                 break;
        case 3 : display();
                 break;

    }
  }while(ch<=3 && ch>0);
return 0 ;
}

node* enqueue(node* rear , int n)
{
    node* newnode = (node*)malloc(sizeof(node));
    if(newnode)
    {
        newnode->data = n ;
        newnode->next = NULL;
    }

    if(front==NULL)
    {
        front = newnode ;
        rear = newnode ;
    }else{
         rear->next = newnode ;
         rear = newnode ;
    }
    return rear ;
}

void dequeue()
{
    if(front == NULL)
    {
        printf("\nThere is nothing to delete-------\n");
    }
    else{
        node* tmp = front ;
        front =front->next ;
        printf("\nDeleted Element = %d",tmp->data);
        free(tmp);
    }
}

void display()
{
    if(front == NULL)
     printf("Queue is Empty");
    else{
       node* tmp = front ;
       while(tmp != NULL)
        {
          printf("%d ",tmp->data);
          tmp = tmp->next ;
        }
    }

}