#include<stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int k=0;
    for(int i= 0; i<numsSize;i++){
        if(nums[i] != val){
nums[k++] = nums[i];
        }
    }
return k; 
}

int main(){
int nums[] = {0,1,2,2,3,0,4,2};
int numsSize = sizeof(nums)/sizeof(nums[0]);
int val = 2;
    removeElement(nums,  numsSize, val);
    return 0;
}