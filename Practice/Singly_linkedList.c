#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

// create newnode
struct node*create_node(int data){
    struct node*New_node=(struct node*)malloc(sizeof(struct node));
    New_node->data=data;
    New_node->next=NULL;
    return New_node;
}

// isEmpty
int isEmpty(struct node*head){
    if(head==NULL){
        return 1;
    }
    return 0;
}

// Display
void Display(struct node*head){
    if(isEmpty(head)){
        printf("Linked list Empty");
    }
    else{
        while(head!=NULL){
            printf("%d  ",head->data);
            head=head->next;
        }
    }
}

// insert at begining
struct node * InsertBegining(struct node *head,int data){
    struct node*New_node=create_node(data);
    if(isEmpty(head)){
        head=New_node;
    }
    else{
        New_node->next=head;
        head=New_node;
    }
    return head;
}

// insert at index
struct node*InsertIndex(struct node*head , int data , int index){
    struct node*New_node=create_node(data);
    if(isEmpty(head)){
        printf("linnked List Empty");
    }
    else{
        int i=0;
        struct node*temp=head;
        while(i!=index-2){
            temp=temp->next;
            i++;
        }
        New_node->next=temp->next;
        temp->next=New_node;
    }
    return head;
}

// insert after
struct node*InsertAfter(struct node*head,int data, int ele){
    struct node*New_node=create_node(data);
    if(isEmpty(head)){
        printf("linked list is Empty");
    }
    else{
        struct node*temp=head;
        while(temp->data!=ele){
            temp=temp->next;
        }
        New_node->next=temp->next;
        temp->next=New_node;
    }
    return head;
}

// insert at End
struct node*InsertEnd(struct node*head , int data){
    struct node*New_node=create_node(data);
    if(isEmpty(head)){
        head=New_node;
    }
    else{
        struct node*temp=head;
        while(temp!=NULL){
            temp=temp->next;
        }
        New_node->next=temp->next;
        temp->next=New_node;
    }
    return New_node;
}

// Delete at begining
struct node*DeleteBegining(struct node*head){
    struct node*temp=head;
    if(isEmpty(head)){
        printf("linked list is Empty");
    }
    else if(head->next==NULL){
        temp=head;
        head=NULL;
        free(temp);
    }
    else{
        temp=head;
        head=head->next;
        free(temp);
    }
    return head;
}

// Delete at index
struct node*DeleteIndex(struct node*head,int index){
    
    if(isEmpty(head)){
        printf("lnked lst Empty");
    }
    else{
        struct node*temp=head;
    struct node*del=head->next;
        int i=0,pos=0;
        while(i!=index-1){
            i++;
            pos++;
        }
        for(i=0;i<=pos-1;i++){
            temp=temp->next;
            del=del->next;
        }
        temp->next=del->next;
        free(del);
    }
    return head;
}

// Delete After
struct node*DeleteAfter(struct node*head,int ele){
    if(isEmpty(head)){
        printf("linked list is Empty");
    }
    else{
        struct node*temp=head;
        struct node*del=head->next;
        while(temp->data!=ele){
            temp=temp->next;
            del=del->next;
        }
        temp->next=del->next;
        free(del);
    }
    return head;
}

// Delete at End
struct node*DeleteEnd(struct node*head){
    if(isEmpty(head)){
        printf("linked list is Empty");
    }
    else if(head->next==NULL){
        struct node*del=head;
        head=NULL;
        free(del);
    }
    else{
        struct node*temp=head;
        struct node*del=head->next;
        while(del->next!=NULL){
            temp-temp->next;
            del=del->next;
        }
        temp->next=NULL;
        free(del);
    }
    return head;
}

// count node
void CountNode(struct node*head){
    int count=0;
    if(isEmpty(head)){
        printf("Total Number of node is: %d",count);
    }
    else{
        struct node*temp=head;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        printf(" Total Number of node in linked list is :%d",count);
    }
}



int main()
{
    struct node*head=(struct node*)malloc(sizeof(struct node));
    head=NULL;
 

 int option;
 int data,ele ,index;
    
while(1){

    printf("\n+===========================+\n");
    printf("1 for insert at begening\n");
    printf("2 for insert At given position\n");
    printf("3 for insert the after perticular value\n");
    printf("4 for insert At the End  \n");
    printf("5 for delete at begening\n");
    printf("6 for delete At given position\n");
    printf("7 for delete the after perticular value\n");
    printf("8 for delete At the End  \n");
    printf("9 for Display\n");
    printf("0 for Exit\n");
    printf("+===========================+\n");


    scanf("%d",&option);
    switch(option){
        case 1:
            printf("which element you want to Add :");
            scanf("%d",&data);
           head= InsertBegining(head,data);
            break;
            
        case 2:
           printf("which element you want to Add :");
           scanf("%d",&data); 
           printf("At which pos");
           scanf("%d",&index);
           if(index<=0){
            printf("invaid position");
           }
           head= InsertIndex(head,data,index);
           break;

        case 3: 
            printf("which element you want to Add  :");
            scanf("%d",&data);
            Display(head);
            printf("After which element ? ");
            scanf("%d",&ele);
            head=InsertAfter(head,data,ele);
            break;

        case 4:
            printf("which element you want to Add  :");
            scanf("%d",&data);
            head=InsertEnd(head,data);
            break;

        case 5:
            head= DeleteBegining(head);
            break;

        case 6:
            printf("At which poosition you want to Delete : ");
            scanf("%d",&index);
            if(index<=0){
            printf("invaid position");
            }
            else{
            head=DeleteIndex(head,index);
            }
            break;

        case 7:
            printf("After which element you want to delete : ");
            scanf("%d",&ele);
            head=DeleteAfter(head,ele);
            break;
             
        case 8:
            head=DeleteEnd(head);
            break;
           
        case 9:
             Display(head);
             break;

        case 10:
            CountNode(head);  
            break;

        case 0:
            exit(0);
            break;     

        }
    }



    return 0;
}