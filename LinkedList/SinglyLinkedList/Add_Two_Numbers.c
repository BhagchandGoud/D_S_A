#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createList1()
{
    struct node *head1 = NULL, *newNode1 = NULL, *temp1;
    int n;
    printf("Enter list 1 length :");
    scanf("%d", &n);
    printf("Insert values :\n");
    for (int i = 0; i < n; i++)
    {
        newNode1 = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newNode1->data);
        newNode1->next = NULL;
        if (head1 == NULL)
        {
            head1 = newNode1;
            temp1 = newNode1;
        }
        else
        {
            temp1->next = newNode1;
            temp1 = newNode1;
        }
    }

    return head1;
}

struct node *createList2()
{
    struct node *head2 = NULL, *newNode2 = NULL, *temp2;
    int n;
    printf("Enter list 2 length :");
    scanf("%d", &n);
    printf("Insert values :\n");
    for (int i = 0; i < n; i++)
    {
        newNode2 = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newNode2->data);
        newNode2->next = NULL;
        if (head2 == NULL)
        {
            head2 = newNode2;
            temp2 = newNode2;
        }
        else
        {
            temp2->next = newNode2;
            temp2 = newNode2;
        }
    }
    return head2;
}

void displayList1(struct node *head1)
{
    struct node *temp = head1;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void displayList2(struct node *head2)
{
    struct node *temp = head2;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

struct node* addTwoNumbers(struct node* l1, struct node* l2) {
struct node*head = NULL , *temp = NULL;
int carry = 0;
while(l1 != NULL || l2 != NULL || carry != 0){
    int sum = 0;
    int x = l1 != NULL ? l1->data : 0;
    int y = l2 != NULL ? l2->data : 0;
    sum += x + y + carry;

        carry = sum/10;
        sum = sum%10;

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data =sum;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        temp = newNode;
    }
    else{
        temp->next = newNode;
        temp = newNode;
    }
    if(l1) l1 = l1->next;
    if(l2) l2 = l2->next;
}
return head;
}
struct node *displayNewList(struct node *newHead)
{
    struct node *temp = newHead;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct node *head1 = createList1();
    displayList1(head1);
    printf("\n");
    struct node *head2 = createList2();
    displayList1(head2);
    printf("\n");
    struct node *newHead = addTwoNumbers(head1, head2);
    displayNewList(newHead);
    return 0;
}