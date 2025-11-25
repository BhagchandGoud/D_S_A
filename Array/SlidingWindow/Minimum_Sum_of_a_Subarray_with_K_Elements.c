#include<stdio.h>
#include<limits.h>

int main(){
    int arr[] = {2, 1, 5, 1, 3, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int start = 0;
    int end =0;
    int sum = 0;
    int k =3;
    int min = INT_MAX;

    while (end < size)
    {
        sum += arr[end];
        int window_size = end-start+1;

        if(window_size < k){
            end++;
        }
        else if (window_size == k)
        {
            if (sum < min)
            {
                min = sum;
            }

            sum -= arr[start];
            start++ , end++;
            
        }
        
    }
      printf("Minimum sum of subarray of size %d = %d\n", k, min);
      return 0;

}