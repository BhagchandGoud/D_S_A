#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#include<limits.h>

int largestSum(int*arr , int n){
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
         int prefixSum = 0;
         for (int j = i; j < n; j++)
         {
                prefixSum += arr[j];
                if (prefixSum > max)
                {
                 max = prefixSum;
                }
                
         }
         
    }
    return max;
}

int main(){
int arr[] = {4,-6,2,8};
int n  = 4;

int ans = largestSum(arr ,  n);
printf("%d" , ans);
    return 0;
}