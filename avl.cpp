#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
  int data;
  struct node *left;
  struct node *right;
  int bfactor;
};
struct node *tree=NULL;
int balance(struct node *tree)
{
  int lh,rh;
  if(tree==NULL)
  return 0;
  else
  {
  lh=balance(tree->left);
  rh=balance(tree->right);
  return (lh+1)-(rh+1);
  }
  }
  struct node *yeah()
  { int n;
    struct node *new_node,*ptr,*preptr;
    printf("Enter elements for an AVL tree.\n");
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
      scanf("%d",&n);
    }
    return tree;
  }
  void bf(struct node *tree)
  {  if(tree!=NULL)
    {
    tree->bfactor=balance(tree);
    bf(tree->left);
    bf(tree->right);
   }
  }
  struct node *search(struct node *tree,int num)
  {
    if(tree!=NULL)
    {
      if(num<tree->data)
      tree=search(tree->left,num);
      else
      tree=search(tree->right,num);
    }
    return tree;
  }
  struct node *insert(struct node *tree,int num,int *log)
  {
    struct node *aptr,*bptr;
    if(tree==NULL)
    {
      tree=(struct node *)malloc(sizeof(struct node));
      tree->data=num;
      tree->left=NULL;
      tree->right=NULL;
      tree->bfactor=0;
      *log=1;
      return tree;
    }
    else if(num<tree->data)
    {
      tree->left=insert(tree->left,num,log);
      if(*log==1)
      {
        switch(tree->bfactor)
        {
          case -1:  //right heavy.
          tree->bfactor=0;
          break;
          case 0:  //balanced.
          tree->bfactor=1;
          break;
          case 1:  //left heavy.
          aptr=tree->left;
          if(aptr->bfactor==1)
          {
            printf("\n\tLL Rotation.");
            tree->left=aptr->right;
            aptr->right=tree;
            tree->bfactor=0;
            aptr->bfactor=0;
            tree=aptr;
          }
          else
          {
            printf("\n\tLR Rotation.");
            bptr=aptr->right;
            aptr->right=bptr->left;
            bptr->left=aptr;
            tree->left=bptr->right;
            bptr->right=tree;
            if(bptr->bfactor==1)
            tree->bfactor=-1;
            else
            tree->bfactor=0;
            if(bptr->bfactor==-1)
            aptr->bfactor=1;
            else
            aptr->bfactor=0;
            bptr->bfactor=0;
            tree=bptr;
          }
          break;
        }
        *log=0;
      }
    }
    else if(num>tree->data)
    {
      tree->right=insert(tree->right,num,log);
      if(*log==1)
      {
        switch(tree->bfactor)
        {
          case 1:
          tree->bfactor=0;
          break;
          case 0:
          tree->bfactor=-1;
          break;
          case -1:
          aptr=tree->right;
          if(aptr->bfactor==-1)
          {
            printf("\n\tRR Rotation.");
            tree->right=aptr->left;
            aptr->left=tree;
            tree->bfactor=0;
            aptr->bfactor=0;
            tree=aptr;
          }
          else
          {
            printf("\n\tRL Rotation.");
            bptr=aptr->left;
            aptr->left=bptr->right;
            bptr->right=aptr;
            tree->right=bptr->left;
            bptr->left=tree;
            if(bptr->bfactor==-1)
            tree->bfactor=1;
            else
            tree->bfactor=0;
            if(bptr->bfactor==1)
            aptr->bfactor=-1;
            else
            aptr->bfactor=0;
            bptr->bfactor=0;
            tree=bptr;
          }
          break;
        }
        *log=0;
      }
    }
    return tree;
  }
  void display(struct node *tree)
  {
    if(tree!=NULL)
    {
    printf("\t%d",tree->data);
    display(tree->left);
    display(tree->right);
    }
  }
  int main()
  {  int log;
    int num;
    yeah();
    printf("t");
    bf(tree);
    display(tree);
    printf("\nEnter number to insert.");
    scanf("%d",&num);
    if(search(tree,num)==NULL)
    insert(tree,num,&log);
    else
    printf("\nNumber already exists.");
    display(tree);
    return 0;
  }
