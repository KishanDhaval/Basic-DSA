#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
// travelser
int traveling (struct node *ptr) {
    while(ptr!=NULL)
    {
        printf("Element:%d\n",ptr->data);
        ptr=ptr->next;
    }
}

//insert at beginning
/*struct node * insertatfirst(struct node * head,int data){
struct node *ptr=(struct node *)malloc(sizeof(struct node));

ptr->next=head;
ptr->data=data;

return ptr;

}



*/
/*insert at between
struct node*insertatbetween(struct node*head,int data,int index)
{   int i=0;

    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    struct node*p=(struct node*)malloc(sizeof(struct node));

    p->next=head;

    while(i!=index-1) {
        p=p->next;
        i++;
    }

    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
*/


/*insert at end
struct node * insertatend(struct node * head,int data) {

    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    struct node*p=(struct node*)malloc(sizeof(struct node));

    p->next=head;
    int i=0;
    while(p->next!=NULL) {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;

    return head;
}
*/

/*insert after given node

struct node*insertafternode(struct node*node,int data){

    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=node->next;
    node->next=ptr;
    
}
*/

int main()
{
    struct node *head;
    struct node *first;
    struct node *second;
    struct node *third;
    head=(struct node* ) malloc (sizeof (struct node));
    first=(struct node* ) malloc (sizeof (struct node));
    second=(struct node* ) malloc (sizeof (struct node));
    third=(struct node* ) malloc (sizeof (struct node));

    head-> data = 7;
    head->next=first;
    first->data=10;
    first->next=second;
    second->data=8;
    second->next=third;
    third->data=11;
    third->next=NULL;

    traveling (head);
    printf("\n");
    
//head=insertatfirst(head,77);
  //  head=insertatbetween(head,55,3);
  //head=insertatend(head,567);
 // insertafternode(second,276);
    traveling (head);

    return 0;
}