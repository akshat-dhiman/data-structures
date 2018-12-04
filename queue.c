#include<stdio.h>
#include<stdlib.h>
#define max 20
int q[max],rear=-1,front=-1;
void insert()
{  int n;
  printf("\nEnter -1 to stop.\nMax limit is 20 elements.");
  printf("\nEnter numbers in queue: ");
  scanf("%d",&n);
  if(front==-1&&rear==-1)
    front=0;
  while(n!=-1)
  {
    if(rear==max-1)
    {
      printf("\nOverflow");
      exit(1);
    }
    else
    {
        rear+=1;
      q[rear]=n;
    }
    scanf("%d",&n);
  }
}
void display()
{
  printf("\nThe elelments in the queue are: ");
  for(int i=front;i<rear+1;i++)
    printf("\t%d",q[i]);
}
int del()
{  int val;
  val=front;
  if(front==-1||front>rear)
  {
    printf("\nUnderflow");
    exit(1);
  }
  else
{
  front+=1;
  return q[val];
}
}
int main()
{
  int n;
  insert();
  display();
  printf("\nHow many elelments you want to delete? : ");
  scanf("%d",&n);
  printf(front);
  while(n>0)
  {
    del();
    n--;
  }
  display();
  return 0;
}
