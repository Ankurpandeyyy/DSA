#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data ;
    struct node *next;
}sll;

sll* createLinkList(sll *);
void display(sll *); 
sll* removeduplicate(sll *);

int main()
{
    int ch ;
    sll *head = NULL;
    do{
        printf("\n-------------------\n\t");
        printf("\n1. createLinklList 1\n2. displayLL \n3. remove_duplicates\n\n");
        printf("Enter your Choice\t");
        scanf("%d",&ch);

        switch(ch)
        {
           case 1 :head = createLinkList(head);
                     break ;
           case 2 : display(head);
                    break ;
           case 3 : head = removeduplicate(head);
                    display(head);
                    break ;
        }
    }while(ch<=3 && ch > 0);
}

sll* createLinkList(sll *head)
{
    sll *newnode = (sll *)malloc(sizeof(sll));
    if(newnode)
    {
        int n ;
        printf("\nEnter the data to insert\t");
        scanf("%d",&n);
        newnode->data = n ;
        newnode->next = NULL ;
    }
    if(head == NULL)
    {
        head = newnode ;
    }
    else{
        sll *tmp = head  ; 
        while( tmp->next != NULL )
        {  
            tmp = tmp ->next ;
        }
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

sll* removeduplicate(sll *head)
{
    if(head == NULL)
    {
        printf("\nEmpty List ");
        
    }else{
        sll* current = head ;

        while(current != NULL)
        {
            sll *tmp = current ;
            while(tmp->next != NULL )
            {
                if(current->data == tmp->next->data )
                  {
                    sll *dup = tmp->next ;
                    tmp->next = dup->next ;
                    dup->next = NULL ;
                    free(dup);
                  }
                  else{
                    tmp = tmp->next ;
                  }
            }
            current = current->next ;
        }
    }
    return head ;
}