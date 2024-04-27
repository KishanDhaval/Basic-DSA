#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

int traversal (struct node*top){
    
        while(top!=NULL){
            printf("%d\n",top->data);
            top=top->next;
        }
}

int isEmpty (struct node *top){
    if(top==NULL)
      //  return 1;
      printf("stack is empty");
     else
       //  return 0;  
       printf("stack is not empty"); 

}


int isFull(struct node *top){
    struct node*n=(struct node*)malloc(sizeof(struct node));
        if(n==NULL){
        printf("stack is FULL");
        }
        else{
         printf("stack is not full");
        }

}


struct node* push(struct node *top,int data){
    struct node*n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->next=top;
    top=n;
    return top;
}


struct node* pop(struct node*top){
    struct node*n=top;
    top=n->next;
    free(n);
    return top;
}


struct node* peak(struct node*top,int pos){
    struct node*n=top;
    int i=0;
    while(i!=pos-1 && n!=NULL)
    {
        n=n->next;
        i++;
    }
    return n->data;
}



int main()
{
    struct node *top=NULL;
    
    
    printf("\n");
       top=  push(top,33);
       top=  push(top,58);
       top=  push(top,39);
       top=  push(top,28);
    //   top= pop(top);
  //  isFull(top);
  
//    traversal (top);
printf("%d",peak(top,2));
   
    isEmpty (top);

    return 0;
}