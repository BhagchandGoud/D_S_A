#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
    int data;
    struct node*next;
};

struct node*createList(){
    struct node*head = NULL , *newNode = NULL , *temp;
    int n;
    printf("Enter n :");
    scanf("%d" , &n);
    printf("Enter values :");
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


void displayList(struct node*head){
    struct node* temp  = head;
    while (temp !=  NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
}


int  minVal(struct node*head){
int min = INT_MAX;
    struct node *temp = head;
    while (temp != NULL)
    {
       if (min > temp->data )
       {
        min = temp->data;
       }
       temp = temp->next;
    }
    
    return min;
}



struct node*reverseList(struct node*head){
    struct node*prev = NULL;
    struct node*curr = head;
    struct node*future = NULL;

    while (curr != NULL)
    {
       future  = curr->next;
       curr->next = prev;
        prev  = curr;
        curr = future ;
    }

   return prev;
}

int main(){
    struct node*head = createList();
    printf("Link list is : \n");
    displayList(head);
    printf("\n Minimum value in link list : \n");
   int min  =  minVal(head);
   printf("%d" , min);
   head = reverseList(head);
   printf("\nAfter reverse link list :");
   displayList(head);
    return 0;
}