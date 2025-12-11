#include<stdio.h>


int prefixSum(int*arr , int n){
    int totalSum = 0;
    int prefixSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum +=arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        if (totalSum-prefixSum == prefixSum)
        {
            
        }
        
    }
    
    
}

int main(){

    return 0;
}