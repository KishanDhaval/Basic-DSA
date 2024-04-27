#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

// create newnode
struct node*create_node(int data){
    struct node*New_node=(struct node*)malloc(sizeof(struct node));
    New_node->data=data;
    New_node->next=NULL;
    return New_node;
}

// isEmpty
int isEmpty(struct node*f){
    if(f==NULL){
        return 1;
    }
    return 0;
}


// Display
void Display(struct node*f){
    if(isEmpty(f)){
        printf("Linked list Empty");
    }
    else{
        while(f!=NULL){
            printf("%d  ",f->data);
            f=f->next;
        }
        printf("\n");
    }
}

// Enqueue
struct node*Enqueue(struct node*f,struct node*r,int data){
    struct node*New_node=create_node(data);
    if(isEmpty(f)){
        f=r=New_node;
    }
    else{
        r->next=New_node;
        r=r->next;
    }
    return f;
}


// Dequeue
struct node*Dequeue(struct node*f,struct node*r){
     struct node*temp=f;
    if(isEmpty(f)){
        printf("Queue Underflow");
    }
    else if(f->next==r){
        free(temp);
        f=NULL;
        r=NULL;
    }
    else{
        f=f->next;
        free(temp);
    }
    return f;
}


int main(){

    struct node*f=(struct node*)malloc(sizeof(struct node));
    struct node*r=(struct node*)malloc(sizeof(struct node));
    f=r=NULL;

    
    int option, data;

    while (1)
    {
        printf("\n+-+-+-+-+-+-+-+\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("0. Exit\n");
        printf("+-+-+-+-+-+-+-+\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("which Element you want to Enqueue\n");
            scanf("%d", &data);
            f=Enqueue(f,r, data);
            break;

        case 2:
            f=Dequeue(f,r);
            break;

        case 3:
             Display(f);
             break;

        case 0:
            exit(0);
            break;

        default :
            printf("Invalid Input");
            break;            
        }
    }

    return 0;
}