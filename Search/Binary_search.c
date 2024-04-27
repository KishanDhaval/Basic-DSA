#include<stdio.h>
#include<stdlib.h>

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
    int arr[20]={2,3,11,15,23,28,34,37,55};
    int n=9;
    int ele;
while(1){
    printf("which element you want to search :");
    scanf("%d",&ele);
    BinarySearch(arr,ele,n);
}

    return 0;
}