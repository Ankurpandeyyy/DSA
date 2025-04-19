#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *prev,*next;
} *start = NULL;
void display()
{
    struct node *temp;
    temp = start;
    while(temp!=NULL)
    {
        printf("\t %d",temp->data);
        temp= temp->next;
    }
}
void insertatbeg()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d",&newnode->data);
    newnode->prev = newnode->next = NULL;

    if(start == NULL)
    {
        start = newnode ;
    }
    else
    {
      newnode -> next = start;
      start -> prev = newnode ;
      start = newnode;
    }
}
void insertatend()
{
    struct node *newnode,*temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&newnode->data);
    newnode->next = newnode->prev = NULL ;
    if(start == NULL)
    {
        start = newnode;
    }
    else
    {
      temp = start;
      while(temp->next != NULL)
      {
        temp = temp -> next ;
      }
      temp->next = newnode;
      newnode->prev = temp;
    }
}
void insertbeforenode()
{
    struct node *newnode , *tmp , *ptr;
    int c ;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data of newnode\t");
    scanf("%d",&newnode->data);
    newnode->next = newnode->prev = NULL ;
    printf("Enter the data before u want to insert a node\t");
    scanf("%d",&c);
    if(start->data == c)
    {
        start -> prev = newnode ;
        newnode -> next = start ;
        start = newnode ;
    }
    else
    {
        tmp = start ;
        while(tmp->data != c)
        {
            ptr = tmp ;
            tmp = tmp->next ;
        }
        newnode->next = tmp ;
        ptr->next = newnode ;
        tmp->prev = newnode ;
        newnode->prev = ptr ;
    }
}
void insertafternode()
{
    struct node *newnode , *tmp , *ptr;
    int c ;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data of newnode\t");
    scanf("%d",&newnode->data);
    newnode->next = newnode->prev = NULL ;
    printf("Enter the data after u want to insert a node\t");
    scanf("%d",&c);
    if(start->data == c)
    {
        tmp = start ;
        tmp = tmp->next ;
        start->next = newnode ;
        newnode->prev = start ;
        newnode->next = tmp ;
        tmp->prev = newnode ;
    }
    else
    {
        tmp = start ;
        while(tmp->data != c)
        {
            tmp = tmp->next ;
        }
        newnode->next = tmp->next ;
        tmp->next = newnode ;
        newnode->prev = tmp ;
        
    }
}
void delete()
{
    if(start->data == NULL)
       printf("LIST IS EMPTY!!!!!!\n");
       
    struct node *tmp, *ptr;
    int c ;
    printf("enter the data you want to delete\n");
    scanf("%d",&c);
    if(start->data == c)
    {
     tmp = start ;
     start = start->next ;
     tmp->next = NULL ;
     free(tmp);
    }
    else
    {
        tmp = start ;
    while(tmp->data != c )
    {
        ptr = tmp ;
        tmp = tmp->next;
    }
     ptr->next = tmp->next ;
     tmp->next = tmp->prev = NULL ;
     free(tmp);
    }
}
void display_rev()
{
    struct node *ptr;
    ptr = start;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    while(ptr != NULL)
    {
        printf("\t %d",ptr->data);
        ptr = ptr->prev;
    }
}
void main()
{
   int ch;
   char s[1];
   struct node *temp;
 do
 {
    printf("\n press 1-> Insertatbeg, 2->insert at end , 3->display_rev press4->display, 5->insertbeforenode, 6->insertafternode,7->delete\t");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: insertatbeg();
                break;
        case 2: insertatend();
                break;
        case 3: display_rev();
                break;
        case 4: display();
                break;
        case 5: insertbeforenode();
                break ;
        case 6: insertafternode();
                break;
        case 7: delete();
                break;
        default: printf("\n WRONG CHOICE");
    }
    printf("\tpress y for continue and n for exit\n");
    scanf("%s",&s);

 } while ((strcmp(s,"Y"))== 0 || (strcmp(s,"y")==0));
 
}