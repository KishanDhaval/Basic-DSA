#include <stdio.h>
#include <stdlib.h>

struct stack {
    int top;
    int size;
    char *arr;
};

// isEmpty
int isEmpty(struct stack *s) {
    return s->top == -1;
}

// isFull
int isFull(struct stack *s) {
    return s->top == s->size - 1;
}

// Display
void Display(struct stack *s) {
    if (isEmpty(s)) {
        printf("stack is Empty");
    } else {
        for (int i = 0; i <= s->top; i++) {
            printf("%c ", s->arr[i]); 
        }
    }
}

// Push
void Push(struct stack *s, char data) {
    if (isFull(s)) {
        printf(" stack Overflow");
    } else if (isEmpty(s)) {
        s->top = 0;
        s->arr[s->top] = data;
    } else {
        s->top++;
        s->arr[s->top] = data;
    }
}

// Pop
char Pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow");
        return '$';  
    } else {
        return s->arr[s->top--];
    }
}


char *reverse(char *arr) {
    struct stack input;
    input.top = -1;
    input.size = 100;
    input.arr = (char *)malloc(input.size * sizeof(char)); 

    struct stack output;
    output.top = -1;
    output.size = 100;
    output.arr = (char *)malloc(output.size * sizeof(char));  

    int i = 0;
    while (arr[i] != '\0') {
        Push(&input, arr[i]);
        i++;
    }

    char *exp = (char *)malloc((i + 1) * sizeof(char));
    int j = 0;
    while (!isEmpty(&input)) {
        exp[j] = Pop(&input);
        j++;
    }
    exp[j] = '\0'; 
    return exp;
}

int main() {
    printf("Enter Expression: ");
    char arr[20];
    scanf("%s", arr);

    printf("Your reversed expression is: %s\n", reverse(arr));

    return 0;
}
