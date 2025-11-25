#include<stdio.h>
#define max 100

int arr[max];
int n = max;

int top1 = -1;
int top2 = max;


void push1(int val){
if (top1 < (n/2+1) )
{
    top1++;
    arr[top1] = val;
}
else{
    return;
}

    
}

void push2(int val){
if (top2 > (n/2))
{
    top2--;
    arr[top2]  = val;
}
else{
    return;
}

}


int pop1(){
if (top1 >= 0)
{
   int val = arr[top1];
   top1--;
   return val;
}
else{
    return -1;
}

}

int pop2(){
if (top2 < n)
{
    int val = arr[top2];
    top2++;
    return val;
}

else{
    return -1;
}

}




void stackToArr(){


push1(2);
    push1(3);
    push2(4);

    printf("[%d, %d, %d]\n", pop1(), pop2(), pop2());

    
}

int main(){
 stackToArr();

    return 0;
}