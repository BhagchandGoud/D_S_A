#include <stdio.h>
#include<limits.h>
#define max 100

int stack[max] ;
int top = -1;



void push(int val){
    if (top ==  max-1)
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
    for (int i = top; i >= 0; i--)
    {
        printf("%d "  , stack[i]);
    }
    
}


void maxNumber(int *arr1 , int*arr2 , int n1 , int n2){
    int k = 5;
int length = n1+n2;
   int newArr[length];
   int j  = 0;
   for (int i = 0; i < n1; i++)
   {
    newArr[j++] = arr1[i];
   }
      for (int i = 0; i < n2; i++)
   {
    newArr[j++] = arr2[i];
   }
   


for (int i = 0; i < length; i++)
{
    int maxN = INT_MIN;
   if (newArr[i] > maxN)
   {
    maxN = newArr[i];
    while (top < k)
    {
        push(maxN);
    }
    
   }
   
}

    }




     
        


int main(){
 int arr1[] = {3,4,6,5};
 int arr2[] = {9,1,2,5,8,3};
 int n1 = sizeof(arr1) / sizeof(arr1[0]);
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
maxNumber(arr1 , arr2 ,  n1 ,  n2);
display();
    return 0;
}