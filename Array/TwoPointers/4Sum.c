#include<stdio.h>
#include<stdlib.h>
#include<String.h>
#include<ctype.h>
#include<stdbool.h>


void merge(int*arr ,int start ,int mid ,int end){
    int n1 = mid-start+1;
    int n2 = end-mid;
    int left[n1] , right[n2];
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[start+i];
    }
     for (int j = 0; j < n2; j++)
    {
        right[j] = arr[mid+j+1];
    }
    int i =0  ,j = 0 ,k= start;
    while (i<n1  && j <n2)
    {
        if (left[i] < right[j])
        {
           arr[k++] = left[i++];
        }
        else{
             arr[k++] = right[j++];
        }
    }
    while (i<n1)
    {
       arr[k++] = left[i++];
    }
    while (j<n2)
    {
        arr[k++] = right[j++];
    }
    
    
}

void mergeSort(int *arr ,int start ,int end){
    if(start>=end) return;
    int mid = start+(end-start)/2;
    mergeSort(arr, start ,mid);
    mergeSort(arr,mid+1, end);
    merge(arr, start ,mid,end);

}



int** fourSum(int* nums, int n, int target, int* returnSize, int** returnColumnSizes) {
    int start = 0;
    int end = n-1;
int *ans = (int*) malloc(4*sizeof(int*)); 
    for (int i = 0; i < n-1; i++)
    {
            int start = i+1;
    int end = n-1;
while (start < end)
{
   int sum = nums[start]+nums[i+1]+nums[i+2]+nums[end];

   if (sum == target)
   {
    // ans [0 , 1 ,2 ,3] = {nums[start] ,nums[i] , nums[i+2] , nums[end]}  ;
   }
   else if (sum < target)
   {
    start++;
   }
   else{
    end--;
   }
   

}


    }
    
}



int main(){
int arr[] = {1,0,-1,0,-2,2};
int n = sizeof(arr)/sizeof(arr[0]);
mergeSort(arr ,0 ,n-1);
for (int i = 0; i < n; i++)
{
    printf("%d ",arr[i]);
}

    return 0;
}