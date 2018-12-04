#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
  int data;
  struct node *ptr;
};
struct node *start=NULL;
struct node *insert()
{
  struct node *new_node,*q;
  int num;
  printf("\nEnter -1 to stop.\n");
  printf("\nEnter elements for circular linked list.\n");
  scanf("%d",&num);
  while(num!=-1)
  {
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    if(start==NULL)
    {
      start=new_node;
      q=start;
      new_node->ptr=start;
    }
    else
    {
      q->ptr=new_node;
      new_node->ptr=start;
      q=q->ptr;
    }
    scanf("%d",&num);
  }
  return start;
}
struct node *display()
{
  struct node *q;
  q=start;
  while(q->ptr!=start)
  {
    printf("\t%d",q->data);
    q=q->ptr;
  }
  printf("\t%d",q->data);
  return start;
}
struct node *insert_beg()
{
  struct node *new_node,*a;
  int num;
  printf("\nEnter no. to add at the starting of the circular linked list: ");
  scanf("%d",&num);
  new_node=(struct node *)malloc(sizeof(struct node));
  new_node->data=num;
  a=start;
  while(a->ptr!=start)
    a=a->ptr;
  a->ptr=new_node;
  new_node->ptr=start;
  start=new_node;
  return start;
}
struct node *insert_end()
{
  struct node *new_node,*z;
  int n;
  printf("\nEnter element to add at end of list: ");
  scanf("%d",&n);
  new_node=(struct node *)malloc(sizeof(struct node));
  new_node->data=n;
  z=start;
  while(z->ptr!=start)
    z=z->ptr;
  z->ptr=new_node;
  new_node->ptr=start;
  return start;
}
struct node *insert_after()
{
  struct node *preptr,*new_node,*x;
  int num,b;
  printf("\nEnter element to be added: ");
  scanf("%d",&num);
  printf("\nEnter no after which you want to add: ");
  scanf("%d",&b);
  new_node=(struct node *)malloc(sizeof(struct node));
  new_node->data=num;
  x=start;
  preptr=x;
  while(preptr->data!=b) {
    preptr=x;
    x=x->ptr;
  }
  preptr->ptr=new_node;
  new_node->ptr=x;
  return start;
}
struct node *del_first()
{
  struct node *x,*z;
  z=start;
  while(z->ptr!=start)
    z=z->ptr;
  x=start;
  start=start->ptr;
  z->ptr=start;
  free(x);
  printf("\n");
  return start;
}
struct node *del_last()
{
  struct node *z,*preptr;
  z=start;
  while(z->ptr!=start)
  {
    preptr=z;
    z=z->ptr;
  }
  preptr->ptr=start;
  free(z);
  printf("\n");
  return start;
}
struct node *del()
{
  struct node *z;
  z=start;
  while(z->ptr!=start)
  start=del_last();
free(z);
return start;
}
int main()
{
  insert();
  display();
  insert_beg();
  display();
  insert_end();
  display();
  insert_after();
  display();
  del_first();
  display();
  del_last();
  display();
  del();
  return 0;
}
