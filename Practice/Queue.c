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

// is Full
int isFull(struct queue*q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}

// displlay
void Display(struct queue*q){
    if(isEmpty(q)){
        printf("queue Empty");
    }
    else{
        printf("Queue Element are : ");
        for(int i=q->f;i<=q->r;i++){
            printf("%d ",q->arr[i]);
        }
    }
}

// Enqueue
void Enqueue(struct queue*q , int data){
    if(isFull(q)){
        printf("Queue Overfow");
    }
    else if(isEmpty(q)){
        q->f++;
        q->r++;
        q->arr[q->r]=data;
    }
    else{
        q->r++;
        q->arr[q->r]=data;
    }
}

// Dequeue
void Dequeue(struct queue*q ){
    if(isEmpty(q)){
        printf("Queue Underflow");
    }
    else{
        q->f++;
    }
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
            Enqueue(q, data);
            break;

        case 2:
            Dequeue(q);
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