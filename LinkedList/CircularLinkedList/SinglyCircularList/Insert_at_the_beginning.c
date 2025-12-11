#include<stdlib.h>
#include<stdio.h>

struct node
{
    int data;
    struct node*next;
};


struct node*createList(){
    struct node*head = NULL , *newNode = NULL, *temp;
    int n;
    printf("Enter length of list :");
    scanf("%d" , &n);
    printf("Enter %d values in list :" , n);
    for (int i = 0; i < n; i++)
    {
        newNode = (struct node*) malloc(sizeof(struct node));
        scanf("%d" , &newNode->data);
        newNode->next = NULL;
        if(head == NULL){
             head = newNode;
             temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
          if(temp != NULL){
         temp->next = head;
        }
           
    return head;
}



void displayList(struct node*head){
    struct node*temp = head;
    printf("circular list created successfully .\n");
    do
    {
        printf("%d " , temp->data);
        temp = temp->next;
    } while (temp != head);
    
}



struct node*insertAtBegning(struct node*head){
    struct node*newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter value to insert begning :");
    scanf("%d" ,&newNode->data);
        struct node*temp = head;  
        while (temp->next != head){
       temp = temp->next;
    }
      temp->next = newNode;
      newNode->next = head;
    head = newNode;
    return head;
}



int main(){
    struct node*head = createList();
    head = insertAtBegning(head);
    displayList(head);
}
