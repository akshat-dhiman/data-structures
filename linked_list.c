#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
  int data;
  struct node *next;   // pointing to next node
};
struct node *start = NULL;

struct node *list(){
  struct node *new, *p;
  int n;
  printf("Enter -1 to stop.\nEnter the elements:\n");
  scanf("%d", &n);
  while(n != -1)
  {
    new = (struct node *)malloc(sizeof(struct node));  // malloc returns a pointer pointing to new space created by it
    new->data = n;
    if (start == NULL)
    {
      start = new;
      p = start;
      new->next = NULL;
    }
    else{
      p->next = new;
      p = new;
      new->next = NULL;
    }
    scanf("%d",&n);
  }
  return start;
}

struct node *display(){
  struct node *q;
  q = start;
  while(q != NULL)
  {
    printf("\t%d", q->data);
    q = q->next;
  }
}

struct node *insert_beg(int n){
  printf("Element inserted at start of list");
  struct node *new_node;
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = n;
  new_node->next = start;
  start = new_node;
  return start;
}

struct node *insert_end(int n){
  printf("\nElement inserted at end of list");
  struct node *new_node, *p;
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = n;
  new_node->next = NULL;
  p = start;
  while(p->next != NULL)
  {
    p = p->next;
  }
  p->next = new_node;
  return start;
}

struct node *insert_after(int n){
  int b;
  printf("\nEnter element after which u want to insert : ");
  scanf("%d",&b);
  struct node *new_node, *prev, *p;
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = n;
  p = start;
  prev = p;
  while(prev->data != b){
    prev = p;
    p = p->next;
    if (p == NULL)
    {
      printf("\nElement not found!");
    }
  }
  prev->next = new_node;
  new_node->next = p;
  return start;
}

struct node *insert_before(int n){
  int b;
  printf("\nElement before which u want to insert : ");
  scanf("%d",&b);
  struct node *new_node, *prev, *p;
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = n;
  p = start;
  prev = p;
  while(p->data != b){
    prev = p;
    p = p->next;
    if (p == NULL)
    {
      printf("Element not found!");
    }
  }
  prev->next = new_node;
  new_node->next = p;
  return start;
}

struct node *del_first(){
  struct node *p;
  p = start;
  start = start->next;
  printf("\nDeleting first element...");
  free(p);
  return start;
}

struct node *del_last(){
  struct node *p, *q;
  p = start;
  q = p;
  while(p->next != NULL){
    q = p;
    p = p->next;
  }
  printf("\nDeleting last element...");
  free(p);
  q->next = NULL;
  return start;
}

struct node *del_after(){
  struct node *prev, *p;
  p = start;
  prev = p;
  printf("\nElement after which u want to delete : ");
  int n;
  scanf("%d", &n);
  while(prev->data != n){
    prev = p;
    p = p->next;
  }
  prev->next = p->next;
  free(p);
  return start;
}

struct node *sort(){
  printf("\n\nSorted List-->");
  struct node *p, *q;
  int temp;
  p = start;
  while(p->next != NULL){
    q = p->next;
    while(q != NULL){
      if (p->data > q->data){
        temp = p->data;
        p->data = q->data;
         q->data = temp;
      }
      q = q->next;
    }
    p = p->next;
  }
  return start;
}

int main()
{
  int n;
  list();
  printf("Displaying elements in list\n");
  display();
  printf("\nEnter element to insert: ");
  scanf("%d", &n);
  insert_beg(n);
  display();
  insert_end(n);
  display();
  insert_after(n);
  display();
  insert_before(n);
  display();
  del_first();
  display();
  del_last();
  display();
  del_after();
  display();
  sort();
  display();
  return 0;
}
