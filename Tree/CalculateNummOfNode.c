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

// Total node in tree
int CountTotalNode(struct node* root){
   
    if(root==NULL){
        return 0;
    }
       return 1 + CountTotalNode(root->left) + CountTotalNode(root->right);
}

 // Example of bynary tree(total node)
    //     20
    //    / \
    //   15   25
    //  / \
    // 10   17


// Total intarnal node
int CountInternalNode(struct node* root){
    if(root==NULL){
        return 0;
    }
    else if(root->left==NULL && root->right==NULL){
        return 0;
    }
    else{
       return 1+ CountInternalNode(root->left) + CountInternalNode(root->right);
    }
}

 // Example of bynary tree (internal node)
    //    .20
    //    / \
    //  .15  25
    //  / \
    // 10   17

// Total external  node
int CountExternalNode(struct node* root){
    int left;
    int right;
    if(root==NULL){
        return 0;
    }
    else if(root->left==NULL && root->right==NULL){
        return 1;
    }
    else{
       return CountExternalNode(root->left) + CountExternalNode(root->right);
    }
}

    // Example of bynary tree(external node)
    //     20
    //    / \
    //   15   .25
    //  / \
    // .10  .17


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

    printf("Total Node in tree is : %d\n",CountTotalNode(r));
    printf("Internal Node in tree is : %d\n",CountInternalNode(r));
    printf("External Node in tree is : %d\n",CountExternalNode(r));

    return 0;
}