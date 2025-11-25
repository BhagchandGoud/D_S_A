#include <stdio.h>
#include <stdlib.h>
#include<math.h>

void merge(int *arr ,int start ,int mid ,int end){
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
 int i = 0 ,j =0 ,k = start;
    while (i<n1 && j<n2)
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
    while (j < n2)
    {
         arr[k++] = right[j++];
    }

}







void mergeSort(int *arr , int start , int end){
    if (start >= end) return;
int mid = start+(end-start)/2;
    mergeSort(arr , start , mid);
    mergeSort(arr , mid+1 ,end);
    merge(arr ,start ,mid, end);
}




int threeSumClosest(int *nums, int numsSize, int target)
{
    int closest = nums[0]+nums[1]+nums[2];
    
    for (int i = 0; i < numsSize - 2; i++) {
            int start = i+1;
    int end = numsSize - 1;
    while (start < end)
    {
        int sum = nums[start] + nums[i] + nums[end];
        if (abs(target - sum) <abs(target - closest))
        {
            closest = sum;
        }
     else  if (sum > target)
        {
            start++;
        }
        else  if (sum < target)
        {
            end--;
        }
        else{
               return sum;
        }
    }
}
    return closest;
}

int main()
{

    int nums[] = {-1, 2, 1, -4};
    int numsSize = 4;
    int target = 1;
    mergeSort(nums, 0, numsSize-1);

    //        for (int i = 0; i < numsSize; i++){
    
    //     printf("%d ", nums[i]);
    // }
     int ans =   threeSumClosest(nums, numsSize, target);
     
        printf("%d ", ans);

    return 0;
}