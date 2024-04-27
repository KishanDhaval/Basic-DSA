#include<stdio.h>

int linearsearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

int binarysearch(int arr[],int size,int element){
   int high=size-1;
   int low=0;
    int mid;
    
    
    while(low<=high){
    mid=(low+high)/2;
        if(arr[mid]==element){
            return mid;
        }
        if(arr[mid]<element){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}


int main()
{
   // int arr[] = {1, 43, 6, 7, 9, 8, 47, 98};
   int arr[] = {1, 3, 6, 7, 9, 10, 47, 98};
    int size = sizeof(arr) / sizeof(int);
    int element = 47;
   // printf("Element %d is found at index %d", element, linearsearch(arr, size, element));
    printf("Element %d is found at index %d", element, binarysearch(arr, size, element));
   
    return 0;
}