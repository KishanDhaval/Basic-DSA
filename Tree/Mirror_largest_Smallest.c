#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create New_node
struct node* create_node(int data){
    struct node *New_node=(struct node*)malloc(sizeof(struct node));
    New_node->data=data;
    New_node->left=NULL;
    New_node->right=NULL;
    return New_node;
}

// In-Order Traversal
void In_Order_Traversal(struct node * root){
    if(root!=NULL){
        In_Order_Traversal(root->left);
        printf("%d ",root->data);
        In_Order_Traversal(root->right);
    }
   
}

// mirrir Image
struct node*MirrorImage(struct node*root){
    if(root!=NULL){
    MirrorImage(root->left);
    MirrorImage(root->right);
    struct node *temp;
     temp=root->left;
    root->left=root->right;
    root->right=temp;
    }
return root;
}

// Largest element in tree
struct node* Largest(struct node* root){
    if(root == NULL || root->right == NULL){
        return root;
    }
    else{
        return Largest(root->right);
    }
}


// Smalest element in tree
struct node* Smallest(struct node*root){
    if(root==NULL || root->left==NULL){
        return root;
    }
    else{
        return Smallest(root->left);
    }
}

// Delete trree
struct node* DeleteTree(struct node*root){
    if(root!=NULL){
    DeleteTree(root->left);
    DeleteTree(root->right);
    free(root);
    }
}

int main()
{
    
    struct node*r=create_node(20);
    struct node*r1=create_node(15);
    struct node*r2=create_node(25);
    struct node*r3=create_node(10);
    struct node*r4=create_node(17);

    r->left=r1;
    r->right=r2;
    r1->left=r3;
    r1->right=r4;

    
    // Example of bynary tree
    //     20
    //    / \
    //   15   25
    //  / \
    // 10   17
    printf("before Mirror\n");
    In_Order_Traversal(r);
    printf("\n");
    r=MirrorImage(r);
    printf("after Mirror\n");
    In_Order_Traversal(r);
     printf("\n");
      printf("\n");
       printf("\n");


//  r= DeleteTree(r);
   
    // Find the largest element
    struct node *largestNode = Largest(r);
    if (largestNode != NULL) {
        printf("Largest element in the tree: %d\n", largestNode->data);
    } else {
        printf("The tree is empty.\n");
    }

    // Find the Smallest element
    struct node *smallestNode = Smallest(r);
    if (smallestNode != NULL) {
        printf("Smallest element in the tree: %d\n", smallestNode->data);
    } else {
        printf("The tree is empty.\n");
    }


   
    return 0;
}