#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
  int data;
  struct node *ptr;
};
struct node *top=NULL;
struct node *insert()
{
  struct node *new_node;
  int num;
  printf("Enter -1 to stop.");
  printf("\nPush elements in stack: ");
  scanf("%d",&num);
  while(num!=-1)
  {
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    if(top==NULL)
    {
      top=new_node;
      new_node->ptr=NULL;
    }
    else
    {
      new_node->ptr=top;
      top=new_node;
    }
    scanf("%d",&num);
  }
    return top;
}
struct node *display()
{
  struct node *z;
  z=top;
  while(z!=NULL)
  {
    printf("\t%d",z->data);
    z=z->ptr;
  }
  return top;
}
struct node *enter()
{
  struct node *new_node;
  int num;
  printf("\nEnter element to push: ");
  scanf("%d",&num);
  new_node->ptr=top;
  top=new_node;
  return top;
}
struct node *del()
{
  struct node *z;
  z=top;
  top=top->ptr;
  free(z);
  printf("\nAfter poping topmost element: ");
  return top;
}
int main()
{
  insert();
  display();
  del();
  display();
  return 0;
}
