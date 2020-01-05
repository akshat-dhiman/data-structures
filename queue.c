#include<stdio.h>
#include<stdlib.h>
#define max 20
int queue[max], front = -1, rear = -1;

void insert(int n){
  if (rear == max - 1)
    printf("\nQueue Overflow");
  else if (front == -1 && rear == -1){  // this step is done to bring front n rear to 1st position.
    front = rear = 0;  //later front won't be changed only rear will move that's why this step done separately cause of front.
    queue[rear] = n;
  }
  else{
    queue[++rear] = n;
  }
}

void display(){
  if (front == -1 && rear == -1)
    printf("\nQueue is empty.");
  else{
    for(int i=front; i<=rear; i++)
      printf("\t%d", queue[i]);
  }
}

int delete(){
  if(front == -1 || rear<front)
    printf("\nQueue Underflow");
  else{
    return queue[front++];
  }
}

int main(){
  int n;
  printf("Enter atmost 20 elements in the queue.\n");
  printf("Enter -1 to stop.\n");  // it's better than taking fixed number of inputs
  scanf("%d", &n);
  while(n != -1){
    insert(n);  // call insert before scanning next item. This way unncessary -1 won't be added
    scanf("%d", &n);
  }
  display();
  printf("\nHow many elements u wanna delete...");
  int d;
  scanf("%d", &d);
  printf("\nElements are always deleted from front in a queue.");
  while(d>0){
    delete();
    d--;
  }
  display();
}
