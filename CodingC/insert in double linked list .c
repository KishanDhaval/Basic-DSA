#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

// Traversal
void traverse(struct node *ptr) {
    while(ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Insert at the beginning
struct node* insertfirst(struct node* head, int data) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    ptr->prev = NULL;
    
    if (head != NULL) {
        head->prev = ptr;
    }
    
    return ptr;
}

// Insert at the end
struct node* insertAtEnd(struct node* head, int data) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    
    if (head == NULL) {
        ptr->prev = NULL;
        return ptr;
    }
    
    struct node* p= head;
    while (p->next != NULL) {
        p = p->next;
    }
    
    p->next = ptr;
    ptr->prev = p;
    
    return head;
}

//insert after given node
struct node*insertafter(struct node*head,int data , int val){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
  ptr->data=data;
     struct node* p=head;
   while(p->data!=val){
       p=p->next;
   }
   ptr->next=p->next;
   p->next=ptr;
   ptr->prev=p;
   ptr->next->prev=ptr;
  return head;  
}

//before given node
struct node*insertbefore(struct node*head,int data , int val){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
  ptr->data=data;
  struct node* p=head;
  while (p->data!=val){
      p=p->next;
  }
     ptr->next=p;
     p->prev->next=ptr;
     ptr->prev=p->prev;
  return head;
  }

int main() {
    struct node *head = NULL;
    
    head = insertfirst(head, 7);
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 8);
    head = insertAtEnd(head, 11);
    head=insertafter(head,77,10);
    head=insertbefore(head,77,10);
    traverse(head);
    printf("\n");

    return 0;
}