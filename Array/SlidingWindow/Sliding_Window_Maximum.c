#include<stdio.h>
#include<limits.h>


int main(){
    int arr[] = {1};
    int k = 1;
    int size =  sizeof(arr)/sizeof(arr[0]);
    int start = 0, end = 0;
    int max = INT_MIN;

    while (end < size)
    {
        int window_size = end-start+1;
        if (window_size < k)
        {
            end++;
        }
        else if (window_size == k)
        {
           for(int i = start ; i <= end ; i++){
            if(arr[i] > max){
                max = arr[i];
            }
           }
           printf("%d ", max);
           start++,end++;
        }
        
        
    }
    
    return 0;
}