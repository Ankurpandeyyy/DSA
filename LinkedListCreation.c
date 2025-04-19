#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void LinkedListTraversal(struct node *ptr)
{
   while(ptr!=NULL)
   {
    printf("\nELEMENT = %d",ptr->data);
    ptr = ptr->next;
   }
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;
    struct node *sixth;

    head = (struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third =(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));
    fifth =(struct node *)malloc(sizeof(struct node));
    sixth =(struct node *)malloc(sizeof(struct node));

    head->data=7;
    head->next=second;

    second->data=14;
    second->next=third;

    third->data=21;
    third->next=fourth;

    fourth->data=28;
    fourth->next=fifth;

    fifth->data=35;
    fifth->next=sixth;

    sixth->data=42;
    sixth->next=NULL;
    
    LinkedListTraversal(head);
    return 0;
}