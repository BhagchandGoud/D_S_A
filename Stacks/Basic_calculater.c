#include<stdio.h>
#include<string.h>
#define max 100

int stack[max];
int top = -1;


void push(int val){
    if (top == max-1)
    {
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
    for (int i = 0; i <= top; i++)
    {
        printf("%d " , stack[i]);
    }
    
}




void basicCalculater(char *str , int length){

 
}


int main(){

    return 0;
}