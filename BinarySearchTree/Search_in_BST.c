#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int val;
    struct node*left , *right;
};


struct node*createNode(int val){
struct node*newNode = (struct node*)malloc(sizeof(struct node));
newNode->val = val;
newNode->left = NULL ,newNode->right = NULL;
return newNode;
}



struct node*insertInBST(struct node*root , int val){
    if (root == NULL)
    {
       return createNode(val);
    }
    if (val < root->val)
    {
        root->left =  insertInBST(root->left , val);;
    }
    else  if (val > root->val)
    {
        root->right = insertInBST(root->right , val);
    }
    
    return root;
}

struct node*createBST(){
    struct node*root = NULL;
    int n ;
    printf("Enter  n:");
    scanf("%d",&n);
    int value ;
    printf("Enter values :");
    for (int i = 0; i < n; i++)
    {
        scanf("%d" , &value);
        root = insertInBST(root ,value);
    }
    
    return root;
}

void inOrderTraversal(struct node*root ){
      if (root == NULL) return;
        inOrderTraversal(root->left); 
    printf("%d ", root->val);
    inOrderTraversal(root->right);
}


struct node* searchInBST(struct node*root , int target){
    if (root == NULL)
    {
        return NULL;
    }
    
    if (target == root->val)
    {
       return root;
    }
    else if (target < root->val)
    {
        root->left = searchInBST(root->left , target);
    }
    else{
        root->right = searchInBST(root->right , target);
    }
}


int main(){
    struct node*root = createBST();
   inOrderTraversal(root);
   printf("\n");
    int target ;
    printf("Enter target value to search in BST :");
    scanf("%d" , &target);
 struct node*ans =   searchInBST(root , target) ;
if (ans)
{
    printf("value found.");
}
else{
    printf("value is not found.");
}



    return 0;
}