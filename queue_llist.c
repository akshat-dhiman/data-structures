#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
  struct node{
    int data;
    struct node *ptr;
  };
  struct node *front=NULL;
struct node *insert()
  {
    struct node *new_node,*rear;
    int num;
    printf("\nEnter -1 to stop.");
    printf("\nEnter elements in queue: ");
    scanf("%d",&num);
    while(num!=-1)
    {
      new_node=(struct node *)malloc(sizeof(struct node));
      new_node->data=num;
      if(front==NULL)
      {
        front=new_node;
        rear=front;
        new_node->ptr=NULL;
      }
      else
      {
        rear->ptr=new_node;
        rear=rear->ptr;
        new_node->ptr=NULL;
      }
      scanf("%d",&num);
    }
    return front;
  }
  struct node *display()
  {
    struct node *z;
    z=front;
    printf("\nDisplaying elements after operation: ");
    while(z!=NULL)
    {
      printf("\t%d",z->data);
      z=z->ptr;
    }
    return front;
  }
  struct node *del()
  {
    struct node *z;
    z=front;
    front=front->ptr;
    free(z);
    return front;
  }
  int main()
  {  int n;
    insert();
    display();
    printf("\nHow many elements you wanna delete? : ");
    scanf("%d",&n);
    while(n>0)
    {
      del();
      n--;
    }
    display();
    return 0;
  }
