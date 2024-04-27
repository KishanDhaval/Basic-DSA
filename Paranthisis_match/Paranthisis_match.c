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
int Push(struct stack *s,char data){
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

// paranthisish match
int ParanthisisMatch(char exp[]){

    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->top=-1;
    s->size=10;
    s->arr=(int*)malloc(sizeof(int));

    for(int i=0;exp[i]!='\0';i++){

        if(exp[i]=='('){
            Push(s,exp[i]);
        }
        else if(exp[i]==')'){
            if(isEmpty(s)){
                return 0;
            }
            else{
                Pop(s);
            }
        }
    }
    int result=isEmpty(s);
    return result;
}



int main()
{
    int option;
    char data;
   char exp[100] ;
   
    printf("Enter the expression: ");
    fgets(exp, sizeof(exp), stdin);
    
     if(ParanthisisMatch(exp)){
        printf("Paranthisis is Match");
     }
     else{
        printf("Paranthisis is Not Match");
     }

    return 0;
}