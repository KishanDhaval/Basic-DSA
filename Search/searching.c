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

// Linear search
int LinearSearch(int arr[],int ele, int n){
    int pos=-1;

    for(int i=0;i<=n;i++){
        if(arr[i]==ele){
            pos=i;
        }
    }
    if(pos==-1){
        printf("Value not found\n");
    }
    else{
        // return pos+1;
        printf("searched element at %d position\n",pos+1);
    }
}


// Binary Searcch
int BinarySearch(int arr[],int ele,int n){
    int low=0;
    int high=n-1;
    int mid;
    int found=0;

    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==ele){
            found=1;
            break;
        }
        else{
            if(ele < arr[mid]){
                high=mid-1;    
            }
            else{
                low=mid+1;
            }
        }
    }
if(found==0){
    printf("element not found\n");
}
else{
    printf(" Searched element found at %d position\n",mid+1);
}
}



int main()
{
    // int arr[10]={1,4,2,66,7,3};
    // int n=6;
    int ele;
    int option;
    int arr[20];
    int n;
    printf("How many element you want to add\n");
    scanf("%d",&n);
    printf("enter element\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

while(1){

    printf("Which element you want to search : ");
    scanf("%d",&ele);
    if(isSorted(arr,n)){
        BinarySearch(arr,ele,n);
    }
    else{
        LinearSearch(arr,ele,n);
    }

   }
     
    return 0;
}