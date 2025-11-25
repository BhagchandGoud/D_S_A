#include<stdio.h>
#include<stdlib.h>


int binarySearch(int *arr , int n){
    int start = 0;
    int end = n-1;
int target;
printf("Enter searching value :");
scanf("%d" , &target);
    while (start<=end)
    {
      int mid = start+(end-start)/2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
    }

    return -1;
    
}

int main(){

    int arrLength;
    printf("Enter length of array to insert values :");
    scanf("%d" , &arrLength);
    printf("Enter %d values in array :" , arrLength);
    int *arr = (int*) malloc(arrLength *sizeof(int));
    for (int i = 0; i < arrLength; i++)
    {
       scanf("%d" , &arr[i]);
    }
    
    int search = binarySearch(arr, arrLength);
    if (search != -1)
    {
       printf("Element found at index %d\n", search);
    }
    else
    {
        printf("Element not found\n");
    }

    free(arr);
    

    return 0;
}