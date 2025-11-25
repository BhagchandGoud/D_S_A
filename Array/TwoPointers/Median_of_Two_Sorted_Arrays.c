#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include<string.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int n = nums1Size+nums2Size;
int *arr = (int*) malloc(n * sizeof(int));
int i = 0,j =0 ,k =0;
while(i < nums1Size &&  j < nums2Size){
if(nums1[i] <= nums2[j]){
    arr[k++] = nums1[i++];
}
else{
    arr[k++] = nums2[j++];
}
}
while(i < nums1Size){
    arr[k++] = nums1[i++];
}
while( j < nums2Size){
    arr[k++] = nums2[j++];
}
int sum = 0;
for(int m = 0 ; m < n ; m++){
sum+=arr[m];
}
double median;
if(sum%2 == 0){
median =  (arr[n / 2 - 1] + arr[n/ 2]) / 2.0;
}
else{
    median =  arr[n / 2 ];
}

return median;
}


int main(){
int nums1[] = {1,2};
int nums2[] = {3,4};
int nums1Size  = sizeof(nums1)/sizeof(nums1[0]);
int nums2Size = sizeof(nums2)/sizeof(nums2[0]);
double ans = findMedianSortedArrays( nums1,  nums1Size, nums2, nums2Size);
 printf("%2f " , ans);
    return 0;
}