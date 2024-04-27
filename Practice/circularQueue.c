#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

// is Empty
int isEmpty(struct queue*q){
    if(q->f==-1){
        return 1;
    }
    return 0;
}

// is full
int isFull(struct queue*q){
   if((q->r+1)%q->size==q->f){
    return 1;
   }
   return 0;
}

// Display
void Display(struct queue *q) {
    if (isEmpty(q)) {
        printf("Queue Empty");
    } else {
        int i = q->f;
        do {
            printf("%d ", q->arr[i]);
            i = (i + 1) % q->size;
        } while (i != (q->r + 1) % q->size);
    }
}


// Enqueue
struct queue*Enqueue(struct queue*q , int data){
    
    if(isFull(q)){
        printf("Queue Overflow");
    }
    else {
        if(q->f==-1 &&q->r==-1){
            q->f=q->r=0;
            q->arr[q->r]=data;
        }
        else{
            q->r=(q->r+1)%q->size;
            q->arr[q->r]=data;
        }
    }
    return q;
}

// Dequeue
struct queue* Dequeue(struct queue*q){
    if(isEmpty(q)){
        printf("Queue Underflow");
    }
    else{
        if(q->f == q->r){
            q->f = q->r = -1;
        }
        else{
            q->f = (q->f + 1) % q->size;
        }
    }
    return q;
}

int main()
{
    
    struct queue*q=(struct queue*)malloc(sizeof(struct queue));
    q->size=10;
    q->f=q->r=-1;
    q->arr=(int*)malloc(q->size*sizeof(int));



    int option, data;

    while (1)
    {
        printf("\n+-+-+-+-+-+-+-+\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("0. Exit\n");
        printf("+-+-+-+-+-+-+-+\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("which Element you want to Enqueue\n");
            scanf("%d", &data);
            q=Enqueue(q, data);
            break;

        case 2:
            q=Dequeue(q);
            break;

        case 3:
             Display(q);
             break;

        case 0:
            exit(0);
            break;

        default :
            printf("Invalid Input");
            break;            
        }
    }

    return 0;
}