#include<stdio.h>
#include<malloc.h>

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

// pre-order Treversal
void Pre_Order_Traversal(struct node * root){
    if(root!=NULL){
        printf("%d ",root->data);
        Pre_Order_Traversal(root->left);
        Pre_Order_Traversal(root->right);
    }
}

// Post-Order Traversal
void Post_Order_Traversal(struct node * root){
    if(root!=NULL){
        Post_Order_Traversal(root->left);
        Post_Order_Traversal(root->right);
        printf("%d ",root->data);
    }
}

// In-Order Traversal
void In_Order_Traversal(struct node * root){
    if(root!=NULL){
        In_Order_Traversal(root->left);
        printf("%d ",root->data);
        In_Order_Traversal(root->right);
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

     int key;
    printf("which element you want to Delete");
    scanf("%d",&key);
    Deletion(r,key);
    In_Order_Traversal(r);

    return 0;
}