#include<stdio.h>
#include<stdlib.h>
int linerSearch(int *arr ,int n){
int target ;
printf("Enter searching value :");
scanf("%d" , &target);

for (int i = 0; i < n; i++)
{
    if(arr[i] == target){
        return arr[i];
    }
}
return 0;
}
int main(){
    int arrLength ;
    printf("Enter length of array to store value in array :");
    scanf("%d" ,&arrLength);
int *arr = (int*) malloc(arrLength*sizeof(int));
printf("Enter %d values in array :\n" , arrLength);
for (int i = 0; i < arrLength; i++)
{
    scanf("%d" , &arr[i]);
}

//call the function of linear search
int search = linerSearch(arr ,arrLength);
if(search){
    printf("\n Element found.");
}
else{
    printf("\n Element not found.");
}
    return 0;
}