#include<stdio.h>
#include<stdlib.h>
struct stack{
    int top;
    int size;
    char *arr;
};


int isOperand(char a){
    if(a>='a'&& a<='z'&& a>='A' && a<='Z' ){
        return 1;
    }
    return 0;
}

int isOperator(char b){
    if(b=='+'  || b=='-' || b=='*' || b=='/' || b=='^' ){
        return 1;
    }
    return 0;
}

int isEmpty(struct stack *s){
    int i=0;
    if(s->top==-1){
        return 1;
    }
    return 0;
}

// Push
void Push(struct stack*s , char data){
    
    if(isEmpty(s)){
        s->top=0;
        s->arr[s->top]=data;
    }
    else{
        s->top++;
        s->arr[s->top]=data;
    }
}


char pop(struct stack *s) {
    if (!isEmpty(s))
        return s->arr[s->top--];
    return '$'; // Return a special character to indicate an empty stack
}

char peek(struct stack *s) {
    return s->arr[s->top];
}

int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;    
    }
    return -1;
}

void Display(struct stack * s){
    if(isEmpty(s)){
        printf("empty");
    }
    else{
        for(int i=0;i<=s->top;i++){
            printf("%c ",s->arr[i]);
        }
    }
}

struct stack* reverse(struct stack *s) {
    struct stack input;
    input.top = -1;
    input.size = 100;
    input.arr = (char *)malloc(input.size * sizeof(char)); 

    struct stack output;
    output.top = -1;
    output.size = 100;
    output.arr = (char *)malloc(output.size * sizeof(char));  

    int i = 0;
    while (s->arr[i] != '\0') {
        Push(&input, s->arr[i]);
        i++;
    }

    // char *exp = (char *)malloc((i + 1) * sizeof(char));
    int j = 0;
    while (!isEmpty(&input)) {
        output.arr[j] = pop(&input);
        j++;
    }
    output.arr[j] = '\0'; 
    return &output;
}


void in_postfix(char arr[]) {
    struct stack op, exp;
    op.top = exp.top = -1;
    op.size = exp.size = 100;
    op.arr = (char *)malloc(op.size * sizeof(char));
    exp.arr = (char *)malloc(exp.size * sizeof(char));

    int i = 0;
    while (arr[i] != '\0') {
        if (isOperand(arr[i])) {
            Push(&exp, arr[i]);
        } else if (isOperator(arr[i])) {
            int now = getPrecedence(arr[i]);
            int prev = getPrecedence(peek(&op));

            if (now >= prev) {
                Push(&op, arr[i]);
            } else {
                while (!isEmpty(&op) && now < prev) {
                    Push(&exp, pop(&op));
                    prev = getPrecedence(peek(&op));
                }
                Push(&op, arr[i]);
            }
        }
        i++;
    }

    while (!isEmpty(&op)) {
        Push(&exp, pop(&op));
    }
  
    struct stack* result= reverse(&exp);
    Display(result);
}

int main()
{
//  char arr[10]={'a','+','b','/','c','-','d','b','/','+','d'};
char arr[100];

printf("Enter Infix expresion you want to convert :\n");
int i=0;
while(i!='\n'){
    scanf("%c",&arr[i]);
    i++;
}

 in_postfix(arr);
    return 0;
}