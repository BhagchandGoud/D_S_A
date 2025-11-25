#include<stdio.h>
#include<stdlib.h>

int *removeDuplicates(int arr[] , int n ,int *newSize){

int j = 0;
int *newArray = (int*) malloc(n*sizeof(int));
  newArray[j++] = arr[0];
for (int i = 1; i < n; i++)
{
 if (arr[i] != arr[i-1])
 {
   newArray[j++] = arr[i];
 }

}


*newSize = j;
return newArray; 
}

int main(){

    int n = 9;
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5};
 int newSize;

    int *unique = removeDuplicates(arr, n, &newSize);

    for (int i = 0; i < newSize; i++) {
        printf("%d ", unique[i]);
    }
    return 0;
}