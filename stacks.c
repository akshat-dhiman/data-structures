#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define max 3
int st[max],top=-1;
void push()
{  int n;
  if(top==max-1)
  printf("\nOverflow");
  else
  {
    scanf("%d",&n);
    top++;
    st[top]=n;
  }
}
int pop()
{  int n;
  if(top==-1)
  printf("\nUnderflow");
  else
  {
    n=st[top];
    top--;
  }
  return n;
}
int peek()
{
  if(top==-1)
  printf("Underflow");
  else
  return st[top];
}
void display()
{
  int i;
  for(i=top;i>=0;i--)
   printf("\n%d",st[i]);
}
int main()
{
  printf("Enter 3 elements in stack: ");
  int i=3;
  while(i>0)
  {
    push();
    i--;
  }
  printf("Poped element: %d",pop())``;
  printf("\nAfter poping the topmost:\n");
  display();
}
