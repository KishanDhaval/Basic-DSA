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
void Display( int arr[],int n){
    int i=0;
 for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
 }
 printf("\n");
    
}

// Bubble sort
void BubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}



int main()
{
    int n=4;
    int arr[30]={1,4,32,2};
    // printf("how many element you want to add in array\n");
    // scanf("%d",&n);
    // printf("Enter array element : ");
    // for(int i=0; i<n;i++){
    //     scanf("%d",&arr[i]);
    // }
    printf(" before sorting\n");
    Display(arr,n);
    BubbleSort(arr,n);
    printf("after sorting\n");
    Display(arr,n);
//    printf("%d", isSorted(arr,n));



    return 0;
}