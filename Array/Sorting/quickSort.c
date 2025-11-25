#include<stdio.h>
#include<stdlib.h>


int partition(int*arr , int start , int end){
int index = start-1;
int pivot = arr[end];
for (int i = start; i < end; i++)
{
   if(arr[i] <= pivot){
    index++;
    int temp = arr[i];
    arr[i] = arr[index];
    arr[index] = temp;
   }
}

index++;
  int temp = arr[end];
    arr[end] = arr[index];
    arr[index] = temp;


return index;
}



void quickSort(int *arr , int start, int end){
    if (start < end)
    {
    int pivot = partition(arr , start , end);
quickSort(arr , start ,pivot-1);
quickSort(arr , pivot+1 , end);
    }
    

}



int main(){
int arrLength ;
printf("Enter length of array :");
scanf("%d" , &arrLength);

int *arr = (int*) malloc(arrLength * sizeof(int));
printf("Enter %d values in array :" , arrLength);
for (int i = 0; i < arrLength; i++)
{
  scanf("%d" , &arr[i]);
}

int start = 0;
int end = arrLength-1;


quickSort(arr , start, end);
printf("After sorted :");
for (int i = 0; i < arrLength; i++)
{
    printf("%d " , arr[i]);
}

    return 0;
}