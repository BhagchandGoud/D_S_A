#include<stdlib.h>
#include<stdio.h>


struct node
{
    int data;
    struct node*next;
};


struct node*createList(){
    struct node*head = NULL , *newNode = NULL , *temp;
    int n;
    printf("Enter length of list :\n");
   scanf("%d" , &n);
   printf("Enter %d values in list :\n" , n);
   for (int  i = 0; i < n; i++)
   {
    newNode = (struct node*)malloc(sizeof(struct node));
    scanf("%d" , &newNode->data);
    newNode->next = NULL;
    if (head ==  NULL)
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


struct node*displayList(struct node*head){
   struct node*temp = head;
   printf("list created successfully.\n");
   while (temp != NULL)
   {
    printf("%d " ,temp->data);
    temp = temp->next;
   }
}


struct node*insertAtPosition(struct node*head){
    int pos;
    printf("Enter the position to insert value :");
    scanf("%d"  , &pos);
    struct node*newNode = (struct node*) malloc(sizeof(struct node));
    printf("Enter the new node value :");
    scanf("%d" , &newNode->data);
    struct node*curr = head;
    if (pos < 1)
    {
        printf("Invalid position.");
        return head;
    }
    
    if (pos == 1)
    {
       newNode->next = head;
       head = newNode;
       return head;
    }
    else{
     for (int i = 1; i < pos-1 && curr != NULL; i++)
    {
         curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
    curr = newNode;
    }
    
   return head;
}


int main(){
    struct node*head = createList();
    head = insertAtPosition(head);
    displayList(head);
}
