#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

// Size of array
int Size(int arr[]){
    int i=0;
    int n=0;
     while(arr[i]!='\0'){
            n++;
            i++;
        }
        return n;
}

// Display
void Display(int *arr , int  n){
    for(int i=0;i<=n-1;i++)
    {
        printf("%d ",arr[i]);
    }
}

// Insertion Sort
// void InsertionSort(int arr[] , int n){

//     for(int i=1 ; i<=n-1 ; i++){
//        int temp=arr[i];
//        int j=i-1;
//         while(arr[j]>temp && j>=0){
//             arr[j+1]=arr[j];
//             j--;
//         }
//         arr[j+1]=temp;
//     }
// }






void InsertionSort(int arr[], int n){
    for (int i=0;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

void Bubble(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
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
    

    int arr[20]={1,5,32,43,21,11,3,2};
   
    int n=Size(arr);  
        Display(arr,n);
        printf("\n");
    // InsertionSort(arr,n);
    Bubble(arr,n);
    Display(arr,n);
    return 0;
}