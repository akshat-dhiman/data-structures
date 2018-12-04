#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
  int data;
  struct node *left;
  struct node *right;
};
struct node *tree=NULL;
struct node *insert()
{
  struct node *new_node,*ptr,*preptr;
  int n;
  printf("Enter elements in tree.\n");
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
    scanf("%d\n",&n);
  }
  return tree;
}
void preorder(struct node *tree)
{
  if(tree!=NULL)
  {
    printf("\t%d",tree->data);
    preorder(tree->left);
    preorder(tree->right);
  }
}
void inorder(struct node *tree)
{
  if(tree!=NULL)
  {
    inorder(tree->left);
    printf("\t%d",tree->data);
    inorder(tree->right);
  }
}
void postorder(struct node *tree)
{
  if(tree!=NULL)
  {
    postorder(tree->left);
    postorder(tree->right);
    printf("\t%d",tree->data);
  }
}
int search(struct node *tree,int val,int c)
{
  if(tree==NULL)
  printf("Tree is empty");
  else if(val<tree->data)
  {
    c++;
  search(tree->left,val,c);
}
  else if(val>tree->data)
  {
      c++;
  search(tree->right,val,c);
}
  else
  return c;
}
struct node *largest(struct node *tree)
{
  if(tree==NULL||tree->right==NULL)
  return tree;
  else
  largest(tree->right);
}
struct node *smallest(struct node *tree)
{
  if(tree==NULL||tree->left==NULL)
  return tree;
  else
  smallest(tree->left);
}
int height(struct node *tree)
{  int lh,rh;
  if(tree==NULL)
  return 0;
  else
  {
   lh=height(tree->left);
   rh=height(tree->right);
 if(lh>rh)
 return (lh+1);
 else
 return (rh+1);
}
}
int nodes(struct node *tree)
{
  if(tree==NULL)
  return 0;
  else
  return (nodes(tree->left)+nodes(tree->right)+1);
}
int internal_n(struct node *tree)
{
  if(tree==NULL||(tree->left==NULL&&tree->right==NULL))
  return 0;
  else
  return (internal_n(tree->left)+internal_n(tree->right)+1);
}
int external_n(struct node *tree)
{
  if(tree==NULL)
  return 0;
  else if(tree->left==NULL&&tree->right==NULL)
  return 1;
  else
  return (external_n(tree->left)+external_n(tree->right));
}
struct node *mirror(struct node *tree)
{
  struct node *temp;
  if(tree!=NULL)
  {
    mirror(tree->left);
    mirror(tree->right);
    temp=tree->left;
    tree->left=tree->right;
    tree->right=temp;
  }
  return tree;
}
struct node *del(struct node *tree)
{
  if(tree!=NULL)
  {
    del(tree->left);
    del(tree->right);
    free(tree);
  }
  return tree;
}
struct node *del_elements(struct node *tree,int val)
{
  if(tree==NULL)
  return tree;
  else if(val<tree->data)
  tree->left=del_elements(tree->left,val);
  else if(val>tree->data)
  tree->right=del_elements(tree->right,val);
  else
  {
    if(tree->left==NULL&&tree->right==NULL)
    {
      free(tree);
      tree=NULL;
      return tree;
    }
    else if(tree->left==NULL)
    {
      struct node *temp=tree;
      tree=tree->right;
      free(temp);
      return tree;
    }
    else if(tree->right==NULL)
    {
      struct node *temp=tree;
      tree=tree->left;
      free(temp);
      return tree;
    }
    else
    {
      struct node *temp=largest(tree->left);
      tree->data=temp->data;
      tree->left=del_elements(tree->left,temp->data);
      return tree;
    }
   }
}
int main()
{  struct node *c;
  int t=0,u,w;
  insert();
  printf("\nElements in PreOrder:\n");
  preorder(tree);
  printf("\nElements in InOrder:\n");
  inorder(tree);
  printf("\nElements in PostOrder:\n");
  postorder(tree);
  c=largest(tree);
  printf("\nLargest element in tree: %d",c->data);
  c=smallest(tree);
  printf("\nSmallest element in tree: %d",c->data);
 printf("\nHeight of tree: %d",height(tree));
 printf("\nTotal no. of nodes in tree: %d",nodes(tree));
 printf("\nTotal no. of internal nodes: %d",internal_n(tree));
 printf("\nTotal no. of external nodes: %d",external_n(tree));
 printf("\nEnter element to Search:");
 fflush(stdin);
 scanf(" %d",&u);
 t=search(tree,u,0);
 if(t!=0)
 printf("\n\tElement found at %d level",t);
 else
 printf("\n\tElement not found!");
printf("\nEnter element to be deleted:");
scanf(" %d",&w);
tree=del_elements(tree,w);
printf("\nElements in PreOrder:\n");
preorder(tree);
printf("\nElements in InOrder:\n");
inorder(tree);
printf("\nElements in PostOrder:\n");
postorder(tree);
 printf("\nMirror image of tree is made.");
 tree=mirror(tree);
 printf("\nElements in PreOrder:\n");
 preorder(tree);
 printf("\nElements in InOrder:\n");
 inorder(tree);
 printf("\nElements in PostOrder:\n");
 postorder(tree);
 del(tree);
 printf("\n\t\t\t\t\t\tTree deleted successfully.");
  return 0;
}
