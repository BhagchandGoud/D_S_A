#include<stdio.h>
#include<stdlib.h>




/*-------      Method 1       -------*/

// void moveT0end(int arr[], int n) {
//     int start = 0;
//     int end = n - 1;

//     while (start < end) {
//         if (arr[end] == 0) {
//             end--;
//         } 
//         else if (arr[start] == 0) {
//             int temp = arr[start];
//             arr[start] = arr[end];
//             arr[end] = temp;
//             start++, end--;
//         } 
//         else {
//             start++;
//         }
//     }
// }


/*-------      Method 2       -------*/
void moveT0end(int arr[], int n) {
    int start = 0;
    int end = n - 1;
int j =0;
for (int i = start; i < n; i++)
{
  if (arr[i] != 0)
  {
    arr[j++] = arr[i];
  }
}
while (j < n)
{
     arr[j++] = 0;
}

}

int main() {
    int n = 8;
    int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};

    moveT0end(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
