# include<stdio.h>
# define max 5
int top=-1,stack[max];
void push(int value,int stack[]);
void pop(int stack[]);
int peek(int stack[]);
void display(int stack[]);
void peep(int valuefind,int stack[]);
void change(int valuechange,int stack[]);
int count(int stack[]);

int main()
{
    int option,val,peekval,valfind,main_valchange,mainsum;

    printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Peep\n6.Change\n7.Count\n");
    
    do {
    printf("._______________________.\n");
    printf("Enter your option : ");
    scanf("%d",&option);
    switch(option) {
        case 1:
        if(top==max-1) {
            printf("..>> STACK is over flow  <<..\n");
        }
        else {
        printf("--> Enter value for push : ");
        scanf("%d",&val);
        push(val,stack);
        }
        break;

        case 2:
        if(top==-1) {
            printf("..>> STACK is under flow  <<..\n");
        }
        else {
            pop(stack);
            
        }
        break;

        case 3:
        if(top==-1) {
            printf("..>> STACK is empty  <<..\n");
        }
        else {
            peekval=peek(stack);
            printf("--> Top most element of STACK is : %d\n",peekval);
        }
        break;

        case 4:
        if(top==-1) {
            printf("..>> STACK is emplty  <<..\n");
        }
        else {
            display(stack);
        }
        break;

        case 5:
        
        if(top==-1) {
            printf("..>> STACK is emplty  <<..\n");
        }
        else {
        printf("Enter the number you want to find in stack : ");
        scanf("%d",&valfind);
        peep(valfind,stack);
        }
        break;

        case 6:
        if(top==-1) {
            printf("..>> STACK is emplty  <<..\n");
        }
        else {
        printf("Enter the number you want to change with top element of stack : ");
        scanf("%d",&main_valchange);
        change(main_valchange,stack);
        }
        break;

        case 7:
        mainsum=count(stack);
        printf("Total number of elements in stack : %d\n",mainsum);
        break;

        case 8:
        printf("# OVER #\n");
        break;

        default : 
        printf(".. Invalid choice  ..\n");
        break;
    }
    }while(option!=8);

return 0;
}
void push(int val,int stack[]){
    top++;
    stack[top]=val;
}
void pop(int stack[]) {
    int value1;
    value1=stack[top];//value1 is initialize by top element of stack && and after top element is forget by using top--
    printf("--> Top most element %d is deleted !\n",value1);
    top--;
}
int peek(int stack[]) {
    return stack[top];
}
void display(int stack[]) {
    for(int i=top; i>=0; i--) {
        printf("%d\n",stack[i]);
    }
}
void peep(int valuefind,int stack[]) {
    for(int j=top; j>=0; j--) {
        if(stack[j]==valuefind) {
            printf("stack[%d] : %d\n",j,valuefind);
        }
    }
}
void change(int valuechange,int stack[]) {
    int temp;
    temp=stack[top];
    stack[top]=valuechange;
    
}
int count(int stack[]) {
    int sum=0;
    for(int c=top; c>=0; c--) {
        sum++;
    }
    return sum;
}