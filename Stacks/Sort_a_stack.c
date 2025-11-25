#include<stdio.h>
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
    for (int i = top; i >= 0 ; i--)
    {
        printf("%d " , stack[i]);
    }
    
}


void sortStack(int n){
int tempStack[n];
int tempTop = -1;
while (top != -1)
{
    int currElement = pop();
    while (tempTop != -1 && tempStack[tempTop] > currElement)
    {
        push(tempStack[tempTop]);
       tempStack[tempTop--];
    }
    tempStack[++tempTop] = currElement;
}

 while (tempTop  != -1 )   {
       push(tempStack[tempTop]);
       tempStack[tempTop--];
    }

}



int main(){
int arr[] = {34, 3, 31, 98, 92, 23};
int n = sizeof(arr)/sizeof(arr[0]);

for (int i = 0; i < n; i++)
{
   push(arr[i]);
}

sortStack(n);

display();
    return 0;
}