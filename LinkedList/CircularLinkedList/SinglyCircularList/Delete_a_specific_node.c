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



struct node*insertAtPosition(struct node*head){
 int pos;
 printf("Ener postion to delete value :");
 scanf("%d" , &pos);

        struct node*temp = head;
        if (head->next == head)
        {
            free(head);
            return NULL;
        }
        if (pos == 1)
        {
           while (temp->next != head)
           {
             temp = temp->next;
           }
           temp->next = head->next;
           free(head);
        }
        else{
            struct node*prev = NULL;
            for (int i = 1; i < pos && temp->next != head; i++)
            {
                prev= temp;
                temp = temp->next;
            }
            prev->next = temp->next;
             free(temp);
        }

        return head;
}



int main(){
    struct node*head = createList();
    head = insertAtPosition(head);
    displayList(head);
}
