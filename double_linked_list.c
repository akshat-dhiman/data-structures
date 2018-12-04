#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
  struct node *prev;
  int data;
  struct node *ptr;
};
struct node *start=NULL;
struct node *insert()
{
  struct node *new_node,*q;
  int num;
  printf("\nEnter -1 to stop.");
  printf("\nEnter elements in double liinked list: ");
  scanf("%d",&num);
  while(num!=-1)
  {
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    if(start==NULL)
    {
      start=new_node;
      new_node->prev=NULL;
      new_node->ptr=NULL;
      q=start;
    }
    else
    {
      q->ptr=new_node;
      new_node->prev=q;
      new_node->ptr=NULL;
      q=q->ptr;
    }
    scanf("%d",&num);
  }
  return start;
}
struct node *display()
{
  struct node *z;
  z=start;
  while(z!=NULL)
  {
    printf("\t%d",z->data);
    z=z->ptr;
  }
  return start;
}
struct node *insert_beg()
{
  struct node *new_node;
  int num;
  printf("\nEnter no to add at beginning: ");
  scanf("%d",&num);
  new_node=(struct node *)malloc(sizeof(struct node));
  new_node->data=num;
  new_node->prev=NULL;
  new_node->ptr=start;
  start->prev=new_node;
  start=new_node;
  return start;
}
struct node *insert_end()
{
  struct node *new_node,*z;
  int num;
  printf("\nEnter element to add at last of list: ");
  scanf("%d",&num);
  new_node=(struct node *)malloc(sizeof(struct node));
  new_node->data=num;
  z=start;
  while(z->ptr!=NULL)
   z=z->ptr;
  new_node->ptr=NULL;
  z->ptr=new_node;
  new_node->prev=z;
  return start;
}
struct node *insert_after()
{
  struct node *new_node,*preptr,*z;
  int num,a;
  printf("\nEnter element to add: ");
  scanf("%d",&num);
  printf("\nEnter no after which you want to add: ");
  scanf("%d",&a);
  new_node=(struct node *)malloc(sizeof(struct node));
  new_node->data=num;
  z=start;
  preptr=z;
  while(preptr->data!=a)
  {
    preptr=z;
    z=z->ptr;
  }
  preptr->ptr=new_node;
  new_node->prev=preptr;
  new_node->ptr=z;
  z->prev=new_node;
  return start;
}
struct node *del_first()
{
  struct node *x;
  x=start;
  start=start->ptr;
  start->prev=NULL;
  free(x);
  printf("\nAfter deleting first element:\n");
  return start;
}
struct node *del_after()
{
  struct node *z,*preptr;
  int num;
  printf("\nEnter element whose next one you wanna delete: ");
  scanf("%d",&num);
  z=start;
  preptr=z;
  while(preptr->data!=num)
  {
    preptr=z;
    z=z->ptr;
  }
  preptr->ptr=z->ptr;
  z->ptr->prev=preptr;
  return start;
}
struct node *del()
{
  while(start!=NULL)
   start=del_first();
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
  del_after();
  display();
  del();
  return 0;
}
