#include<stdlib.h>
#include<stdio.h>

struct node
{
    int data;
    struct node*next;
};

struct node*createList(){
    struct node*head = NULL , *newNode = NULL , *temp;
    int n ;
     printf("Enter length of list :");
     scanf("%d" ,&n);
     printf("Enter %d values in list : \n" , n);
     for (int i = 0; i < n; i++)
     {
        newNode = (struct node* ) malloc(sizeof(struct node));
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
    struct node*temp = head;
    while (temp != NULL)
    {
        printf("%d " , temp->data);
        temp = temp->next;
    }
}

struct node*insertAtEnd(struct node*head){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    printf("Enter new node to insert at last :");
    scanf("%d" , &newNode->data);
    struct node*temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
    return head;
}
int main(){
    struct node*head = createList();
    head = insertAtEnd(head);
    displayList(head);
    return 0;
}