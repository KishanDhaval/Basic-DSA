#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};

// Is Empty condition
int isEmpty(struct stack *ptr) {
    if (ptr->top == -1) {
        return 1;

    } else {
        return 0;

    }
}
//Is Full condition
int isFull(struct stack *ptr) {
    if (ptr->top == ptr->size - 1) {
        return 1;

    } else {
        return 0;
    }
}


//push
void push(struct stack *ptr,int data) {
    if(isFull(ptr)) {
        printf("stack overflow");
    }
    else {
        ptr->top++;
        ptr->arr[ptr->top]=data;
    }

}


//pop
int pop(struct stack *ptr) {
    if(isEmpty (ptr)) {
        printf("stack under flow\n");
    }
    else {
        int val=ptr->arr[ptr->top];
        ptr->top=ptr->top-1;
        return val;
    }
}


//peek
int peek(struct stack*ptr,int i){
    if(ptr->top-i+1<0)
        printf("invalid input");
    else
        return ptr->arr[ptr->top-i+1];    
    
}
int main() {
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 3;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    s->arr[0] = 11;
    s->top++;


    //push function
    push(s,34);
    
    //pop function 
  printf("poping element is:%d\n",pop(s));  
  
  //peek function
  printf("Element at position 1 is: %d\n",peek(s,1) );
  /*
        //isEmpty function
        if (isEmpty(s)) {
            printf("Stack is empty\n");
        }
        else {
            printf("Stack is not empty\n");
        }
        //isFull function
        if(isFull(s)) {
            printf("stack is full");
        }
        else {
            printf("stack is not full");
        }
    */

    return 0;
}