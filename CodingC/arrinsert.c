#include<stdio.h>

void Display(int arr[], int n){
    for(int i=0;i<=n-1;i++){
        printf("%d ",arr[i]);
    }
}

int insert(int arr[],int size,int capacity,int index,int element ) {
        for(int i=size-1; i>=index; i--) {
            arr[i+1]=arr[i];

        }
        arr[index]=element ;
        return 1;
        for(int i=0; i<=size; i++) {
            printf("%d",arr[i]);
        }
    
}

int main()
{

    int size=4, element=12, index=2, capacity=100;
    int arr[100]= {1,3,7,9};


    insert(arr,size, capacity, index, element);
    size+=1;
    Display(arr,size);
    return 0;
}

