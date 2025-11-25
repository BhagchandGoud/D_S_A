#include<stdio.h>


int binarySearch(int*arr ,int n ,int target){
int start = 0 ,end = n-1 ;
int index = n;

while (start < end)
{
    int mid = start+(end-start)/2;
    if (arr[mid] == target)
    {
               printf("mid is  : %d\n" , mid);
       return mid;
    }
    else if (arr[mid] < target)
    {
        start = mid+1;
        printf("start is  : %d\n" , start);
    }
    else{
         index = mid;
        end = mid-1;
               printf("end is  : %d\n" , end);
    }
    printf("index is  :%d" , index);
}
 return index;
}



int main(){
int arr[] = {1,3,5,6};
int n= sizeof(arr)/sizeof(arr[0]);
int target =  7;
int ans = binarySearch(arr, n ,target);
// printf("%d" ,ans);
}