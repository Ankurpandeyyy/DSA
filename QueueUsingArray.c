#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int queue[SIZE], front = -1, rear = -1 ;

void enqueue()
{
    int value ;
    if(rear == SIZE - 1)
       printf("\nQueue is Full!!! Insertion is not Possible!!!");
    else
    {
        if(front == -1)
           front = 0 ;
        rear++ ;
        printf("Enter value for Inserting : \t");
        scanf("%d",&value);
        queue[rear] = value ;
        printf("\n Insertion SUCCESS !!!!");
    }
}
void dequeue()
{
    if(front > rear || front== -1)
      printf("\n\nQueue is Empty!!! Deletion is not possible\n");
    else
    {
        printf("\nDELETED = %d", queue[front]);
        front++ ;
    }
}
void display()
{
    if(rear == -1)
      printf("\nQueue is Empty!!!!\n");
    else
    {
        int i;
        printf("\nQueue Elements are-----\n");
        for(i=front; i<=rear; i++)
           printf("%d\t",queue[i]);
    }
}
void main()
{
    int ch;
    while(1)
    {
    printf("\nEnter your Choice\t");
    printf("\n1. enqueue\n2. dequeue\n3. display\n4. exit(0)\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: enqueue();
                break;
        case 2: dequeue();
                break;
        case 3: display();
                break;
        case 4: exit(0);
                break;
        default: printf("\n\nWRONG CHOICE\n");
    }
    }
}