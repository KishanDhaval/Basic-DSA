#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

// isEmplty function
int isEmpty(struct stack *s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}

// isFull Function
int isFull(struct stack *s){
    if(s->top==s->size-1){
        return 1;
    }
    return 0;
}

// Display Stack element
void Display(struct stack *s){
    if(isEmpty(s)){
        printf("stack is Empty");
    }
    else{
    printf("\nNow stack Element are: ");
    for(int i=0;i<=s->top;i++){
        printf("%d  ",s->arr[i]);
        }
    }
}

// Push Oparation in stack
int Push(struct stack *s,int data){
    if(isFull(s)){
        printf("Push not posible stack full\n");
    }
    else{ 
            s->top++;
            s->arr[s->top]=data;
        }    
}

// Pop Oparation in Stack
void Pop(struct stack *s){
    if(isEmpty(s)){
        printf("Pop not posible stack Empty\n");
    }
    else{
        s->top--;
    }
}

// Peep Oparation in stack
int Peep(struct stack *s){
    if(isEmpty(s)){
        printf("stack Empty so peep not posible\n");
    }
    else{
        return s->arr[s->top];
    }
}


int main()
{
    int option,data;
    // struct stack s;
    // s.data=112;
    // s.top=-1;
    // s.arr=

    struct stack *s;
    s->top=-1;
    s->size=10;
    s->arr=(int*)malloc(sizeof(int));


while(1){
    printf("\n+==========================+\n");
    printf("1 For push Element in  stack\n");
    printf("2 For pop Element from stack\n");
    printf("3 For peep Element from stack\n");
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