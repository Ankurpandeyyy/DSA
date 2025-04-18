#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data ;
  struct node *next ;
}node ;

node* insertatright(node* , int);
node* insertatleft(node*,int);
void display(node*);
node* delete(node* , int);
node* insertatindex(node*,int);
void sortusingselectionsort(node*);
void sortusingbubblesort(node*);
void sortusinginsertionsort(node*);
void reverse(node*);
int countnodes(node*);


int main()
{
  node *head = NULL ;
  int ch , n , c=0;
  do
  {
    printf("\n*****************************");
    printf("\n1.Insert_At_Right\n2.Insert_At_Left\n3.Display\n4.Delete\n5.insert_at_index\n6.selection_sort\n7.Bubble_sort\n8.reverse\n9.TotalNodes\n10.exit()\n");
    printf("\nEnter Choice\t");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1 : printf("\nEnter data to insert\t");
                 scanf("%d",&n);
                 head = insertatright(head,n);
                 break;
        case 2 : printf("\nEnter data to insert\t");
                 scanf("%d",&n);
                 head = insertatleft(head,n);
                  break;
        case 3 : display(head);
                 break;
        case 4 : printf("\nEnter data to delete from linked list\t");
                 scanf("%d",&n);
                 head = delete(head , n);
                 break;
        case 5 : printf("\nEnter data to insert\t");
                   scanf("%d",&n);
                  head = insertatindex(head , n);
                  break;
        case 6 : sortusingselectionsort(head);
                  break;
        case 7 : sortusingbubblesort(head);
                 break;
        case 8 : reverse(head);
                break;
        case 9 : c = countnodes(head);
                 printf("\nTotal Nodes = %d",c);
                      break;
    }
  } while (ch<=10 && ch > 0);
    return 0 ;
}

node* insertatright(node* head , int n)
{
   node *newnode = (node*)malloc(sizeof(node));
   if(newnode)
   {
    newnode->data = n ;
    newnode->next = NULL ;
   }

   if(head == NULL)
   {
    head = newnode ; 
   }else{
    node *tmp = head ;
    while(tmp->next!=NULL)
    {
        tmp = tmp->next ;
    }
    tmp->next = newnode ;
   }
   return head ;
}

node* insertatleft(node* head , int n)
{
   node *newnode = (node*)malloc(sizeof(node));
   if(newnode)
   {
    newnode->data = n ;
    newnode->next = NULL ;
   }

   if(head == NULL)
   {
    head = newnode ; 
   }else{
    newnode->next = head ;
    head = newnode ;
   }
   return head ;
}

void display(node *head)
{
    if(head == NULL)
    {
        printf("\nLink List is empty--------\n");
        return ;
    }
    printf("\nCreated Linked List----------\n");
    int count=0;
    node* tmp = head ;
    while(tmp!=NULL)
    {
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
}

int countnodes(node* head)
{
  node* tmp = head ;
  int count=0 ;
  while(tmp!=NULL)
  {
    count++;
    tmp = tmp->next;
  }
  return count ;
}

node* delete(node* head , int n)
{
    if(head == NULL)
    {
        printf("\nLink List is empty--------\n");
    }
    node *tmp = head ;
    if(tmp->data == n)
    {
        head = head->next ;
        free(tmp);
    }
    else{
        node* prev = head ;
        while(tmp->data != n)
        {
            prev = tmp;
            tmp= tmp->next ;
        }
        prev->next = tmp->next ;
        free(tmp);
    }
    return head ;
}

node* insertatindex(node* head ,int n )
{
    display(head);
    node* newnode = (node*)malloc(sizeof(node));
    if(newnode)
    {
        newnode->data = n ;
        newnode->next= NULL;
    }
    int idx ;
    printf("\nEnter the index in which you want to insert a node\t");
    scanf("%d",&idx);
    
    node *prev = head ;
    for(int i=0 ; i<idx-1 ; i++)
    {
        prev = prev->next ;
    }
    newnode->next = prev->next ;
    prev->next = newnode ;

    display(head);
    
    return head ;
}

void sortusingselectionsort(node* head)
{
    if(head == NULL)
      {
        printf("Empty Linked List\n");
        return ;
      }
     node *tmp = head ;
    for(node* i=tmp ;i->next!=NULL ; i=i->next)
    {
        node* min = i ;
        {
            for(node* j=i->next ; j!=NULL ; j=j->next)
            {
                if(min->data > j->data)
                   min = j ;
            }

            if(min != i)
            {
                int t = min->data ;
                min->data = i->data ;
                i->data = t ;
            }
        }
    }
    node *traverse = tmp ;

    while(traverse != NULL)
    {
        printf("%d ",traverse->data);
        traverse = traverse->next ;
    }
    
}

void sortusingbubblesort(node* head)
{
  if(head == NULL)
   {
    printf("Linked list is empty");
    return ;
   }

  int n = countnodes(head);
   for(int i=0 ; i<n-1 ; i++ )
   {
     node *t = head ;
     for(int j=0 ; j<n-i-1 ; j++)
     {
        if(t->data > t->next->data)
        {
            int temp = t->data ;
            t->data = t->next->data ;
            t->next->data = temp ;
        }
        t=t->next;
     }
     
   }

   node *tmp = head ;

    while(tmp != NULL)
    {
        printf("%d ",tmp->data);
        tmp = tmp->next ;
    }
}

void reverse(node* head)
{
    if(head == NULL)
      {
        printf("\nEmpty inked List");
        return ;
      }
      node* prev = NULL;
      node* current = head;
      node* next = NULL;
  
      while (current != NULL) {
          next = current->next;   // Save next
          current->next = prev;   // Reverse current node's pointer
          prev = current;         // Move prev to current
          current = next;         // Move to next node
      }
  
      node *tmp = prev ;
      while(tmp != NULL)
    {
        printf("%d ",tmp->data);
        tmp = tmp->next ;
    }
}


