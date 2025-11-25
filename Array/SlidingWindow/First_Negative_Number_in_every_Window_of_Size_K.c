#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


int main(){
    int arr[] = {12,-1,3,5,-2,45,-3 ,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int start = 0;
    int end = 0;
    int k = 3;


    while (end < size)
    {
      int window_size = end-start+1;
      if(window_size < k){
        end++;
      }
      else if (window_size == k)
      {
         int   found  = 0;
for (int i = start; i <= end; i++)
{
   if (arr[i] < 0) {
                    printf("%d ", arr[i]);
                    found = 1;
                    break;
                }
}

        if (!found) {
                printf("0 ");  
            } 
        start++ ,end++;
      }
    }
    return 0;
}