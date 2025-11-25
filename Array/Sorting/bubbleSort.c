#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int *arr , int n){
    for (int i = 0; i < n; i++)
    {
      for (int j = i+1; j < n-1; j++)
      {
       if(arr[i] > arr[j]){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
       }
      }
      
    }
    return;
}

void printArray(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
int arrLength ;
printf("Enter length of array :");
scanf("%d" , &arrLength);
printf("Enter %d values in array  :" , arrLength);
int *arr = (int*) malloc(arrLength*sizeof(int));
for (int i = 0; i < arrLength; i++)
{
 scanf("%d" , &arr[i]);
}

bubbleSort(arr ,arrLength);
printf("Sorted array is :");
printArray(arr , arrLength);
    return 0;
}