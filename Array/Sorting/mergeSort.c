#include<stdio.h>
#include<stdlib.h>

void merge(int*arr, int start ,int mid, int end){
    int L1 = mid-start+1;
    int L2 = end-mid;
    int a1[L1] , a2[L2];
    for (int i = 0; i < L1; i++)
    {
        a1[i] = arr[start+i];
    }
    for (int j = 0; j < L2; j++)
    {
        a2[j] = arr[mid+1+j];
    }

    int i = 0 ,j =0 ,k=start;

    while (i < L1 && j < L2)
    {
        if (a1[i] < a2[j])
        {
          arr[k++] = a1[i++];
        }
        else{
            arr[k++] = a2[j++];
        }
    }
       while (i < L1)
        {
          arr[k++] = a1[i++];
        }
        while (j < L2)
        {
            arr[k++] = a2[j++];
        }
    
}


void mergeSort(int *arr , int start , int end){
if (start < end)
{

int mid = start+(end-start)/2;
mergeSort(arr , start , mid);
mergeSort(arr , mid+1 , end);
merge(arr , start, mid , end);
}
}

int main(){
    int n;
    printf("Enter length of array :");
    scanf("%d" , &n);
printf("Enter %d values in array :" , n);
int *arr = (int*) malloc(n*sizeof(int));
for (int i = 0; i < n; i++)
{
    scanf("%d" ,&arr[i]);
}

int start = 0;
int end = n-1;

mergeSort(arr , start , end);
for (int i = 0; i < n; i++)
{
   printf("%d ", arr[i]);
}

    return 0;
}