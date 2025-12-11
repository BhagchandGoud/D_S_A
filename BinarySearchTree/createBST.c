#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*left , *right;
};


struct node*createNode(int val){
      struct node*  newNode = (struct node*) malloc(sizeof(struct node));
         newNode->data = val;
        newNode->left = NULL , newNode->right = NULL;
        return newNode;
}


struct node*insertInBST(struct node*root , int val){
if (root == NULL)
{
   return createNode(val);
}

if (val < root->data)
{
    root->left = insertInBST(root->left , val);
}
else if (val > root->data)
{
    root->right = insertInBST(root->right , val);
}
 return root;
}

struct node*createBST(){
struct node*root = NULL;
    int n ,val;
    printf("Enter n :");
    scanf("%d" , &n);
    printf("Enter values:");
    for (int i = 0; i < n; i++)
    {
     scanf("%d", &val);
        root = insertInBST(root , val);
    }
    return root;
}


void inOrderTraversal(struct node*root){
    if (root == NULL) return;
    inOrderTraversal(root->left);
    printf("%d " , root->data);
    inOrderTraversal(root->right);
}
void preOrderTraversal(struct node*root){
    if (root == NULL) return;
    
    printf("%d " , root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(struct node*root){
    if (root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
     printf("%d " , root->data);
}
int main(){
struct node*root = createBST();
printf("In oreder traversal : ");
inOrderTraversal(root);
printf("\n");
printf("Pre oreder traversal : ");
preOrderTraversal(root);
printf("\n");
printf("Post oreder traversal : ");
postOrderTraversal(root);
    return 0;
}