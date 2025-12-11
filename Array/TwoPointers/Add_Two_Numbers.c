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

void display(){
    for (int i = 0; i <=top; i++)
    {
        printf("%d ", stack[i]);
    }
    
}

int main(){
int nums1 []= {9,9,9,9,9,9,9};
int nums2[] = {9,9,9,9};
int s1 = sizeof(nums1)/sizeof(nums1[0]);
int s2 = sizeof(nums2)/sizeof(nums2[0]);
int i = 0 ,j =0;
    int carry =0;
while(i < s1 && j < s2){

    int sum = 0;
    sum += nums1[i]+nums2[j]+carry;

             carry = sum/10;
             sum = sum%10;

        push(sum);
i++ ,j++;
}

display();

return 0;
}