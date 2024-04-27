#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
// travelser
int traveling (struct node *head) {

    struct node* ptr=head;
    do
    {
        printf("Element:%d\n",ptr->data);
        ptr=ptr->next;
    } while(ptr!=head);
}

//delet at beginning circular linked list
struct node * deleteatfirst(struct node * head) {
    struct node *ptr=head;
    struct node*p=head->next;
    while(p->next!=head){
        p=p->next;
    }
    
    head=head->next;
    p->next=head;
    free(ptr);
    return head;
}

// delete at end
struct node* deleteatend(struct node*head) {
    struct node*ptr=head->next;
    struct node*p=head;

    while(ptr->next!=head) {
        ptr=ptr->next;
        p=p->next;
    }
    p->next=head;
    free(ptr);
    return head;
}

//delete after given node
struct node*deleteafter(struct node*head,struct node*node){
    struct node *ptr=node->next;
    node->next=ptr->next;
    free(ptr);
    return head;
}

//delete before given node
struct node* deletebefore(struct node*head,struct node*node){
    struct node *ptr=head->next;
    struct node*p=head;
    while (ptr->next!=node){
        ptr=ptr->next;
        p=p->next;
    }
    p->next=node;
    free(ptr);
   return head; 
}


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
    third->next=head;

    traveling (head);
    printf("\n");
    //head=deleteatfirst(head);
  //  head=deleteatend(head);
   //head=deleteafter(head, first);
    //head=deletebefore(head,  second);
    traveling (head);

    return 0;
}