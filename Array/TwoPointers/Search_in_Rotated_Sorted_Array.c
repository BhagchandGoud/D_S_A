#include<stdio.h>


int binarySearch(int*arr , int n , int target){
    int start =0 ,end = n-1;
    while (start <= end)
    {
        int mid = start+(end-start)/2;
        if(arr[mid] == target){
      return mid;
        }
        else if (arr[mid] >= arr[start])
        {
            if(arr[start] <= target && target < arr[mid]){
            end = mid-1;
            }
            else{
                
             start = mid+1;
            }
        }
        else{
            if(arr[mid] < target && target <= arr[end]){
               start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        
    }
    
}

int main(){
int arr[] ={4,5,6,7,0,1,2};
int n = sizeof(arr)/sizeof(arr[0]);
int target =0;
int ans =binarySearch(arr,n ,target);

printf("%d" ,ans);
    return 0;
}