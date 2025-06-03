#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int dest ;
    int weight ;
    struct node *next ;
}graph;

void Add_Edges(graph*[] , int);
void Display(graph*[] , int);

int main()
{
    int v ;
    printf("\nEnter number of VERTICES\t");
    scanf("%d",&v);
    graph* p[v];   
    for(int i=0 ; i<v ; i++)
      {
        p[i] = NULL ;
      }

    int ch ;
    do{
        printf("\n\t1.AddEdges\n\t2.Display_Graph\n\t");
        printf("\nEnter your Choice\t");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1 : Add_Edges(p , v);
                 break;
        case 2 : Display(p , v);
                 break ;
        }
    }while(ch<=2 && ch>0);
}

void Add_Edges(graph* p[] , int v)
{
  int src;
  printf("\nEnter source(0 to %d) destination(0 to %d) and weight (enter -1 -1 -1 for exiting..)\n",v,v);
  graph *newnode ;
  while(1)
  {
    newnode = (graph*)malloc(sizeof(graph));
    scanf("%d%d%d",&src , &newnode->dest, &newnode->weight);

    if(src==-1 || newnode->dest==-1 || newnode->weight==-1)
       break;
    
    newnode->next=p[src];
    p[src] = newnode ;
  }
}

void Display(graph* p[] , int v)
{
  
    for(int i=0 ; i<v ; i++)
    {
        printf("\nVertex %d ",i);
        graph *tmp = p[i];
        while(tmp!=NULL)
        {
            printf("-> %d (weight:%d)",tmp->dest,tmp->weight);
            tmp = tmp->next ;
        }
        printf("\n");
    }

}