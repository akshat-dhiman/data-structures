#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  int priority;
  struct node *next;
};
struct node *start = NULL;
struct node *new_node, *p;

/* First make a normal list with priority & data then arrange it on basis of priority.*/

void priority_list_create(){
  int n, pr;
  printf("Enter data & it's priority : ");
  scanf("%d %d", &n, &pr);
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = n;
  new_node->priority = pr;
  if(start == NULL){
    start = new_node;
    p = start;
    new_node->next = NULL;
  }
  else{
    p->next = new_node;
    p = new_node;
    new_node->next = NULL;
  }
}

void display(){
  struct node *q;
  q = start;
  while(q != NULL){
    printf("\t(%d, %d)", q->data, q->priority);
    q = q->next;
  }
}

void priority_list_arrangement(){
  struct node *temp, *p, *q;
  p = start;
  while(p->next != NULL){
    q = p->next;
    while(q != NULL){
      if(p->priority > q->priority){
        temp->data = p->data;
        temp->priority = p->priority;
        p->data = q->data;
        p->priority = q->priority;
        q->data = temp->data;
        q->priority = temp->priority;
      }
      q = q->next;
    }
    p = p->next;
  }
}

int main(){
  int a = 5;
  while(a > 0){
    priority_list_create();
    a--;
  }
  printf("\nThe irregular list is: ");
  display();
  printf("\nThe priority wise arranged list is: ");
  priority_list_arrangement();
  display();
  return 0;
}
