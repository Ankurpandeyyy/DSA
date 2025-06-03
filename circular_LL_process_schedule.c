#include<stdio.h>
#include<stdlib.h>
#define TIME_SLOT 10  
typedef struct process{
    int id ;
    int burst ;
    int completion ;
    int remaining ;
    struct process *next ;
}process;

process* addProcess(process* );
void display(process*);
void scheduling(process* , int);

int main()
{
    process* head = NULL ;
    int ch , n=0;
    do{
        printf("\n\t**************\n");
        printf("1. Create_Process\n2. display\n3. Schedule_Process\n");
        printf("Enter your CHOICE\t");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1 : head = addProcess(head);
                     n++;
                     break ;
            case 2 :  display(head);
                     break ;
            case 3 : scheduling(head,n);
                     break;
        }
    }while(ch<=3 && ch>0);
    return 0 ;
}
process* addProcess(process* head)
{
  process *newnode = (process*)malloc(sizeof(process));
  if(newnode)
   {
    printf("\nEnter process id\t");
    scanf("%d",&newnode->id);
    printf("\nEnter burst time\t");
    scanf("%d",&newnode->burst);
    newnode->completion = 0 ;
    newnode->remaining= newnode->burst;
    newnode->next = NULL ;
   }
   if(head == NULL)
   {
    newnode ->next = head ;
    head = newnode ;
    head->next = newnode ;
   }else{
    process* tmp = head ;
    while(tmp->next != head)
    {
        tmp = tmp ->next ;
    }
    tmp -> next = newnode ;
    newnode -> next = head ;
   }
   return head ;
}
void display(process* head)
{
    if(head == NULL)
      {
        printf("\n there is no process to display\n");
        return ;
      }
      else{
        process* tmp = head ;
        printf("\nID\t Burst_Time\t Completion_Time\t remaining_Time\n");
        while(tmp->next != head)
        {
            printf("%d\t\t%d\t\t%d\t\t%d\n",tmp->id,tmp->burst,tmp->completion,tmp->remaining);
           
            tmp = tmp->next ;
        }
        printf("%d\t\t%d\t\t%d\t\t%d\n",tmp->id,tmp->burst,tmp->completion,tmp->remaining);
      }
    
}
void scheduling(process *head , int n)
{
    if (head == NULL || n <= 0) {
        printf("No processes to schedule.\n");
        return;
    }
    int completed = 0 ;
    int time = 0 ;

    process *tmp = head ;
    while(completed < n)
    {
        if(tmp->remaining > 0)
        {
            if(tmp->remaining <= TIME_SLOT )
            {
                time += tmp->remaining;
                tmp->remaining = 0;
                tmp->completion = time ;
                completed++;
            }
            else
            {
                time += TIME_SLOT;
                tmp->remaining -= TIME_SLOT;
            }
        }
        tmp = tmp->next ;
    }
    printf("\nID\tBurst_Time\tWaiting_Time\tCompletion_Time\n");
    tmp = head;
    do {
        int waiting = tmp->completion - tmp->burst;
        printf("%d\t\t%d\t\t%d\t\t%d\n", tmp->id, tmp->burst, waiting, tmp->completion);
        tmp = tmp->next;
    } while (tmp != head);
}



