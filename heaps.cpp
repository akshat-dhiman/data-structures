#include<stdio.h>
#include<stdlib.h>
void insert(int arr[],int n,int val)
{
  int pos,parent;
  pos=n;
  while(pos>0)
  {
    if(pos==n)
    parent=(pos-1)/2;
    else
    parent=pos/2;
    if(val<=arr[parent])
    {
      arr[pos]=val;
      return;
    }
    arr[pos]=arr[parent];
    pos=parent;
  }
  arr[0]=val;
  return;
}
int del_element(int arr[],int n)
{
  int first,last,p,left,right;
  first =arr[0];
  last=arr[n];
  p=0;
  left=1;
  right=2;
  n=n-1;
  while(right<=n)
  {
    if(arr[left]<=last&&arr[right]<=last)
    {
     arr[p]=last;
     return first;
    }
    else if(arr[left]>=arr[right])
    {
      arr[p]=arr[left];
      p=left;
    }
    else
    {
      arr[p]=arr[right];
      p=right;
    }
    left=2*p;
    right=2*p+1;
  }
  if(left==n&&arr[left]>last)
  {
   arr[p]=arr[left];
   p=left;
  }
  arr[p]=last;
   return first;
}
void display(int arr[],int n)
{
  int i;
  for(i=0;i<=n;i++)
   printf("\t%d",arr[i]);
}
int main()
{
  int a[20],n,val,c;
  printf("Enter no of elements you want to insert in the heap: ");
  scanf("%d",&n);
  int i;
  printf("\nEnter the elements now: ");
  for(i=0;i<n;i++)
   scanf("%d",&a[i]);
  printf("\nEnter the element you want to insert in this heap: ");
  scanf("%d",&val);
  insert(a,n,val);
  printf("\n");
  display(a,n);
  c=del_element(a,n);
  printf("\nDeleted element is: %d",c);
  printf("\n\n");
  display(a,n-1);
  return 0;
}
