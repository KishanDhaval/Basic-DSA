#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* create_node(int data){
    struct node* New_node=(struct node*)malloc(sizeof(struct node));
    New_node->data=data;
    New_node->next=NULL;
    New_node->prev=NULL;
    return New_node;
}

int isEmpty(struct node* head){
    if(head==NULL){
        return 1;
    }
    return 0;
}

void Display(struct node*head){
    if(isEmpty(head)){
        printf("linnked List is Empty");
    }
    else{
        struct node*temp=head;
        while(temp->next!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

struct node* AtBegining(struct node* head, int data)
{
    struct node* New_node=create_node(data);
    if(isEmpty(head)){
        head=New_node;
    }
    else{
        New_node->next=head;
        head=New_node;
    }
    return head;
}

struct node*AtEnd(struct node* head,int data){
    strucct node* New_node=create_node(data);
    if(isEmpty(head)){
        head=New_node;
    }
    else{
        struct node*temp=head;
        while(temp!=NULL){
            temp=temp->next;
        }
        New_node->next=
        
    }
}


int main()
{
    struct node * head=(struct node*)malloc(sizeof(struct node));
    head->next=NULL;
    head->prev=NULL;

int option,data ;

while(1){

    printf("1.Innsert At Begining\n 2.\n");
    scanf("%d",&option);

switch(option){
    case 1: 
        printf(" which data at first");
        scanf("%d",&data);
        head=AtBegining(head,data);
        Display(head);
        break;

    default:
        printf("invalide");    
}
}



    return 0;
}