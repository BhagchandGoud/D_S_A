#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node*next;
};

struct node*createList(){
    struct node*head = NULL , *newNode = NULL , *temp;
    int n;
    printf("Enter length of list :");
    scanf("%d" , &n);
    printf("Enter %d values in list :" , n);
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
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}


struct node* insertAtMiddle(struct node*head){
    struct node*slow = head;
    struct node*fast = head;
    struct node*newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter value of newNode to insert at middle of list :\n");
    scanf("%d" , &newNode->data);
    newNode->next = NULL;
    while (fast != NULL && fast->next != NULL)
    {
       slow = slow->next;
       fast = fast->next->next;
    }
    newNode->next = slow->next;
    slow->next = newNode;
    return head;
}


void displayList(struct node*head){
    struct node*temp = head;
    printf("New list after includes value :\n");
    while (temp != NULL)
    {
        printf("%d " , temp->data);
        temp = temp->next;
    }
    
}

int main(){
struct node*head = createList();
head = insertAtMiddle(head);
displayList(head);
}