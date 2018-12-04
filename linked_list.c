#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
  int data;
  struct node *ptr;
};
struct node *start=NULL;
struct node *list()
{
  struct node *new,*p;
  int n;
  printf("\nEnter -1 to stop.");
  printf("\nEnter the numbers.");
  scanf("%d\n",&n);
  while(n!=-1)
  {
    new=(struct node *)malloc(sizeof(struct node));
    new->data=n;
    if(start==NULL)
    {
      start=new;
      p=start;
      new->ptr=NULL;
    }
    else
    {
      p->ptr=new;
      p=p->ptr;
      new->ptr=NULL;
    }
    scanf("%d\n",&n);
  }
  return start;
}
struct node *display()
{
  struct node *q;
  q=start;
  while(q!=NULL)
  {
    printf("\t%d",q->data);
    q=q->ptr;
  }
  return start;
}
struct node *insert_beg()
{
  struct node *new_node;
  int num;
  printf("\nAfter inserting at start of the linked list: ");
  scanf("%d",&num);
  new_node=(struct node *)malloc(sizeof(struct node));
  new_node->data=num;
  new_node->ptr=start;
  start=new_node;
  return start;
}
struct node *insert_end()
{
  struct node *new_node,*w;
  int num;
  printf("\nEnter number to insert at last: ");
  scanf("%d",&num);
  new_node=(struct node *)malloc(sizeof(struct node));
  new_node->data=num;
  w=start;
  while(w->ptr!=NULL)
    w=w->ptr;
  w->ptr=new_node;
  new_node->ptr=NULL;
  return start;
}
struct node *insert_after()
{
  struct node *new_node,*preptr,*t;
  int num,a;
  new_node=(struct node *)malloc(sizeof(struct node));
  printf("\nEnter no. to add: ");
  scanf("%d",&num);
  new_node->data=num;
  printf("\nEnter no. after which you want to add: ");
  scanf("%d",&a);
  t=start;
  preptr=t;
  while(preptr->data!=a)
  {
    preptr=t;
    t=t->ptr;
    if(t->ptr==NULL)
    printf("\nNumber doesn't exists.");
  }
  preptr->ptr=new_node;
  new_node->ptr=t;
  return start;
}
struct node *insert_before()
{
  struct node *new_node,*preptr,*w;
  int num,b;
  printf("\nEnter no. to add: ");
  scanf("%d",&num);
  printf("\nEnter no. before which you want to add: ");
  scanf("%d",&b);
  new_node=(struct node *)malloc(sizeof(struct node));
  new_node->data=num;
  w=start;
  preptr=w;
  while(w->data!=b)
  {
    preptr=w;
    w=w->ptr;
  }
  preptr->ptr=new_node;
  new_node->ptr=w;
  return start;
}
struct node *del_first()
{
  struct node *i;  //to point to the first node after shifting start to next element only to free up that node.
  i=start;
  start=start->ptr;
  printf("\nDeleting first element...\n");
  free(i);  //to free up the space taken by first node.
  return start;
}
struct node *del_last()
{
  struct node *o,*oppai;
  o=start;
  while(o->ptr!=NULL)
  {
    oppai=o;
    o=o->ptr;
  }
  oppai->ptr=NULL;
  free(o);
  printf("\nDeleting last element...\n");
  return start;
}
struct node *del_after()
{
  struct node *k,*l;
  int u;
  printf("\nEnter number whose next element you want to delete.\n");
  scanf("%d",&u);
  k=start;
  l=k;
  while(l->data!=u)
  {
    l=k;
    k=k->ptr;
  }
  l->ptr=k->ptr;
  free(k);
  return start;
}
struct node *sortit()
{
  struct node *ptr1,*ptr2;
  int temp;
  ptr1=start;
  while(ptr1->ptr!=NULL)
  {
    ptr2=ptr1->ptr;
    while(ptr2!=NULL)
    {
      if(ptr1->data>ptr2->data)
      {
        temp=ptr1->data;
        ptr1->data=ptr2->data;
        ptr2->data=temp;
      }
      ptr2=ptr2->ptr;
    }
    ptr1=ptr1->ptr;
  }
  printf("\n");
  return start;
}
int main()
{  printf("Entering elements in linked list.");
  list();
  printf("\nPrinting the elements. ");
  display();
  insert_beg();
  display();
  insert_end();
  display();
  insert_after();
  display();
  insert_before();
  display();
  del_first();
  display();
  del_last();
  display();
  del_after();
  display();
  sortit();
  display();
  return 0;
}
