#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#define max 100

int stack[max];
int top = -1;


struct node
{
   int data;
   struct node*next;
};


void push(int val){
    if (top == max-1)
    {
       return ;
    }
    stack[++top] = val;
    
}

int pop(){
    if (top == -1)
    {
        return -1;
    }
    return stack[top--];
}


void display(){
    for (int i = top; i >= 0; i--)
    {
        printf("%d "  ,stack[i]);
    }
    
}

void displayList(struct node*head){
    struct node*temp = head;
    while (temp != NULL)
    {
        printf("%d " , temp->data);
        temp = temp->next;
    }
    
}

struct node*createList(){
    struct node*head = NULL , *newNode = NULL , *temp;
    int n;
    printf("Enter n : ");
    scanf("%d" , &n);
    printf("Insert %d values : \n" , n);
    for (int i = 0; i < n; i++)
    {
        newNode = (struct node*) malloc(sizeof(struct node));
        scanf("%d" , &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else{
            temp->next = newNode;
            temp = newNode;
        }
        
    }

    return head;
    
}


bool palindromeStack(struct node*head){
    struct node*temp = head;

while (temp != NULL)
{
    push(temp->data);
    temp = temp->next;
}
temp = head;
while (temp != NULL)
{
  int currElement = pop();
if (currElement != temp->data) {
            return false;  
        }
         temp = temp->next;
}


return true;
}

int main(){
struct node*head =createList();
printf("\nStack elements are :\n");
if (palindromeStack(head))
{
  printf("Palindrome.");
}
else{
    printf("No plaindrome.");
}
    return  0;

}