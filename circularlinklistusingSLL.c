#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *next ;
}*start = NULL ;
//typedef struct node anky ;

void insertatbeg()
{
    struct node *newnode, *tmp ;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("ENTER DATA FOR FIRST NODE\t");
    scanf("%d",&newnode->data);

    if(start == NULL)
    {
        start = newnode ;
        newnode -> next = start ;
    }
    else
    {
      tmp = start ;
      while(tmp->next != start)
      {
        tmp = tmp->next ;
      }
      newnode->next = start ;
      start = newnode ;
      tmp -> next = start ;

    // tmp-> next = newnode ;
    // newnode->next = start ;
    // start = newnode ;
    }
}

void insertatend()
{
     struct node *newnode, *tmp ;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("ENTER DATA FOR LAST NODE\t");
    scanf("%d",&newnode->data);

    if(start == NULL)
    {
        start = newnode ;
        newnode -> next = start ;
    }
    else
    {
      tmp = start ;
      while(tmp->next != start)
      {
        tmp = tmp->next ;
      }
     tmp->next = newnode ;
     newnode->next = start ;
     }  
 }
//  void reverse()
//  {
//     struct  node *tmp ;
//     tmp = start ;
//     while(tmp->next != start)
//     {
//         tmp = tmp->next ;
//     }
//     printf("%d",tmp->data);
//  }
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

void main()
{
    int c ;
    char s[1];  
    do{
    printf("\tclick 1 = insertatbeg, click 2 = insertatend, click 3 = display\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1 : insertatbeg();
                 break ;
        case 2 : insertatend();
                 break ;
        case 3 : display();
                 break ;
        default : printf("Wrong input\n");
    }
    printf("\nENTER Y FOR CONTINUE N FOR EXIT\n");
    scanf("%s",&s);
    }while((strcmp(s,"y")==0) || (strcmp(s,"Y")==0)); 
    
}
