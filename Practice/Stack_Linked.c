#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

// create newnode
struct node*create_node(int data){
    struct node*New_node=(struct node*)malloc(sizeof(struct node));
    New_node->data=data;
    New_node->next=NULL;
    return New_node;
}

// isEmpty
int isEmpty(struct node*top){
    if(top==NULL){
        return 1;
    }
    return 0;
}

// Display
void Display(struct node*top){
    if(isEmpty(top)){
        printf("Stack Empty");
    }
    else{
        while(top!=NULL){
            printf("%d  ",top->data);
            top=top->next;
        }
    }
}

// Pop
struct node* Push(struct node*top , int data){
    struct node*New_node=create_node(data);
    if(isEmpty(top)){
        top=New_node;
    }
    else{
        New_node->next=top;
        top=New_node;
    }
    return top;
}

// Pop
struct node*Pop(struct node*top){
    if(isEmpty(top)){
        printf("Stack Underflow");
    }
    else{
        struct node*temp=top;
        top=top->next;
        free(temp);
    }
    return top;
}

void Peep(struct node*top){
    if(isEmpty(top)){
        printf("Stack Underflow");
    }
    else{
        printf("%d",top->data);
    }
}

// Stack top
void StackTop(struct node*top){
    if(isEmpty(top)){
        printf("Stack Underflow");
    }
    else{
        printf("stack top is:%d",top->data);
    }
}

// Stack Bottom
void StackBottom(struct node*top){
    if(isEmpty(top)){
        printf("Stack Underflow");
    }
    else{
        struct node*temp=top;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        printf("Stack Bottom is:%d",temp->data);
    }
}

int main()
{
    struct node*top=(struct node*)malloc(sizeof(struct node));
    top=NULL;


int option,data;

while(1){
    printf("\n+===========+\n");
    printf("1. push \n");
    printf("2. pop \n");
    printf("3. peep\n");
    printf("4. Display\n");
    printf("5. stack Top\n");
    printf("6. Stack Bottom\n");
    printf("0. Exit\n");
    printf("+===========+\n");
    scanf("%d",&option);

    switch(option){
        case 1:
            printf("which Element you want to push into stack\n");
            scanf("%d",&data);
            top=Push(top,data);           
            break;

        case 2:
            top=Pop(top);
            break;

        case 3:
            Peep(top);
            break;

        case 4 :
             Display(top);
             break;

        case 5:
            StackTop(top);
            break;

        case 6 :
            StackBottom(top);
             break;

        case 0:
            exit(0);
            break;  

            default:
                printf("Invalid option\n");
                break;       
    }
}



    return 0;
}