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
           newNode->next = head;
           temp = newNode;
        }
        else
        {
            newNode->next = head;
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}


void diplayList(struct node*head){
    if(head == NULL) 
    {             
        printf("List is empty\n");
        return;
    }
    struct node*temp = head;
    do
    {
       printf("%d " , temp->data);
       temp = temp->next;
    } while (temp != head);
    
}

int main(){
struct node*head = createList();
diplayList(head);
}

