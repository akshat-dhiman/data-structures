#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
  int data;
  struct node *left;
  struct node *right;
  bool rt;
};
struct node *tree=NULL,*q;
int a[20],i=0;
struct node *insert()
{
  struct node *new_node,*ptr,*preptr;
  int n;
  printf("Enter the values in binary search tree.\n");
  printf("Enter -1 to stop.\n");
  scanf("%d",&n);
  while(n!=-1)
  {
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=n;
      new_node->left=NULL;
      new_node->right=NULL;
    if(tree==NULL)
    {
     tree=new_node;
      tree->left=NULL;
      tree->right=NULL;
      q=tree;
    }
    else
    {
      ptr=tree;
      while(ptr!=NULL)
      {
        preptr=ptr;
        if(n<ptr->data)
        ptr=ptr->left;
        else
        ptr=ptr->right;
      }
      if(n<preptr->data)
      preptr->left=new_node;
      else
      preptr->right=new_node;
    }
    scanf("\n%d",&n);
  }
  return tree;
}
void inorder(struct node *tree)
{
  if(tree!=NULL)
  {
    inorder(tree->left);
    printf("\t%d",tree->data);
    a[i]=tree->data;
    i++;
    inorder(tree->right);
  }
}
int numbers(struct node *tree)
{
  if(tree==NULL)
  return 0;
  else
  return (numbers(tree->left)+numbers(tree->right)+1);
}
struct node *reach1(struct node *tree,int val,struct node *w=q)
{
  if(tree==NULL)
  return tree;
  else
  {
  if(val<w->data)
  w->left=reach1(tree,val,w->left);
  else if(val>w->data)
  w->right=reach1(tree,val,w->right);
  else
  tree->left=w;
  return tree;
}
}
struct node *reach2(struct node *tree,int val,struct node *w=q)
{
  if(tree==NULL)
  return tree;
  else
  {
  if(val<w->data)
  w->left=reach2(tree,val,w->left);
  else if(val>w->data)
  w->right=reach2(tree,val,w->right);
  else
  tree->right=w;
  return tree;
}
}
struct node *thread(struct node *tree)
{  struct node *temp1,*temp2;
  int c;
  c=numbers(tree);
  if(tree==NULL)
  return tree;
  else if(tree->left==NULL&&tree->right==NULL)
  { i=0;
    while(a[i]!=tree->data)
      i++;
      if(i!=0||i!=c-1)
      {
    temp1=reach1(tree,a[i]-1);
    temp2=reach2(tree,a[i]+1);
  }
  if(i==0)
  temp2=reach2(tree,a[i]+1);
  if(i==c-1)
  temp1=reach1(tree,a[i]-1);
  printf("yeah");
    return tree;
  }
  else
  {
    (thread(tree->left),thread(tree->right));
    printf("yeah");
    return tree;
  }
}
int main()
{ int c;
  insert();
  inorder(tree);
  c=numbers(tree);
  for(int j=0;j<c;j++)
    printf("\t\n%d",a[j]);
  thread(tree);
  return 0;
}
