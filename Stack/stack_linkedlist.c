#include<stdio.h>
#include<stdlib.h>

struct stack{
    int data;
    struct stack *next;
};

// is Empty 
int isEmpty(struct stack*top){
    if(top==NULL){
        return 1;
    }
    return 0;
}

// is Full
int isFull(struct stack*top){
    struct stack *New_node=(struct stack*)malloc(sizeof(struct stack));
    if(New_node==NULL){
        return 1;
    }
    return 0;
}

// creat New node
struct stack*create_node(int data){
    struct stack *New_node=(struct stack*)malloc(sizeof(struct stack));
    New_node->data=data;
    New_node->next=NULL;
    return New_node;
}

// Display Function
void Display(struct stack* top){
    if(isEmpty(top)){
        printf("stack is Emplty\n");
    }
    else{
        while(top!=NULL){
            printf("%d ",top->data);
            top=top->next;
        }
    }
}


// Push oparation
struct stack* Push(struct stack* top,int data){
   
   
    if(isFull(top)){
        printf("Push not posible stack is full");
    }
    else{
          struct stack *New_node=(struct stack*)malloc(sizeof(struct stack));
     New_node->data=data;
        New_node->next=top;
        top=New_node;
    }
    return top;
}

// // Pop oparation
// void Pop(struct stack** top){
   
//     if(isEmpty(*top)){
//         printf("Stack Underflow\n");
//     }
//     else{
//          struct stack* temp=*top;
//         *top=(*top)->next;
//         free(temp);
        
//     }
// }

// Pop oparation
struct stack* Pop(struct stack* top){
   
    if(isEmpty(top)){
        printf("Stack Underflow\n");
    }
    else{
         struct stack* temp=top;
        top=(top)->next;
        free(temp);
        
    }
    return top;
}


// Peak oparation
int Peak(struct stack* top){
    if(top==NULL){
        printf("stack Empty");
    }
    else{
        int x=top->data;
        return x;
    }
}


int main()
{
    int option,data;
    struct stack* top;
    top=NULL;

    //    top=  Push(top,33);
    //    top=  Push(top,58);
    //    top=  Push(top,39);
    //    top= Push(top,28);
    while(1){

    printf("\n+-+-+-+-+-+-+-+\n");
    printf("1 for Push\n");
    printf("2 for Pop\n");
    printf("3 for Peak\n"); 
    printf("4 for Display");
    printf("+-+-+-+-+-+-+-+\n");
    scanf("%d",&option);

    switch(option){
        case 1:
            printf("which Element you want to Add : \n");
            scanf("%d",&data);
          top=Push(top,data);
            break;

        case 2:
            // Pop(&top);
           top= Pop(top);
            break;

        case 3:
            printf("Top most Element is : %d ",Peak(top));
            break;

        case 4:
            Display(top);
            break;

        case 0:
            exit(0);    
            break;
            
        default:
            printf("Invalid option\n");
            break;

        }
    }
   // Display(top);
    return 0;
}