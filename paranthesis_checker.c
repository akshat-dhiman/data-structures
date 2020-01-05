#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 20
int stk[max], top = -1;
void push(char c){
  if(top == max - 1){
    printf("\nStack Overflow");
  }
  else{
    stk[++top] = c;
  }
}

int pop(){
  if(top == -1){
    printf("\nStack Underflow");
  }
  else{
    return stk[top--];  // -- after top so that top value is returned first and top decremented later
  }
}

int main(){
  char exp[max], temp;
  int i, flag = 1;
  printf("\t\tParanthesis Checker\n");
  printf("Enter the expression...\t\t");
  gets(exp);
  for(i =0; i<strlen(exp); i++){
    if (exp[i] == '[' || exp[i] == '{' || exp[i] == '('){
      push(exp[i]);
    }
    if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']'){
      if (top == -1)  // if stack is already empty & we did encounter closing bracket first
        flag = 0;  // flag 0 means mistake
      else{
        temp = pop();
        if(temp == '{' && (exp[i] == ')' || exp[i] == ']'))
          flag = 0;
        if(temp == '[' && (exp[i] == ')' || exp[i] == '}'))
          flag = 0;
        if(temp == '(' && (exp[i] == '}' || exp[i] == ']'))
          flag = 0;
      }
    }
  }
  if (top >= 0)
    flag = 0;
  if (flag == 0)
    printf("\n\tWrong Expression");
  if (flag == 1)
    printf("\n\tCorrect Expression");
  return 0;
}
