#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#define max 100

int stack[max];
int top = -1;


void push(int val){
    if (top == max-1)
    {
     return;
    }
    stack[++top] = val;
    
}

int pop(){
    if (top == -1)
    {
        return -1;
    }
    
    return stack[top--];
}



void display(){
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    
}


void  baseBallGame(char*arr [] , int length){

for (int i = 0; i<length ; i++)
{
   if (strcmp(arr[i], "+") == 0)
   {
    push(stack[top]+stack[top-1]);
 
   }
   else if (strcmp(arr[i], "D") == 0)
   {
   push(stack[top]*2);
   }
   else if (strcmp(arr[i], "C") == 0)
   {
    pop();
   }
   else {
            int num = atoi(arr[i]);
            push(num);
        }

}

int sum = 0;
for (int i = 0; i < top; i++)
{
    sum += stack[i];
}

printf("\n%d" , sum);
}


int main(){
char *arr[] = {"5","-2","4","C","D","9","+","+"};
    int length = sizeof(arr)/sizeof(arr[0]);
  baseBallGame(arr ,length);

    return 0;
}