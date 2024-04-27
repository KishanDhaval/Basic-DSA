#include<stdio.h>






struct stack {
    int size;
    int top;
    int arr;
};


int isFull(struct stack*ptr) {
    if(ptr->top==ptr->size-1) {
        return 1;
    }
    else {
        return 0;
    }
}

int isempty(struct stack*ptr) {

    if(ptr->top==-1) {

        return 1;
    }
    else {
        return 0;
    }
}



void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

void pop(struct stack* ptr){
    if(isempty(ptr)){
        printf("Stack underflow! Cannot pop %d to the stack\n", val);
    }
    else{
        val=ptr->arr[ptr->top];
        ptr->top=top-1;
    }
}


int main()
{
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr=(int *)malloc(sp->size*sizeof(int));
    printf("%d\n",isFull(sp));
    printf("%d\n",isempty(sp));

push(sp,12);
push(sp,12);
push(sp,12);
push(sp,12);
push(sp,12);
push(sp,12);
push(sp,12);
push(sp,12);
push(sp,12);
push(sp,12);
    printf("%d\n",isFull(sp));
    printf("%d\n",isempty(sp));



    return 0;
}