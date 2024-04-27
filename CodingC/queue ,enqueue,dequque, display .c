#include<stdio.h>
#include<stdlib.h>

struct queue {
    int size;
    int f;
    int r;
    int*arr;
};

void display (struct queue*q){
  q->f=q->f+1;
    while(q->f<=q->r){
        printf("%d\n",q->arr[q->f]);
        q->f=q->f+1;
    }
}

int isEmpty(struct queue*q){
    if(q->f==q->r)
        return 1;
    else    
        return 0 ;
}


int isFull (struct queue*q){
    if(q->r==q->size-1)
        return 1;
    else
        return 0;    
}

void enqueue(struct queue *q,int val){
   if(isFull(q)){
       printf("queue over flow enqueue not possible\n");
   }
   else{
        q->r=q->r+1;
        q->arr[q->r]=val;
   }
}

int dequeue(struct queue*q){
    int a;
    if(isEmpty(q)){
        printf("queue underflow dequeue not possible\n");
    }
    else{
        q->f++;
        a=q->arr[q->f];
        return a;
    }
    printf("\n");
}

int main()
{
    struct queue q;
    q.size=5;
    q.f=q.r=-1;
    q.arr=(int*)malloc(q.size*sizeof(int));
    enqueue(&q,13);
    enqueue(&q,8);
    enqueue(&q,28);
    enqueue(&q,7);
    
    if(isFull(&q))
        printf("queue is full");
    if(isEmpty(&q))
        printf("queue is empty");    
    
  //  printf("Dequeue Element is: %d",dequeue(&q));
    display (&q);
    return 0;
}