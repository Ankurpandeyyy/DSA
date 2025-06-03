#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data ;
    struct node *next;
}sll;

sll* createLinkList(sll *);
void display(sll *); 
sll* merge(sll * , sll * , sll*);

int main()
{
    int ch ;
    sll *head1 = NULL;
    sll *head2 = NULL ; 
    sll *head = NULL ;
    do{
        printf("\n-------------------\n\t");
        printf("\n1. createLinklList 1\n2. Create LinkList 2\n3. displayLL 1\n4. displayLL 2\n5. MergeLinkList\n\n");
        printf("Enter your Choice\t");
        scanf("%d",&ch);

        switch(ch)
        {
           case 1 :head1 = createLinkList(head1);
                     break ;
           case 2 :head2 = createLinkList(head2);
                     break ;
           case 3 : display(head1);
                      break;
           case 4 : display(head2);
                      break;
           case 5 :head = merge(head1 , head2 , head);
                   display(head);
                   break ;
        }
    }while(ch<=5 && ch > 0);
}

sll* createLinkList(sll *head)
{
    sll *newnode = (sll*)malloc(sizeof(sll));
    if(newnode)
    {
        int n ;
        printf("\nEnter the data to insert\t");
        scanf("%d",&n);
        newnode->data = n ;
        newnode->next = NULL ;
    }
    if(head == NULL || newnode->data < head->data)
    {
        newnode->next = head ;
        head = newnode ;
    }
    else{
        sll *tmp = head  ;
        
        while( tmp->next != NULL && tmp->next->data < newnode->data)
        {  
            tmp = tmp ->next ;
        }
         newnode -> next = tmp->next ;
         tmp->next = newnode ;
    }
    return head ;
}

void display(sll *head)
{
    if(head == NULL)
      {
        printf("\n list is empty\n");
        return ;
      }
    else{
        sll *tmp = head ;
        while(tmp != NULL)
        {
            printf("%d - > ",tmp->data);
            tmp = tmp->next ;
        }
        printf(" NULL");
    }
}

sll* merge(sll *head1 , sll* head2 , sll* head)
{
    
    if(head1 == NULL || head2 == NULL)
    {
        printf("\nthere must be elements in both linked list for merging\n");
        return head ;
    }
    else{
        head = head1 ;
       
        sll *p = head2 ;
     
        while(p != NULL)
        {
          sll *node = p ;
          p = p->next;
          node->next = NULL ;
          if(node->data < head ->data)
          {
            node ->next = head ;
            head = node ;
          }else{
             sll *t = head ;
             while(t->next != NULL && t->next->data < node->data)
             {
                t = t->next;
             }
             node ->next = t->next ;
             t->next = node ;
          }     
        }
    }
    return head ;   
}

