#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node*prev , *next;
};


struct node*createList(){
    struct node*head = NULL , *temp  , *newNode = NULL;
    int n;
    printf("Enter length of list :");
    scanf("%d" , &n);
    printf("Enter %d values in list :\n" , n);
    for (int i = 0; i < n; i++)
    {
       newNode = (struct node*) malloc(sizeof(struct node));
       scanf("%d" , &newNode->data);
       newNode->prev = NULL , newNode->next = NULL;
       if (head == NULL)
       {
        head = newNode;
        temp = newNode;
       }
       else{
        newNode->prev = temp;
        temp->next = newNode;
        temp = newNode;
       }
    }
    return head;
}


void displayList(struct node*head){
    struct node*temp = head;
    printf("Doubly link list created successfully.\n");
    while (temp != NULL)
    {
        printf("%d" , temp->data);
        if (temp->next != NULL)
        {
            printf("<->");
        }
        temp = temp->next;
    }
    
}


struct node*insertAtEnd(struct node*head){
    struct node*newNode = (struct node*) malloc(sizeof(struct node));
    printf("Enter the value to insert at last :");
    scanf("%d" , &newNode->data);
    newNode->prev = newNode->next =  NULL ;

    struct node*slow = head;
    struct node*fast = head;
    while (fast != NULL && fast->next != NULL)
    {
       slow = slow->next;
       fast = fast->next->next;
    }
slow->prev->next = newNode;
newNode->next = slow;
    return head;
}


int main(){
    struct node*head = createList();
    head = insertAtEnd(head);
    displayList(head);

    return 0;
}