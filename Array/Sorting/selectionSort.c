#include<stdio.h>
#include<stdlib.h>

void selectionSort(int*arr , int n){
    int minIndex;
for (int i = 0; i < n; i++)
{
  minIndex = i;
for (int j = i+1; j < n; j++)
{
     if (arr[j] < arr[minIndex])
  {
    minIndex = j;
  }
  
}

if (minIndex != i)
{
   int temp = arr[minIndex];
   arr[minIndex] = arr[i];
   arr[i] = temp;
}


}

}

void printArray(int*arr , int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
}

int main(){
int arrLength;
printf("Enter length of array :");
scanf("%d" , &arrLength);

printf("Enter %d values in array :" , arrLength);
int *arr = (int*) malloc(arrLength * sizeof(int));

for (int i = 0; i < arrLength; i++)
{
    scanf("%d" , &arr[i]);
}

selectionSort(arr , arrLength);
printf("After sorted :");
printArray(arr ,arrLength);

    return 0;
}