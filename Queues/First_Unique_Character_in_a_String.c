#include<stdio.h>
#include<string.h>
#define max 200

int queue[max];
int front  = -1 ,rear = -1;

void enqueue(int ch){
    if (rear == max-1)
    {
        return;
    }
    if (front == -1)
    {
       front = 0;
    }
    queue[++rear] = ch;
    
}


int dequeue(){
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


void display(){
    for (int i = front; i <= rear; i++)
    {
       printf("%d " , queue[i]);
    }
    
}
int uniqueCharacter(char*s , int n){
int freq[256] = {0};

    for (int i = 0; i < n; i++)
    {
    char ch = s[i];
    freq[ch-'a']++;
    }
    for (int i = 0; i < n; i++)
    {
    char ch = s[i];
    if (freq[ch-'a'] == 1){
        enqueue(i);
    }
    }
    return  queue[front];
}


int main(){
 char s[] = "loveleetcode";
 int n = strlen(s);
int ans =uniqueCharacter(s ,  n);
// display();
printf("%d" ,ans);
    return 0;
}