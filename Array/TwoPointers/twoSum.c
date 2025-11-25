#include<stdio.h>
#include<stdlib.h>


void twoSum(int*arr , int n){
    int start = 0, end = n-1;
   int target;
   printf("Enter target value :");
   scanf("%d" , &target);

    while (start< end)
    {
        int sum = arr[start]+arr[end];
        if (sum == target)
        {
            printf("[%d , %d] sum is equal to target %d" , arr[start] , arr[end] , sum);
     return;
        }
        else if (sum < target)
        {
            start++;
        }
        else{
            end--;
        }
    }
    printf("No pair found!\n");
}


int main(){

int arrLength;
printf("Enter length of array :");
scanf("%d" , &arrLength);
int *arr = (int*) malloc(arrLength*sizeof(int));
printf("Enter %d values in array :" , arrLength);
for (int i = 0; i < arrLength; i++)
{
    scanf("%d" , &arr[i]);
}
twoSum(arr ,  arrLength) ;
    return 0;
}