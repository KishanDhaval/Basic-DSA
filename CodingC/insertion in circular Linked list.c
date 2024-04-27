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

//insert at beginning circular linked list
struct node * insertatfirst(struct node * head,int data) {
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;

    struct node*p=head->next;
    while(p->next!=head) {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
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


   // head=insertatfirst(head,567);
    
    traveling (head);

    return 0;
}