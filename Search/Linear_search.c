#include<stdio.h>
#include<stdlib.h>

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
        printf("searched element AT %dth position\n",pos+1);
    }
}


int main()
{
    int arr[10]={1,4,2,66,7,3};
    int n=6;
    int ele;
    int option;
while(1){
    printf("which element youu want to search : ");
    scanf("%d",&ele);
    //printf("element is at  %d position ",LinearSearch(arr,ele,n)); 
    LinearSearch(arr,ele,n);
   }
     
    return 0;
}