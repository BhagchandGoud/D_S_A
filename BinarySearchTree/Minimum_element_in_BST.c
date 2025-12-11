#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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



struct node*insertVal(struct node*root , int val){
    if (root == NULL)
    {
        return createNode(val);
    }
    if (val < root->data)
    {
        root->left = insertVal(root->left , val);
    }
    else if (val > root->data)
    {
       root->right = insertVal(root->right , val);
    }
    
    return root;
}

struct node*createBST(){
    int n;
    printf("Enter n :");
    scanf("%d" , &n);
    int val;
    printf("Enter values :");
    struct node*root = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d" , &val);
        root = insertVal(root , val);
    }
    
    return root;
}


int inOrdertraversal(struct node*root){
    if (root == NULL)
    {
        return -1;
    }

    int leftMin = inOrdertraversal(root->left);
   int rightMin =  inOrdertraversal(root->right);
   int currMin = root->data;
     if (leftMin != -1 && leftMin< currMin)
    {
      currMin = leftMin;
    }
    if(rightMin != -1 && rightMin < currMin) {
       currMin = rightMin;
    }
    return currMin;

}


int main(){
struct node*root = createBST();
int ans = inOrdertraversal(root);
printf("min is : %d" ,ans);

    return 0;
}
