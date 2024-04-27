#include<stdio.h>
#include<malloc.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};




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

    // struct node *r=(struct node*)malloc(sizeof(struct node));
    // r->left=NULL;
    // r->right=NULL;

    // struct node *r1=(struct node*)malloc(sizeof(struct node));
    // r1->left=NULL;
    // r1->right=NULL;

    // struct node *r2=(struct node*)malloc(sizeof(struct node));
    // r2->left=NULL;
    // r2->right=NULL;


struct node*r=create_node(5);
struct node*r1=create_node(2);
struct node*r2=create_node(3);
struct node*r3=create_node(8);
struct node*r4=create_node(2);

r->left=r1;
r->right=r2;
r1->left=r3;
r2->right=r4;

    return 0;
}