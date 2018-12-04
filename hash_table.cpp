#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct pair{
  int val;
  int key;
  struct pair *next;
};
void display(struct pair arr[],int s)
{
  int i;
  printf("\tKey\t\tValue\n");
  for(i=0;i<s;i++)
  {
  printf("\t%d\t\t%d\n",arr[i].key,arr[i].val);
  struct pair *ptr;
  ptr=arr[i].next;
  while(ptr!=NULL)
  {
    printf("\t%d\t\t%d\n",ptr->key,ptr->val);
    ptr=ptr->next;
  }
  }
}
void search(struct pair arr[],int s)
{
  int n;
  printf("\nEnter the element to search: ");
  scanf("%d",&n);
  if(arr[n%s].val==n)
  printf("\nValue present at %d location.",n%s);
  else
  printf("\nValue not present.");
}
void insert(struct pair arr[],int s)
{
  int n;
  printf("\nEnter value to insert: ");
  scanf("%d",&n);
  if(arr[n%s].val==-1)
  arr[n%s].val=n;
  else
  {
    struct pair *yo;
    yo=(struct pair *)malloc(sizeof(struct pair));
    yo->val=n;
    yo->key=n%s;
    yo->next=NULL;
    arr[n%s].next=yo;
  }
}
int main()
{ int s,j=0;
  printf("Enter the size of the hash table: ");
  scanf("%d",&s);
  struct pair hash[s];
  while(j<s)
  {
    hash[j].val=-1;
    j++;
  }
  int i,temp;
  printf("\nEnter elements for the hash table: ");
  for(i=0;i<s;i++)
  {
    scanf("%d",&temp);
    hash[temp%s].val=temp;
    hash[temp%s].key=temp%s;
    hash[i].next=NULL;
  }
  display(hash,s);
  search(hash,s);
  insert(hash,s);
  display(hash,s);
  return 0;
}
