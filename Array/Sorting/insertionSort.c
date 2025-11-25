#include<stdio.h>
#include<stdlib.h>




void insertionSort(int *arr , int n){
    int start = 0;
    int end = n-1;
for (int i = 1; i < n; i++)
{
        int key = arr[i];
    int j = i-1;
while (j >= 0 && arr[j] > key)
{
   arr[j+1] = arr[j];
   j--;
}

arr[j + 1] = key; 
}
    
}





void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main(){
int arrLength;
printf("Enter length of array :");
scanf("%d" , &arrLength);
printf("Enter %d values in array  ", arrLength);
int *arr = (int*) malloc(arrLength*sizeof(int));
for (int i = 0; i < arrLength; i++)
{
    scanf("%d" , &arr[i]);
}
insertionSort(arr ,arrLength);
printf("After sorted :");
printArray(arr , arrLength);

}