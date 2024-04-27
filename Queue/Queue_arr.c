#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

// is Empty
int isEmpty(struct queue *q)
{
    if (q->f == -1)
    {
        return 1;
    }
    return 0;
}

// is Full
int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

// Display
void Display(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow");
    }
    else
    {
        printf("\nQueue : ");
        for (int i = q->f; i <= q->r; i++)
        {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}


// Enqueue
struct queue *Enqueue(struct queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue Overflow");
    }
    else
    {
        if (isEmpty(q))
        {
            q->f = q->r = 0;
        }
        else
        {
            q->r++;
        }
        q->arr[q->r] = data;
    }
    return q;
}

// Dequeue
struct queue *Dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow");
    }
    else if (q->f == q->r)
    {
        q->f = q->r = -1;
    }
    else
    {
        q->f++;
    }
    return q;
}

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    int option, data;

    while (1)
    {
        printf("\n+-+-+-+-+-+-+-+-+\n");
        printf("1 For Enqueue\n");
        printf("2 For Dequeue\n");
        printf("3 For Display\n");
        printf("+-+-+-+-+-+-+-+-+\n");
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