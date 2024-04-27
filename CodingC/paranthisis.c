
#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    char *arr;
};

// Is Empty condition
int isEmpty(struct stack *ptr) {
    return (ptr->top == -1);
}

// Is Full condition
int isFull(struct stack *ptr) {
    return (ptr->top == ptr->size - 1);
}

// Push
void push(struct stack *ptr, char data) {
    if (isFull(ptr)) {
        printf("Stack overflow\n");
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}

// Pop
char pop(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack underflow\n");
        return '\0'; // Return null character for an empty stack
    } else {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

// Parenthesis matching
int parenthesis(char *exp) {
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            push(sp, exp[i]);
        } else if (exp[i] == ')') {
            if (isEmpty(sp)) {
                free(sp->arr);
                free(sp);
                return 0;
            } else {
                pop(sp);
            }
        }
    }

    int result = isEmpty(sp);
    free(sp->arr);
    free(sp);
    return result;
}

int main() {
    char exp[] = "(kish)(12(1+2))";
    if (parenthesis(exp)) {
        printf("Parenthesis are balanced\n");
    } else {
        printf("Parenthesis are not balanced\n");
    }

    return 0;
}