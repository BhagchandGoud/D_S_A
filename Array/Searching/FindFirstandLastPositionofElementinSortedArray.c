#include<stdio.h>
#include<stdlib.h>

int leftSearch(int*arr , int n , int target){
    int start = 0 ,end = n-1;
    int left;
    while (start <= end)
    {
        int mid = start+(end-start)/2;
        if(arr[mid] == target){
              end = mid-1;
        }
        else if (arr[mid] < target)
        {
            
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        
    }
}

int rightSearch(int*arr , int n , int target){
    int start = 0 ,end = n-1;
    int right;
    while (start <= end)
    {
        int mid = start+(end-start)/2;
        if(arr[mid] == target){
           return mid;
        }
        else if (arr[mid] < target)
        {
            start = mid+1;
        }
        else{

            end = mid-1;
        }
        
    }

}


int main(){
int arr[] = {5,7,7,8,8,10};
int n = sizeof(arr) /sizeof(arr[0]);
int target = 8;
int left = leftSearch(arr ,n, target);
printf("%d",left);
int right = rightSearch(arr ,n, target);
printf("%d",right);
   int *store = (int*) malloc(2*sizeof(int));

    store[0] = -1,store[1] = -1;
      store[0] = left;
        store[1] = right;
    return 0;
}