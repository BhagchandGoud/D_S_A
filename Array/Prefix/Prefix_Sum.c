#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
bool prefixSum(int *arr , int n){
    int toatalSum = 0;
    int prefix = 0;
for (int i = 0; i < n; i++)
{
    toatalSum+= arr[i];

} 
    for (int j = 0; j < n; j++)
    {
        prefix+=arr[j];
        if (toatalSum-prefix == prefix)
        {
            return true;
        }
}
return false;
}


int main(){
int arr[] = {2,4,6,2,1,5,8,2};
int n = 8;

if (prefixSum(arr ,  n))
{
    printf("true");
}
else{
    printf("false");
}

    return 0;
}