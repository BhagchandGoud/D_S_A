#include<stdio.h>
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
    for (int i = top ; i >= 0; i--)
    {
        printf("%d " , stack[i]);
    }
    
}


void stockSpan(int*arr ,int n){
    int span[n];



for (int i = 0; i < n; i++)
{
    span[i] = 1;
    int count = 1;
  
while (top != -1 && arr[stack[top]] <= arr[i])
{  
    pop();
   count++;
}

    span[i] = count;

push(i);
}

for (int i = 0; i < n; i++)
{
   printf("%d " , span[i]);
}

    
}



int main(){
int arr[] = {100 ,80,60 ,120};
int n =  sizeof(arr)/sizeof(arr[0]);


 stockSpan(arr, n);
//  display();
    return 0;
}