#include<stdio.h>
#include<stdlib.h>
#define max 30
int stk[max],top=-1;
char pfix[max];
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
int priority(char x)
{
  if(x=='%'||x=='*'||x=='/')
  return 1;
  else if(x=='+'||x=='-')
  return 0;
}
void convert(char infix[])
{
  int i=0,j=0;
  char temp;
  while(infix[i]!='\0')
  {
    if(infix[i]=='(')
    {
      push(infix[i]);
      i++;
    }
    else if(infix[i]==')')
    {
      while(top!=-1&&stk[top]!='(')
      {
        pfix[j]=pop();
        j++;
      }
      if(top==-1)
      {
        printf("\nWrong expression.");
        exit(1);
      }
      temp=pop();
      i++;
    }
    else if(isdigit(infix[i])||isalpha(infix[i]))
    {
      pfix[j]=infix[i];
      j++;
      i++;
    }
    else if(infix[i]=='+'||infix[i]=='*'||infix[i]=='%'||infix[i]=='/'||infix[i]=='-')
    {
      while(top!=-1&&stk[top]!='('&&priority(stk[top])>priority(infix[i]))
      {
        pfix[j]=pop();
        j++;
      }
      push(infix[i]);
      i++;
    }
    else
    {
      printf("\nInvalid expression.");
      exit(1);
    }
  }
  while(top!=-1&&stk[top]!='(')
  {
    pfix[j]=pop();
    j++;
  }
  printf("\nConverted postfix expression is: %s",pfix);
}
int main()
{
  char infix[max];
  printf("\nEnter the infix expression: ");
  scanf("%s",infix);
  strcpy(pfix,"");
  convert(infix);
  return 0;
}
