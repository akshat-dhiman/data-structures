#include<stdio.h>
#include<stdlib.h>
#define max 20
int stk[max],top=-1;
void push(char x)
{
  if(top==max-1)
  printf("\nOverflow");
  else
  stk[++top]=x;
}
char pop()
{
  if(top==-1)
  printf("\nUnderflow");
  else
  return stk[top--];
}
int main()
{
  int val,i,c=0;
  char s[max];
  printf("Enter an expression: ");
  scanf("%s",s);
  for(i=0;i<strlen(s);i++)
  {
    if(s[i]=='('||s[i]=='{'||s[i]=='[')
    push(s[i]);
    else if(s[i]==')'||s[i]=='}'||s[i]==']')
    {
    if(top==-1)
    c++;
    else
    {
    val=pop();
    if(s[i]==')'&&(val=='{'||val=='['))
    c++;
    else if(s[i]=='}'&&(val=='('||val=='['))
    c++;
    else if(s[i]==']'&&(val=='('||val=='{'))
    c++;
  }
}
  }
  if(c==0)
  printf("\nPerfect Expression.");
  else
  printf("\nThere are %d many mistakes in the given expression.",c);
  return 0;
}
