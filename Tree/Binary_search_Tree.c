#include<stdio.h>
#include<malloc.h>
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


// // Binary search type1
// struct node* Search(struct node* root , int key){
//     if(root==NULL){
//         return NULL;
//     }
//     if(root->data==key){
//         return root;
//     }
//     else if(key<root->data){
//         return Search(root->left , key);
//     }
//     else{
//         return Search(root->right , key);
//     }
// }

// Binary search type2
struct node* Search(struct node* root , int key){
    while(root!=NULL){
        if(root->data==key){
            return root;
        }
        else if(key<root->data){
            return Search(root->left , key);
        }
        else{
            return Search(root->right , key);
        }
    }
    return NULL;
}

//HighEst Element
struct node* High(struct node* root ){
        if(root->right==NULL || root==NULL){
            return root;
        }
        else{
            return High(root->right);
        }
} 

// ?Lowest Element
struct node* Low(struct node* root){
    if(root==NULL || root->left==NULL){
        return root;
    }
    else{
        return Low(root->left);
    }
}


int main()
{

    struct node*r=create_node(5);
    struct node*r1=create_node(3);
    struct node*r2=create_node(6);
    struct node*r3=create_node(2);
    struct node*r4=create_node(4);

    r->left=r1;
    r->right=r2;
    r1->left=r3;
    r1->right=r4;

    
    // Example of bynary tree
    //     5
    //    / \
    //   3   6
    //  / \
    // 2   4

    int key;
    printf("which element you want to search");
    scanf("%d",&key);
    struct node *ptr=Search(r,key);

    if(ptr!=NULL){
        printf("found :%d \n",ptr->data);
    }
    else{
        printf("Value is not found\n");
    }

    In_Order_Traversal(r);
    
    printf("Highest Element in Tree is : %d \n",High(r)->data);
    printf("Lowest Element in Tree is : %d \n",Low(r)->data);

    return 0;
}