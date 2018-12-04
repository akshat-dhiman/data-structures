#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
enum color {red,black};
struct node{
  int data;
  struct node *left;
  struct node *right;
  struct node *parent;
  bool color;
};
struct node *tree=NULL;
struct node *insert()
{
  int n;
  struct node *new_node,*ptr,*preptr;
  printf("Enter elements in red-black tree.");
  printf("\nEnter -1 to stop.");
  scanf("%d",&n);
  while(n!=-1)
  {
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=n;
    new_node->left=NULL;
    new_node->right=NULL;
    new_node->parent=NULL;
    if(tree==NULL)
    {
      tree=new_node;
      tree->left=NULL;
      tree->right=NULL;
      tree->color=black;
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
      new_node->parent=preptr;
      if(preptr->color==black)
      new_node->color=red;
      else
      new_node->color=black;
    }
    scanf("%d",&n);
  }
  return tree;
}
struct node *gparent(struct node *n)
{
  if(n!=NULL&&n->parent!=NULL)
  return n->parent->parent;
  else
  return NULL;
}
struct node *uncle(struct node *n)
{
  struct node *g;
  g=gparent(n);
  if(g!=NULL)
  {
    if(n->parent==g->left)
    return g->right;
    else
    return g->left;
  }
  else
  printf("\n\tThere is no uncle node.");
}
void *rotate_l(struct node *n)
{
  n->parent->right=n->left;
  n->left=n->parent;
}
void *rotate_r(struct node *n)
{
  n->parent->left=n->right;
  n->right=n->parent;
}
void case5(struct node *n)
{
  struct node *g;
  g=gparent(n);
  if(n==n->parent->left&&n->parent==g->left)
    rotate_r(g);
    else if(n==n->parent->right&&n->parent==g->right)
    rotate_l(g);
    n->parent->color=black;
    g->color=red;
}
void case4(struct node *n)
{
  struct node *g;
  g=gparent(n);
  if(n==n->parent->right&&n->parent==g->left)
  {
    rotate_l(n->parent);
    n=n->left;
  }
  else if(n==n->parent->left&&n->parent==g->right)
  {
    rotate_r(n->parent);
    n=n->right;
  }
  case5(n);
}
void case1(struct node *);
void case3(struct node *n)
{
  struct node *g,*u;
  g=gparent(n);
  u=uncle(n);
  if(n!=NULL&&u->color==red)
  {
    u->color=black;
    n->parent->color=black;
    g->color=red;
    case1(g);
  }
  else
  case4(n);
}
void case2(struct node *n)
{
  if(n->parent->color==black)
  return;
  else
  case3(n);
}
void case1(struct node *n)
{
  if(n->parent==NULL)
  n->color=black;
  else
  case2(n);
}
struct node *insert_new(int n)
{
  struct node *bruh,*ptr,*preptr;
  bruh=(struct node *)malloc(sizeof(struct node));
  bruh->data=n;
  bruh->left=NULL;
  bruh->right=NULL;
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
  preptr->left=bruh;
  else
  preptr->right=bruh;
  case1(bruh);
  return tree;
}
struct node *display(struct node *tree)
{
  if(tree!=NULL)
  {
  printf("\t%d",tree->data);
  display(tree->left);
  display(tree->right);
  }
}
int main()
{ int n;
  insert();
  display(tree);
  printf("\nEnter an element to inert in the tree: ");
  scanf("%d",&n);
  insert_new(n);
  display(tree);
  return 0;
}
