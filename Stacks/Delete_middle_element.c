#include<stdio.h>
#define max 100

int stack[max];
int top = -1;
    int newStack[max];
   int newTop = -1;

void push(int val){
    if (top == max-1)
    {
        return ;
    }
    stack[++top] = val;
    
}

void push1(int val){
    if (newTop == max-1)
    {
        return ;
    }
   newStack[++newTop] = val;
    
}

int pop(){
    if (top == -1)
    {
       return -1;
    }

    return stack[top--];
    
}


void display(){
    printf("Stack elements are :");
    for (int i = top; i >= 0 ; i--)
    {
        printf("%d " , stack[i] );
    }
    
}




int deleteMiddle(){
    int mid = top/2;

 while (top > mid)
 {
   int p = pop();
   push1(p);
 }

 pop();
 
  while (top != -1)
 {
   int p = pop();
   push1(p);
 }


}

void newDisplay(){
            for (int i =newTop; i >= 0 ; i--)
    {
        printf("%d " , newStack[i] );
    }
}
int main(){
push(10);
push(20);
push(30);
push(40);
push(50);
deleteMiddle();
// display();
newDisplay();
    return 0;
}