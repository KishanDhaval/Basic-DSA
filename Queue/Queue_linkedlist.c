#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// create node
struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->next = NULL;
    new_node->data = data;
    return new_node;
}

// is Empty
int isEmpty(struct node* f) {
    if (f == NULL) {
        return 1;
    }
    return 0;
}

// is Full
int isFull(struct node* f) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        return 1;
    }
    free(new_node);  // Free the allocated memory
    return 0;
}

// Display
void Display(struct node* f) {
    if (isEmpty(f)) {
        printf("Queue Empty\n");
    } else {
        printf("Now Elements are: ");
        while (f != NULL) {
            printf("%d ", f->data);
            f = f->next;
        }
        printf("\n");
    }
}

// Enqueue
struct node* Enqueue(struct node* f, struct node* r, int data) {
    if (isFull(f)) {
        printf("Queue overflow\n");
    } else {
        struct node* new_node = create_node(data);
        if (isEmpty(f)) {
            f = r = new_node;
        } else {
            r->next = new_node;
            r = new_node;
        }
        return f;
    }
}

// Dequeue
struct node* Dequeue(struct node* f) {
    if (isEmpty(f)) {
        printf("Queue Underflow\n");
    } else {
        struct node* temp = f;
        f = f->next;
        free(temp);
    }
    return f;
}

int main() {
    struct node* f = NULL;
    struct node* r = NULL;

    int option, data;

    while (1) {
        printf("\n+-+-+-+-+-+-+-+-+\n");
        printf("1 For Enqueue\n");
        printf("2 For Dequeue\n");
        printf("3 For Display\n");
        printf("4 For Exit\n");
        printf("+-+-+-+-+-+-+-+-+\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the Element you want to Enqueue\n");
                scanf("%d", &data);
                f = Enqueue(f, r, data);
                break;

            case 2:
                f = Dequeue(f);
                break;

            case 3:
                Display(f);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid option\n");
                break;
        }
    }

    return 0;
}