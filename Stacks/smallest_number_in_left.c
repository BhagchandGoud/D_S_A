#include<stdio.h>
#define max 100

int stack[max];
int top = -1;


void push(int val){
    if (top ==max -1)
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
    for (int i = top; i >= 0 ; i--)
    {
       printf("%d " , stack[i]);
    }
    
}


void smallestLeft(int *arr , int n){
int left[n];

for (int i = n-1; i >= 0; i--)
{
    left[i] = -1;

    while (top != -1 && arr[stack[top]] < arr[i])
    {
        push(arr[i]);
    }
    
}


}


int main(){


    return 0;
}