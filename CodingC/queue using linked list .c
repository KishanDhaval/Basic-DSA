#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Traversal
void traveling(struct node* f) {
    while (f != NULL) {
        printf("Element: %d\n", f->data);
        f = f->next;
    }
}

struct node* enqueue(struct node* f, struct node* r, int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;

    if (r == NULL) {
        f = r = n;
    } else {
        r->next = n;
        r = n;
    }

    return f;
}

struct node* dequeue(struct node* f, struct node* r) {
    if (f == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return f;
    }
    
    struct node* temp = f;
    f = f->next;
    free(temp);
    
    if (f == NULL) {
        // If the queue becomes empty after dequeue, reset the rear pointer.
        r = NULL;
    }

    return f;
}

int main() {
    struct node* f = NULL;
    struct node* r = NULL;

    printf("Queue before enqueue:\n");
    traveling(f);

    printf("\nEnqueuing 726:\n");
    f = enqueue(f, r, 38);
    

    printf("\nQueue after enqueue:\n");
    traveling(f);

    printf("\nDequeuing:\n");
    f = dequeue(f, r);

    printf("\nQueue after dequeue:\n");
    traveling(f);

    return 0;
}