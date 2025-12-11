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

struct node* deleteAtPosition(struct node*head){
int pos;
printf("Enter position for deleting value :");
scanf("%d" , &pos);

struct node*prev = NULL;
struct node*curr = head;
for (int i = 1; i < pos && curr != NULL; i++)
{
    prev = curr;
   curr = curr->next;
}
prev->next = curr->next;
free(curr);
return head;
}

int main(){
struct node*head = createList();
head = deleteAtPosition(head);
displayList(head);
}
