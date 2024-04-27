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

//delete at beginning
struct node * deletatfirst(struct node * head) {
    struct node *ptr=(struct node *)malloc(sizeof(struct node));

    ptr->next=head;
    head=head->next;
    free(ptr);

    return head;

}




//insert at between
struct node*deletatbetween(struct node*head,int index)
{   int i=0;

    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    struct node*p=(struct node*)malloc(sizeof(struct node));

    p->next=head;

    while(i!=index-1) {
        p=p->next;
        i++;
    }

    ptr=p->next;
    p->next=ptr->next;
    free(ptr);
    return head;
}



//insert at end
struct node * deletatend(struct node * head) {

    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    struct node*p=(struct node*)malloc(sizeof(struct node));

    p->next=head->next;
    ptr->next=head;
    int i=0;
    while(p->next!=NULL) {
        p=p->next;
        ptr=ptr->next;
        i++;
    }

    ptr->next=NULL;
    free(p);

    return head;
}


//insert after given node

struct node*deletafternode(struct node*head, int value) {

    struct node*p=head;
    struct node*ptr=head->next;


    while(p->data!=value)
    {
        p=p->next;
        ptr=p->next;
    }
    p->next=ptr->next;
    free(ptr);
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
    third->next=NULL;

    traveling (head);
    printf("\n");


    //head=deletatfirst(head);
    // head=deletatbetween(head,3);
    // head=deletatend(head);
    //deletafternode(head,10);
    traveling (head);

    return 0;
}