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
    scanf("%d"  , &n);
}
