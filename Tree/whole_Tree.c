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

// Insertion in binary search tree
struct node* Insertion(struct node* root, int key) {
    struct node* ptr = NULL;
    struct node* current = root;

    while (current != NULL) {
        ptr = current;
        if (key == current->data) {
        printf("Insertion Not possible\n");
        return NULL;
        }
        else if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    struct node* New = create_node(key);
    if (key < ptr->data) {
        ptr->left = New;
    } else {
        ptr->right = New;
    }
    return root; 
}

// pre-order Treversal
void Pre_Order_Traversal(struct node * root){
    if(root!=NULL){
        printf("%d ",root->data);
        Pre_Order_Traversal(root->left);
        Pre_Order_Traversal(root->right);
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

// Post-Order Traversal
void Post_Order_Traversal(struct node * root){
    if(root!=NULL){
        Post_Order_Traversal(root->left);
        Post_Order_Traversal(root->right);
        printf("%d ",root->data);
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

// Largest element in tree
struct node* Largest(struct node* root){
    if(root == NULL || root->right == NULL){
        return root;
    }
    else{
        return Largest(root->right);
    }
}

// Placeholder for deleteElement function
struct node *DeleteElement(struct node *root, int key) {
    
    return root;
}

// Total node in tree
int CountTotalNode(struct node* root){
   
    if(root==NULL){
        return 0;
    }
       return 1 + CountTotalNode(root->left) + CountTotalNode(root->right);
}

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

// Placeholder for Height function
int Height(struct node *root) {

    return 0;
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

// Placeholder for DeleteTree function
struct node *DeleteTree(struct node *root) {
    if (root != NULL) {
        DeleteTree(root->left);
        DeleteTree(root->right);
        free(root);
    }
    return NULL;
}

// Binary search type
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

    int option, val;
    struct node *ptr;
    


    do{

    printf("\n ******MAIN MENU******* \n");
    printf("\n 1. Insert Element");
    printf("\n 2. Preorder Traversal");
    printf("\n 3. Inorder Traversal");
    printf("\n 4. Postorder Traversal");
    printf("\n 5. Find the smallest element");
    printf("\n 6. Find the largest element");
    printf("\n 7. Delete an element");
    printf("\n 8. Count the total number of nodes");
    printf("\n 9. Count the total number of external nodes");
    printf("\n 10. Count the total number of internal nodes");
    printf("\n 11. Determine the height of the tree");
    printf("\n 12. Find the mirror image of the tree");
    printf("\n 13. Delete the tree");
    printf("\n 14. Search Element");
    printf("\n 15. Exit");
    printf("\n\n Enter your option : ");
    scanf("%d", &option);

    switch(option){

    case 1:
    printf("\n Enter the value of the new node : ");
    scanf("%d", &val);
    r = Insertion(r, val);
    break;

    case 2:
    printf("\n The elements of the tree are : \n");
    Pre_Order_Traversal(r);
    break;

    case 3:
    printf("\n The elements of the tree are : \n");
    In_Order_Traversal(r);
    break;

    case 4:
    printf("\n The elements of the tree are : \n");
    Post_Order_Traversal(r);
    break;

    case 5:
    ptr = Smallest(r);
    if (ptr != NULL) {
        printf("Smallest element in the tree: %d\n", ptr->data);
    }
    else {
        printf("The tree is empty.\n");
    }
    break;

    case 6:
    ptr = Largest(r);
    if (ptr != NULL) {
        printf("Largest element in the tree: %d\n",ptr->data);
    } else {
        printf("The tree is empty.\n");
    }
    break;

    case 7:
    printf("\n Enter the element to be deleted : ");
    scanf("%d", &val);
    r = DeleteElement(r, val);
    break;

    case 8:
    printf("Total Node in tree is : %d\n",CountTotalNode(r));
    break;

    case 9:
  
    printf("External Node in tree is : %d\n",CountExternalNode(r));
    break;

    case 10:
     printf("Internal Node in tree is : %d\n",CountInternalNode(r));
    break;

    case 11:
    printf("\n The height of the tree = %d", Height(r));
     break;

    case 12:
     r=MirrorImage(r);
    break;

    case 13:
     r = DeleteTree(r);
     break;

    case 14:
    printf("which element you want to search");
    scanf("%d",&val);
    ptr=Search(r,val);
    if(ptr!=NULL){
        printf("found :%d \n",ptr->data);
    }
    else{
        printf("Value is not found\n");
    }
    break;

    }
    }while(option!=15);
    return 0;
}