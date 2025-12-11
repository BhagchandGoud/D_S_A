#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*prev , *next;
};


struct node*createList(){
    struct node*head = NULL , *newNode = NULL , *temp;
    int n;
    printf("Enter length of list :");
    scanf("%d" , &n);
    printf("Enter %d values in list :\n" , n);
    for (int i = 0; i < n; i++)
    {
        newNode = (struct node*)malloc(sizeof(struct node));
        scanf("%d" ,&newNode->data);
        newNode->prev = newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            newNode->prev = temp;
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
        if (temp->next != NULL){
            printf("<->");
        }
        temp = temp->next;
    }
}

int main(){
    struct node*head = createList();
    displayList(head);
}