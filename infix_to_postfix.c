#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define max 20
int stk[max], top = -1;

void push(char op){
  if (top == max - 1)
    printf("\nOverflow");
  else
    stk[++top] = op;
}

int pop(){
  if (top == -1)
    printf("\nUnderflow");
  else
    return stk[top--];
}

int priority(char op){
  if (op == '+' || op == '-')
    return 0;
  else if (op == '/' || op == '%' || op == '*')
    return 1;
}
void infix_to_postfix(char source[], char target[]){
  int i = 0, j = 0;
  char temp;
  while(source[i] != '\0'){
    if (source[i] == '('){
      push(source[i]);
      i++;
    }
    else if (source[i] == ')'){
      while(top != -1 && stk[top] != '('){
        target[j] = pop();
        j++;
      }
      if (top == -1){
        printf("\nWrong Expression");
        exit(1);
      }
      temp = pop();
      i++;
    }
    else if (source[i] == '+' || source[i] == '/' || source[i] == '%' || source[i] == '-' || source[i] == '*'){
      while(top != -1 && stk[top] != '(' && priority(stk[top]) >= priority(source[i])){
        target[j] = pop();
        j++;
      }
      push(source[i]);
      i++;
    }
    else if (isalpha(source[i]) || isdigit(source[i])){
      target[j] = source[i];
      j++;
      i++;
    }
    else{
      printf("\nWrong Expression");
      exit(1);
    }
  }
  while(top != -1 && stk[top] != '('){
    target[j] = pop();
    j++;
  }
}

int main(){
  char infix[20], postfix[20];
  strcpy(postfix, "");
  printf("Enter the infix expression : ");
  gets(infix);
  infix_to_postfix(infix, postfix);
  printf("\nThe postfix expression is : ");
  puts(postfix);
  return 0;
}
