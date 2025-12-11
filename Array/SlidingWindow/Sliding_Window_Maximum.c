#include <stdio.h>
#include <limits.h>

#define MAX 1000000

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int val)
{
    if (rear == MAX - 1)
    {
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    queue[++rear] = val;
}

int dequeue()
{
    if (front == -1)
    {
        return -1;
    }
    int val = queue[front++];
    if (front > rear)
    {
        front = rear = -1;
    }
    return val;
}

void display()
{
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
}
int main()
{
int arr[] = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    int size = sizeof(arr) / sizeof(arr[0]);
    int start = 0, end = 0;
    int max = INT_MIN;

    while (end < size)
    {
        int window_size = end - start + 1;
        if (window_size < k)
        {
            end++;
        }
        else if (window_size == k)
        {
            for (int i = start; i <= end; i++)
            {
                if (arr[i] > max)
                {
                    max = arr[i];
                }
            }
         enqueue(max);
            start++, end++;
        }
    }

    display();

    return 0;
}