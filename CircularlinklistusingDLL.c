#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *next , *prev;
}*start = NULL ;

void insertatbeg()
{
     struct node *newnode, *tmp ;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("ENTER DATA FOR FIRST NODE\t");
    scanf("%d",&newnode->data);
    newnode->next = newnode->prev = NULL ;
    if(start == NULL)
    {
        start = newnode ;
        newnode -> next = newnode->prev = start ;
    }
    else
    {
      tmp = start ;
      while(tmp->next != start)
      {
        tmp = tmp->next ;
      }
      tmp->next = newnode ;
      newnode-> prev = tmp;
      newnode->next = start;
      start->prev = newnode ;
      start = newnode ;
    }
}
void insertatend()
{
    struct node *newnode, *tmp ;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("ENTER DATA FOR LAST NODE\t");
    scanf("%d",&newnode->data);
    newnode->next = newnode->prev = NULL ; 
    if(start == NULL)
    {
        start = newnode ;
        newnode -> next = newnode->prev = start ;
    }
    else
    {
      tmp = start ;
      while(tmp->next != start)
      {
        tmp = tmp->next ;
      }
     tmp->next = newnode ;
     newnode->prev = tmp ;
     newnode -> next = start ;
     }  
}
void display()
{
    struct node *tmp ;
    tmp = start ;
    while(tmp ->next != start)
    {
        printf("%d\t",tmp->data);
        tmp = tmp->next;
    }
    printf("%d",tmp->data);
}
void delete()    
{
    struct node *temp , *ptr;
    int c ;
    printf("Enter the data you want to delete\t");
    scanf("%d",&c);
    if(start->data == c)
    {
      temp = start ;
      start = start->next ;
      start->prev = temp->prev ;
      temp->prev->next = start ;
      temp->prev =temp->next = NULL ;
      free(temp);
    }
    else
    {
      temp = start ;
    while(temp->data != c)
      {
        ptr = temp;
        temp = temp-> next;
      }
      ptr->next = temp->next;
      temp->next->prev =  ptr;
      temp->next = temp->prev = NULL;
      free(temp);
    }
}
void main()
{
     int c ;
    char s[1];  
    do{
    printf("\tclick 1 = insertatbeg, click 2 = insertatend, click 3 = display, click 4 = delete\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1 : insertatbeg();
                 break ;
        case 2 : insertatend();
                 break ;
        case 3 : display();
                 break ;
        case 4 : delete();
                 break ;
        default : printf("Wrong input\n");
    }
    printf("\nENTER Y FOR CONTINUE N FOR EXIT\n");
    scanf("%s",&s);
    }while((strcmp(s,"y")==0) || (strcmp(s,"Y")==0)); 
    
}
