#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data ;
  struct node *next ;
}node ;

node* push(node*,int);
node* pop(node*);
void display(node*);
int peek(node*);

int main()
{
  node *top = NULL ;
  int ch , n , ele ;
  do
  {
    printf("\n*****************************");
    printf("\n1.push\n2.pop\n3.display\n4.peek\n");
    printf("\nEnter Choice\t");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1 :printf("\nEnter data for Pushing\t");
                scanf("%d",&n); 
                top = push(top,n);
                if(top!=NULL)
                   printf("\nElement pushed in to stack\n");
                break;
        case 2 : top = pop(top);
                 break;
        case 3 : display(top);
                 break;
        case 4 : ele = peek(top);
                 if(ele !=-1)
                   printf("\nPeeked element = %d",ele);
                break;

    }
  }while(ch<=4  && ch>0);

  return 0;
}

node* push(node* top , int n)
{
   node* newnode = (node*)malloc(sizeof(node));
   if(newnode)
     {
        newnode->data = n;
        newnode->next = NULL;
     }
  if(top==NULL)
  {
    top = newnode ;
  }else{
    newnode->next = top ;
    top = newnode ;
  }
   return top ;
}

node *pop(node* top)
{
    if(top==NULL)
      printf("\nStack is empty\n");
    else{
        node* tmp = top ;
        top = top->next ;
        printf("\nPopped Element = %d",tmp->data);
        free(tmp);
    }
    return top ;
}

void display(node *top)
{
    if(top==NULL)
     {
        printf("\nStack is Empty\n");
     }else{
        node *tmp = top;
        printf("\nStack Elements------\n");
        while(tmp!=NULL)
        {
            printf("%d ",tmp->data);
            tmp = tmp->next;
        }
     }
}

int peek(node* top)
{
    if(top==NULL)
    {
        printf("There is nothing to peek in stack\n");
        return -1 ;
    }
    else{
        return top->data ;
    }
}