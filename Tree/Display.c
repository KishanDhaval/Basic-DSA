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

//HighEst Element
struct node* High(struct node* root ){
   
        if(root->right==NULL || root==NULL){
            return root;
        }
        else{
            return High(root);
        }
} 



int main()
{


struct node*r=create_node(5);
struct node*r1=create_node(2);
struct node*r2=create_node(3);
struct node*r3=create_node(8);
struct node*r4=create_node(2);

r->left=r1;
r->right=r2;
r1->left=r3;
r2->right=r4;

int option;
printf("1.pre-order \n 2. post-order \n 3. in-order\n");
scanf("%d",&option);

switch(option){
    case 1:
        Pre_Order_Traversal(r);
        break;
    case 2:
        Post_Order_Traversal(r);
        break;

    case 3:
         In_Order_Traversal(r);
         break;    

    default:
        printf("NNot valide input");
        break;     
}

    return 0;
}