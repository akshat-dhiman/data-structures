#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
  char data;
  int p;
  struct node *ptr;
};
struct node *start=NULL;
struct node *insert()
{
  struct node *new_node,*z=start;
  int num,ok;
  char s;
  printf("\nEnter -1 to stop.");
  printf("\nEnter the characters and their priorities: ");
  ok=scanf(" %c %d",&s,&num);
  while(num!=-1&&ok==2)
  {
    new_node=malloc(sizeof(struct node));
    new_node->data=s;
    new_node->p=num;
    if(start==NULL)
    {
      start=new_node;
      z=start;
      new_node->ptr=NULL;
    }
    else
    {
      z->ptr=new_node;
      new_node->ptr=NULL;
      z=z->ptr;
    }
    ok=scanf(" %c %d",&s,&num);
  }
  return start;
}
struct node *display()
{
  struct node *z;
  z=start;
  printf("\nDisplaying elements:\n");
  while(z!=NULL)
  {
    printf("\t%c [Priority=%d]\n",z->data,z->p);
    z=z->ptr;
  }
  return start;
}
struct node *sortit()
{
  struct node *z,*q;
  int t;
  char x;
  z=start;
  while(z->ptr!=NULL)
  {
    q=z->ptr;
    while(q!=NULL)
    {
      if(z->p>q->p)
      {
        t=z->p;
        x=z->data;
        z->p=q->p;
        z->data=q->data;
        q->p=t;
        q->data=x;
      }
      q=q->ptr;
    }
    z=z->ptr;
  }
  return start;
}
struct node *new_insert()
{
  struct node *y,*z;
  int n,ok;
  char s;
  printf("\nEnter character and priority for new node:");
  ok=scanf(" %c %d",&s,&n);
  if(2==ok)
  {
    y=malloc(sizeof(struct node));
    y->data=s;
    y->p=n;
  if(n<start->p)
  {
    y->ptr=start;
    start=y;
    printf("%d",y->p);
  }
  else
  {
    z=start;
  while(z->ptr->p<=n&&z->ptr!=NULL)
    z=z->ptr;
  y->ptr=z->ptr;
  z->ptr=y;
}
}
  return start;
}
int main()
{
  insert();
  display();
  sortit();
  display();
  new_insert();
  display();
  return 0;
}
