#include<stdio.h>
#include<stdlib.h>
#define max 10
int front = -1, rear = -1, queue[max];
void insert(int n){
  if ((front == 0 && rear == max -1) || (rear == front-1))
    printf("\nOverflow");
  else if (front != 0 && rear == max - 1){
    rear = 0;
    queue[rear] = n;
  }
  else if (front == -1 && rear == -1){
    front = rear = 0;
    queue[rear] = n;
  }
  else if (rear != max - 1)
    queue[++rear] = n;
}

void delete(){
  if (front == -1 && rear == -1)
    printf("\nUnderflow");
  else if (front == rear)
    front = rear = -1;
  else if (front == max -1)
    front = 0;
  else
    front++;
}

void display(){
  if  (rear < front){
    for(int i=front;i<max;i++)
      printf("\t%d", queue[i]);
    for(int i=0;i<=rear;i++)
      printf("\t%d", queue[i]);
  }
  else{
    for(int i=front;i<=rear;i++)
      printf("\t%d", queue[i]);
  }
}

int main(){
  printf("Enter not more than 10 elements in the circular queue.\n");
  printf("Enter -1 to stop.\n");
  int n;
  scanf("%d", &n);
  while(n != -1){
    insert(n);
    scanf("%d", &n);
  }
  printf("\nValues inserted.");
  printf("\nElements added to Circular queue.");
  display();
  delete();
  printf("\nFirst element deleted from queue.")
  insert(3);
  printf("\n3 inserted in circular queue.");
  display();
  return 0;
}
