#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

void push(int);
void pop();
void display();

int stack[SIZE], top = -1 ;

void main()
{
    int value, choice;
    while(1)
    {
        printf("\n\n ***** MENU *****\n");
        printf("1. push\n2. pop\n3. Display\n4. Exit(0)");
        printf("\nEnter your choice: \t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the value to be insert : ");
                    scanf("%d",&value);
                    push(value);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break ;
            case 4: exit(0);
            default:printf("\nWRONG WRONG WRONG!!!!!");
        }
    }
}
void push(int value)
{
    if(top == SIZE-1)
       printf("\nStack is full !!! INSERTION is not possible!!");
    else
    {
      top++ ;
      stack[top] = value ;
      printf("Insertion success!!!");
    }
}
void pop()
{
    if(top == -1)
      printf("Stack is EMPTY,,,Deletion can't be perform!!!!");
    else
    {
        printf("\nDELETED : %d ",stack[top]);
        top-- ;
    }
}

void display()
{
    int i ;
    if(top == -1)
      printf("\nstack is Empty!!!");
    else
    {
        printf("stack elements are:::\n");
          for(i=top ; i>=0; i--)
            printf("%d\n",stack[i]);
    }
}