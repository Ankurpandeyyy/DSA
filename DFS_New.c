#include<stdio.h>
#include<stdlib.h>
#define max 10 
typedef struct node{
    int dest ;
    int weight ;
    struct node *next ;
}node;

typedef struct graph{
    int numV ;
    node* list[max];
    int visited[max];
}graph;

graph* addedges(graph* , int);
int DFS(graph* , int, int);
void display(graph* , int);

int main()
{
    int v , ch , src , dest ;
    printf("\nEnter number of vertices\t");
    scanf("%d",&v);
    graph* g = NULL;
    do{
        printf("\n1.Create Graph\n2.display\n3.DFS");
        printf("\n\n\tEnter your choice\t");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 : g = addedges(g,v);
                     break;
            case 2 : display(g,v);
                     break;
            case 3 : if(g==NULL)
                     printf("\nGraph is empty\n");
                     else{
                      printf("Enter source(0 to %d) and destination(0 to %d)\n",v-1,v-1);
                      scanf("%d%d",&src,&dest);
                      printf("\nDFS Path \n");
                      if(DFS(g,src,dest) != 1)
                        printf("No path Found");
                     }
                     
                     break;
        }
    } while(ch<=3 && ch>0);
}

graph* addedges(graph* g , int v)
{
    g = (graph*)malloc(sizeof(graph));
    if(g)
    {
        g->numV = v ;
        for(int i=0 ; i<v ; i++){
           g->visited[i]=0 ;
           g->list[i]=NULL;
        }
    }
   
    int src , dest , weight ;
    printf("\nEnter src and destination and weight(enter -1 -1 -1 for exit)\n");

   node *newnode ;
   while(1)
   {
    newnode = (node*)malloc(sizeof(node));
    scanf("%d%d%d",&src,&newnode->dest,&newnode->weight);
    if(src==-1 || newnode->dest==-1 || newnode->weight==-1)
        break;

     newnode->next = g->list[src];
     g->list[src] = newnode ;
   }

   return g ;
}

int DFS(graph* g , int s , int d)
{
    g->visited[s] = 1 ;
    printf("%d\t",s);

    if(s==d)
      return 1 ;

    node *tmp = g->list[s];
    while(tmp)
    {
        if(g->visited[tmp->dest] != 1)
        {
            if(DFS(g,tmp->dest,d))
               return 1 ;
        }
        tmp = tmp->next ;
    }
}

void display(graph* g , int v)
{
    if(g==NULL)
     {
        printf("\n Graph is empty\n");
     }else{
         
        printf("\nCREATED GRAPH\n");
        for(int i=0 ; i<v ; i++)
        {
            printf("Vertex(%d) :",i);
            node *tmp = g->list[i];
            while(tmp)
            {
                printf("%d (weight:%d)- >",tmp->dest,tmp->weight);
                tmp = tmp->next;
            }
            printf("NULL\n");
        }
     }
}


