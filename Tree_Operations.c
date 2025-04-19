#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
  struct Tree *left;
  int info;
  struct Tree *right;
} tree;

tree *insert(tree *, int);
void inorder(tree *);
void preorder(tree *);
void postorder(tree *);
void insert_using_recursion(tree **, int );
int height(tree*);
int highest_info_Node(tree*);
int lowest_info_Node(tree*);
int common_parent_Nodes(tree*);
int left_side_nodes(tree*);
int right_side_nodes(tree*);
int parent_find(tree* , int);


int main()
{
  tree *root = NULL;
  int ch, n,h=0;
  do
  {
    printf("\n\n************************");
    printf("\n1.Insert\n2.InOrder\n3.PreOrder\n4.PostOrder\n5.Insert_Using_Recursion\n6.height\n7.highest_info_Node\n8.Lowest_info_Node\n9.common_parent_Nodes\n10.Total_left_side_nodes\n11.Total_right_side_nodes\n12.Find_parentOfNode");
    printf("\nEnter your Choice\t");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:printf("Enter the data\t");
           scanf("%d", &n);
           root = insert(root, n);
           break;

    case 2:inorder(root);
           break;
      
    case 3:preorder(root);
           break;
     
    case 4:postorder(root);
           break;

    case 5:printf("Enter the data\t");
           scanf("%d", &n);
           insert_using_recursion(&root, n);
           break; 
    case 6 :h = height(root);
            if(h!=-1)
              printf("Height of tree : %d ",h);
            break;  
    case 7 : h = highest_info_Node(root);
                 printf("\nHeighest info node : %d ",h);
                 break;
    case 8 : h = lowest_info_Node(root);
                 printf("\nlowest info node : %d ",h);
                 break;
    case 9 : h = common_parent_Nodes(root);
                 
                 printf("\nNodes having common parents : %d ",h);
                 break;
    case 10 : h = left_side_nodes(root);
                 
                 printf("\nNo of left side nodes : %d ",h);
                 break;
    case 11 : h = right_side_nodes(root);
                
                 printf("\nNo of right side nodes : %d ",h);
                 break;
    case 12 : printf("\nEnter node for finding parent\t");
              scanf("%d",&n);
              h = parent_find(root,n);
              
              printf("\nParent Node : %d ",h);
              break;
    }
  } while (ch <= 13 && ch > 0);

  return 0;
}

tree* insert(tree* root , int n)
{
    tree* newnode = (tree*)malloc(sizeof(tree));
    if(newnode)
    {
        newnode->info = n ;
        newnode->left = newnode->right = NULL ;
    }
    
    tree *p ,*c ;
    p=c=root;
    if(root==NULL)
     root = newnode ;
    else{
        while(c!=NULL)
        {
            if(c->info > n)
              {
                p=c ;
                c= c->left ;
              }else if(c->info < n)
              {
                p=c ;
                c = c->right;
              }else{
                free(newnode);
                return root ;
              }
        }
        if(p->info > n)
    p->left = newnode;
  else
    p->right = newnode ;
    }
    return root ;
}

void insert_using_recursion(tree **rt, int n)
{
  if (*rt == NULL)
  {
    tree *newnode = (tree *)malloc(sizeof(tree));
    newnode->info = n;
    newnode->left = newnode->right = NULL;
    *rt = newnode;
  }
  else
  {
    if (n < (*rt)->info)
    {
      insert_using_recursion(&(*rt)->left, n);
    }
    else
      insert_using_recursion(&(*rt)->right, n);
  }
  return;
}

void inorder(tree *rt)
{
  if (rt == NULL)
  {
    return;
  }
  inorder(rt->left);
  printf("%d ", rt->info);
  inorder(rt->right);
}
void preorder(tree *rt)
{
  if (rt == NULL)
  {

    return;
  }
  printf("%d ", rt->info);
  preorder(rt->left);
  preorder(rt->right);
}
void postorder(tree *rt)
{
  if (rt == NULL)
  {
    return;
  }
  postorder(rt->left);
  postorder(rt->right);
  printf("%d ", rt->info);
}

int height(tree* root)
{
  if(root == NULL)
     {  
        return 0 ;
     }
    
    int l = height(root->left);
    int r = height(root->right);

    return 1+(l>r ? l : r);
}

int highest_info_Node(tree *root)
{
   if(root == NULL)
   {
    return 0 ;
   }
   else{
    while(root->right != NULL)
        root = root->right ;
   }
   return root->info ;
}

int lowest_info_Node(tree* root)
{
  if(root == NULL)
    return 0 ; 
    else
    {
      while(root->left !=NULL)
       {
        root = root->left ;
       }
    }
    return root->info;
}

int common_parent_Nodes(tree* root)
{
  if(root == NULL)
  return 0 ;

  int c=0 ;
  if(root->right !=NULL && root->left != NULL)
    c = c + 2 ;

 c = c + common_parent_Nodes(root->left);
 c = c + common_parent_Nodes(root->right);

 return c ;

}

int count_(tree* root)
{
    if(root==NULL)
       return 0 ;
    
       return 1+count_(root->left) + count_(root->right);
}


int left_side_nodes(tree* root)
{

if(root ==NULL || root->left == NULL)
  return 0 ;
  return count_(root->left);

}


int right_side_nodes(tree* root)
{
    if(root ==NULL || root->right == NULL)
  return 0 ;
  return count_(root->right);
}

int parent_find(tree* root , int n)
{
   if(root==NULL)
     return 0 ;
    
    if(root->left != NULL && root->left->info == n || root->right!=NULL && root->right->info == n)
       return root->info ;

    int lefttree =  parent_find(root->left , n);
    if(lefttree != 0)
       return lefttree ;

    return  parent_find(root->right , n);
}

