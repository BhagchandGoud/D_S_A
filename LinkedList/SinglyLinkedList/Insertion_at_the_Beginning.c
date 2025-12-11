#include<stdlib.h>
#include<stdio.h>


struct node{
    int data;
    struct node*next;
};

struct node*createList(){
    struct node*head = NULL , *newNode = NULL , *temp;
    int n;
    printf("Enter length of  list :");
    scanf("%d" , &n);
    printf("Enter %d  elements in list : \n" , n);
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

void displayList(struct node*head)
{
    struct node*temp = head;
    printf("List created successfully .\n");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
}



struct node*insertAtBegning(struct node*head){
    struct node *newNode;
    printf("Enter element to add begning :\n");
    newNode = (struct node*) malloc(sizeof(struct node));
    scanf("%d" , &newNode->data);
    newNode->next = head;
     head = newNode ;

    return head;
}
int main(){
struct node*head = createList();
head = insertAtBegning(head);
displayList(head);
    return 0;
}