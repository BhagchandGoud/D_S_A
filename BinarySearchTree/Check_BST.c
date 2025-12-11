#include<stdio.h>
#include<stdlib.h>



struct node
{
    int data;
    struct node*left , *right;
};
 

struct node*createNode(int val){
    struct node*newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL , newNode->right = NULL;
    return newNode;
}


struct node*insertValue(struct node*root , int val){
    if (root == NULL)
    {
        return createNode(val);
    }
    
if (val < root->data)
{
   root->left = insertValue(root->left ,  val);
}
else if (val > root->data)
{
   root->right = insertValue(root->right ,  val);
}
return root;
}

struct node*createBST(){
    int n;
    printf("Enter n :");
    scanf("%d" , &n);
    int value;
    printf("Insert values :");
    struct node*root = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d" , &value);
root = insertValue(root , value);
    }
    
    return root;
}


void inOrderTraversal(struct node*root){
     if (root == NULL) return; 
    inOrderTraversal(root->left);
    printf("%d " , root->data);
      inOrderTraversal(root->right);
}





int main(){
struct node*root = createBST();
printf("In oreder traversal : ");
inOrderTraversal(root);
    return 0;
}