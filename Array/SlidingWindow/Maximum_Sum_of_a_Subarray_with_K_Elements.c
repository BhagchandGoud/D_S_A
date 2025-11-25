#include<stdio.h>
#include<limits.h>
int main(){
int arr[] = {2, 1, 5, 1, 3, 2};
int size = sizeof(arr)/sizeof(arr[0]);
int start = 0 ,end = 0;
int sum = 0;
int k = 3;
int max = INT_MIN;
while (end < size)
{
    int window_Size = end-start+1;
 sum+=arr[end];

 if(window_Size < k){
end++;
 }
else if( window_Size == k){
    if (sum > max)
    {
        max = sum;
    }
    sum -= arr[start];
    start++,end++;
}

}

    printf("Maximum sum of subarray of size %d = %d\n", k, max);


return 0;
}