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


void displayList(struct node*head){
    struct node*temp = head;
    printf("New list after delete last  value :\n");
    while (temp != NULL)
    {
        printf("%d " , temp->data);
        temp = temp->next;
    }
    
}

struct node* deleteAtEnd(struct node*head){
struct node*slow = head;
struct node*fast = head;
while (fast != NULL && fast->next != NULL)
{
   slow = slow->next;
   fast = fast->next->next;
}
slow->next = NULL;
free(fast);
    return head;
}

int main(){
struct node*head = createList();
head = deleteAtEnd(head);
displayList(head);
}
