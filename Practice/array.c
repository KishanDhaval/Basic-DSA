#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// array size
int Size(int arr[]){
    int i=0;
    int size=0;
    while(arr[i]!='\0'){
        size++;
        i++;
    }
    return size;
}

// Display
void Display(int arr[] , int size){
    for(int i=0;i<=size-1;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

// Insertion
void Insertion(int arr[],int size,int ele ,int pos ){
    int i;
    for( i=size-1;i>=pos-1;i--){
        arr[i+1]=arr[i];
    }
    arr[i+1]=ele;
    // size++;
}

// delete
void Delete(int arr[],int size,int ele){
   int i=0,pos=0;
    while(arr[i]!=ele){
        pos++;
        i++;
    }
    for(i=pos;i<=size-1;i++){
        arr[i]=arr[i+1];
    }
}

int main()
{   int ele,pos;
    int arr[100]={1,4,7,23,6};
    int size =Size(arr);
    Display(arr,size);

    // For Insertion
    printf("which Element ? :");
    scanf("%d",&ele);
    printf("which position? :");
    scanf("%d",&pos);       
    Insertion(arr,size,ele,pos);
    size++;
    Display(arr,size);   


    // for Delete
    printf("which Element ? :");
    scanf("%d",&ele);
    Delete(arr,size,ele) ; 
    size--;
    Display(arr,size);

    return 0;
}