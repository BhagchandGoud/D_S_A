#include<stdio.h>
#define max 100

int stack1[max], stack2[max];
int top1 = -1, top2 = -1;

void push1(int val){
    if(top1 == max-1) return;
    stack1[++top1] = val;
}

void push2(int val){
    if(top2 == max-1) return;
    stack2[++top2] = val;
}

int pop1(){
    if(top1 == -1) return -1;
    return stack1[top1--];
}

int pop2(){
    if(top2 == -1) return -1;
    return stack2[top2--];
}

void display1(){
    printf("Queue = ");
    for(int i = top1; i >= 0; i--){
        printf("%d ", stack1[i]);
    }
    printf("\n");
}

void enqueue(int val){

    while(top1 != -1){
        push2(pop1());
    }

    push1(val);
    while(top2 != -1){
        push1(pop2());
    }
}

void dequeue(){
    if(top1 != -1){
        pop1();
    }
}

int front(){
    if(top1 == -1) return -1;
    return stack1[top1];
}

int main() {

    enqueue(100);
    enqueue(300);
    enqueue(500);
dequeue();
    display1();   

    return 0;
}
