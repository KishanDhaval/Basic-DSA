#include<stdio.h>
#include<stdlib.h>


// is Sorted
int isSorted(int arr[],int n){
    int sort=1;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            sort=0;
        }
    }
    return sort;
}

// Display
void Display(int *arr , int  n){
    for(int i=0;i<=n-1;i++)
    {
        printf("%d ",arr[i]);
    }
}

// swap function
void Swap(int *a , int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

// Selection Sort
void SelectioSort(int arr[],int n){
    
    for(int i=0;i<=n-1;i++){

        for(int j=i+1;j<=n-1;j++){
            if(arr[i]>arr[j]){
               Swap(&arr[i],&arr[j]);
            }
        }
    }
}


int main()
{
    
    int arr[20]={1,5,32,238,23,9,3,2};
    int n=8;
    SelectioSort(arr,n);
    Display(arr,n);

    return 0;
}