#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
// IS Empty 
int isEmpty(struct node*head){
    if(head==NULL){
        return 1;
    }
    return 0;
}

struct node*create_node(int data){
    struct node*New_node=(struct node*)malloc(sizeof(struct node));
    New_node->data=data;
    New_node->next=NULL;
    return New_node;
}

// Display
int Display (struct node *ptr) {
   
   if(isEmpty(ptr)){
    printf("linkedlist empty\n");
   }
   else{
    printf("Now Element in linkedlist are : ");
    while(ptr!=NULL)
    {
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    }
   }
}


//insert at beginning
struct node * insertatfirst(struct node * head,int data)
{
struct node *New_node=create_node(data);
New_node->data=data;

if(isEmpty(head)){
  head=New_node;
}
else{
    New_node->next=head;
    head=New_node;
}
return head;
}

//insert at given index
struct node*insertatindex(struct node*head,int data,int index)
{   int i=0;

    struct node*New_node=create_node(data);
    New_node->data=data;
    if(isEmpty(head)){
        printf("invalid index ,can't add");
    }
    else{
     struct node*temp=create_node(data);
     temp->next=head;
    while(i!=index-1) {
        temp=temp->next;
        i++;
    }
     New_node->next=temp->next;
    temp->next=New_node;
    }
 return head;
}


//insert after given Element

struct node*insertafterelement(struct node*head,int ele,int data){
    int pos=0;
  struct node*New_node=create_node(data);
    New_node->data=data;
    struct node*temp=head;
    while(temp->data!=ele){
        temp=temp->next;
    }
    New_node->next=temp->next;
    temp->next=New_node;   
    return head;
}



// insert at end
struct node* insertatend(struct node * head,int data) {

    struct node*New_node=create_node(data);
    New_node->data=data;

    if(isEmpty(head)){
        head=New_node;
    }
    else{
         struct node*temp=head;
   
        while(temp->next!=NULL) {
             temp=temp->next;
         }
    
             New_node->next=temp->next;
            temp->next=New_node;
    }
   return head;
}


// delete at begining
  struct node *Delete_first(struct node *head){
    if(isEmpty(head)){
        printf("Deletion not posible , linkedlist Empty\n");
    }
    else{
        struct node*temp=head;
        head=head->next;
        free(temp);
    }
    return head;
}

// delete At given position
struct node* Delete_At_index(struct node*head,int index){
    if(isEmpty(head)){
        printf("Deletion not posible linkedlist Empty");
    }
    else{
        int i=0;
        struct node*temp1=head;
         struct node*temp2=head->next;
        while(i!=index-2){
            temp1=temp1->next;
            temp2=temp2->next;
            i++;
        }
        temp1->next=temp2->next;
        free(temp2);
    }
    return head;
}

// delete after perticular element
struct node* Delete_after(struct node *head,int ele){
    if(isEmpty(head)){
        printf("Deletionn not posible linkedlist empty");
    }
    else{
        struct node*temp1=head;
        struct node*temp2=head->next;
        while(temp1->data!=ele){
            temp1=temp1->next;
             temp2=temp2->next;
        }
        temp1->next=temp2->next;
        free(temp2);
    }
    return head;
}

// delete at the end
struct node*Delete_end(struct node*head){
    
    if(isEmpty(head)){
        printf("Deletion not posible , LInkedlist empty");
    }
    else{
        if(head->next==NULL){
            struct node*ptr=head;
            free(ptr);
            head=NULL;
            }
        else{
           struct node * temp1=head->next;
             struct node * temp2=head;

             while(temp1->next!=NULL){
            temp1=temp1->next;
            temp2=temp2->next;
                }
             temp2->next=NULL;
            free(temp1);
            }
        }
    return head;
}


int main()
{
    struct node *head=NULL;
  
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
    printf("+===========================+\n");


    scanf("%d",&option);
    switch(option){
        case 1:
            printf("which element you want to Add :");
            scanf("%d",&data);
           head= insertatfirst(head,data);
            break;
            
        case 2:
           printf("which element you want to Add :");
           scanf("%d",&data); 
           printf("At which pos");
           scanf("%d",&index);
           if(index<=0){
            printf("invaid position");
           }
           head= insertatindex(head,data,index);
           break;

        case 3: 
            printf("which element you want to Add  :");
            scanf("%d",&data);
            Display(head);
            printf("After which element ? ");
            scanf("%d",&ele);
            head=insertafterelement(head,ele,data);
            break;

        case 4:
            printf("which element you want to Add  :");
            scanf("%d",&data);
            head=insertatend(head,data);
            break;

        case 5:
            head= Delete_first(head);
            break;

        case 6:
            printf("At which poosition you want to Delete : ");
            scanf("%d",&index);
            head=Delete_At_index(head,index);
            break;

        case 7:
            printf("After which element you want to delete : ");
            scanf("%d",&ele);
            head=Delete_after(head,ele);
            break;
             
        case 8:
            head=Delete_end(head);
            break;
           
        case 9:
             Display(head);
             break;   

        case 0:
            exit(0);
            break;     

        }
    }
    return 0;
}