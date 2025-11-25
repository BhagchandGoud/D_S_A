#include<stdio.h>
#define max 100

int stack[max];
int top = -1;

void push(int val){
    if (top == max-1) return;
    stack[++top] = val;
}

int pop(){
    if (top == -1) return -1;
    return stack[top--];
}

void nextSmallerElement(int*arr , int n){
    int ans[n];
    for (int i = 0; i < n; i++)
    {
        ans[i] = -1;
        while (top != -1 && arr[stack[top]] > arr[i])
        {
           ans[stack[top]] = arr[i];
           pop();
        }
        
        push(i);
    }

        for(int i = 0; i < n; i++){
        printf("%d ", ans[i]);
    }
    
}



int main(){
    int arr[] = {1, 3, 2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    nextSmallerElement(arr,n);
    return 0;
}