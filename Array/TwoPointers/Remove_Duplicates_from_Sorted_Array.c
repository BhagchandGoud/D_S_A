#include<stdio.h>
#include<ctype.h>
int removeDuplicates(int* nums, int numsSize){
    if (numsSize == 0) return 0;
    int k = 1;
for ( int i = 1; i < numsSize; i++)
{
    if (nums[i] != nums[i-1])
    {
        nums[k++] = nums[i];
    }
}

return k;
}


int main(){
int arr [] = {1,1,2};
int n = sizeof(arr)/sizeof(arr[0]);
int ans = removeDuplicates( arr, n);
printf("%d" ,ans);

    return 0;
}