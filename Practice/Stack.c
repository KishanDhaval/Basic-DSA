#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    int size;
    int *arr;
};

// is Empty
int isEmpty(struct stack*s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}

// isFull
int isFull(struct stack*s){
    if(s->top==s->size-1){
        return 1;
    }
    return 0;
}

//Display
void Display(struct stack*s){
    if(isEmpty(s)){
        printf("stack is Empty");
    }
    else{
        for(int i=0;i<=s->top;i++){
            printf("%d ",s->arr[i]);
        }
    }
}

// Push
void Push(struct stack*s , int data){
    if(isFull(s)){
        printf(" stack Ovrflow");
    }
    else if(isEmpty(s)){
        s->top=0;
        s->arr[s->top]=data;
    }
    else{
        s->top++;
        s->arr[s->top]=data;
    }
}

// Pop
void Pop(struct stack*s){
    if(isEmpty(s)){
        printf("Stack Underflow");
    }
    else{
        printf("%d Element is Poped",s->arr[s->top]);
        s->top--;
    }
}

// Peep
int Peep(struct stack*s){
    if(isEmpty(s)){
        printf("stack Underflow");
    }
    else{
        return s->arr[s->top];
    }
}

// stack Top
void StackTop(struct stack *s){
    if(isEmpty(s)){
        printf("stack Underflow");
    }
    else{
        printf("stack top is:%d",s->arr[s->top]) ;
    }
}

// stack Bottom
void StackBottom(struct stack *s){
    if(isEmpty(s)){
        printf("stack Underflow");
    }
    else{
        printf("stack Bottom is:%d",s->arr[s->top==0]) ;
    }
}

int main()
{
    struct stack*s;
    s->top=-1;
    s->size=100;
    s->arr=(int*)malloc(s->size*sizeof(int));

int option,data;

while(1){
    printf("\n+==========================+\n");
    printf("1 For push Element in  stack\n");
    printf("2 For pop Element from stack\n");
    printf("3 For peep Element from stack\n");
    printf("5 for stack Top\n");
    printf("6 for Stack Bottom\n");
    printf("4 for Display\n");
    printf("0 for Exit\n");
    printf("+==========================+\n");
    scanf("%d",&option);

    switch(option){
        case 1:
            printf("which Element you want to push into stack\n");
            scanf("%d",&data);
            Push(s,data);           
            break;

        case 2:
            Pop(s);
            break;

        case 3:
            printf("%d",Peep(s));
            break;

        case 4 :
             Display(s);
             break;

        case 5:
           StackTop(s);
            break;

        case 6 :
            StackBottom(s);
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