#include<stdio.h>
#include<stdlib.h>
#define max 10
int st[max], top = -1, i;  //initially set to -1. will be incremented when elements r added to stack

void display(){
  printf("\nStack now :\n");
  for(i = top; i>=0; i--){
    printf("\t%d",st[i]);
  }
}

void push(int n){
  if (top == max-1){
    printf("Overflow\n");
  }
  else{
    st[++top] = n;  // put ++ before top else top is incremented after value is stored.
    printf("\nValue added to stack.");
    display();
  }
}

void pop(){
  if (top == -1){
    printf("Underflow\n");
  }
  else{
    top--;
    display();
  }
}

int peek(){
  if (top == -1){
    printf("\nUnderflow");
  }
  else{
    return st[top];
  }
}

int main(){
  int n;
  printf("Stack size : 10\n");
  printf("Enter -1 to stop.\nEnter elements in the stack\n");
  scanf("%d", &n);
  while(n != -1){
    st[++top] = n;
    scanf("%d", &n);
  }
  printf("\nFirst element poping from stack...");
  pop();
  printf("\nEnter element to push to stack : ");
  scanf("%d", &n);
  push(n);
  return 0;
}
