#include<stdio.h>
#include<string.h>
#include <ctype.h>
#define max 100


char stack[max];
int top = -1;


void push(char val){
    if(top == max-1){
        return ;
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
    if (top == -1)
    {
        printf("Stack is Empty .");
        return;
    }
    
    for (int i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }
    
}
char* clearDigits(char *str , int length){
    for (int i = 0; i < length; i++)
    {
        if (!isdigit(str[i]))
        {
            push(str[i]);
        }
        
       else{
            pop();
        }
    }
    
}


int main(){
char str[] = "abc";
int length = strlen(str);
 clearDigits(str, length);
display();
    return 0;
}