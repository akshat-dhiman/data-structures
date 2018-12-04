#include<stdio.h>
#include<stdlib.h>
#define max 5
int q[max],front=-1,rear=-1;
void insert()
{  int n;
  printf("\nEnter -1 to stop.");
  printf("\nEnter the elements to add in queue: ");
  scanf("%d",&n);
  if(front==-1&&rear==-1)
    front=0;
  while(n!=-1)
  {
    if(rear==max)
    {
      printf("\nOverflow");
      exit(1);
    }
    else if(front!=0&&rear==max-1)
    {
      rear=0;
      q[rear]=n;
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
  int i;
  if(front==-1&&rear==-1)
  printf("\nUnderflow");
  else
  {
    printf("\nDisplaying elements: ");
    if(front<rear)
    {
      for(i=front;i<=rear;i++)
      printf("\t%d",q[i]);
    }
    else
    {
      for(i=front;i<max;i++)
      printf("\t%d",q[i]);
      for(i=0;i<=rear;i++)
      printf("\t%d",q[i]);
    }
  }
}
void del()
{
  if(front==-1&&rear==-1)
  {
    printf("\nUnderflow");
    exit(1);
  }
  else
  {
    if(front==rear)
    {
      front=-1;
      rear=front;
    }
    else if(front==max-1)
    front=0;
    else
    front+=1;
  }
}
int main()
{
  int n;
  insert();
  display();
  printf("\nHow many elements you wanna delete? : ");
  scanf("%d",&n);
  while(n>0)
  {
    del();
    n--;
  }
  insert();
  display();
  return 0;
}
