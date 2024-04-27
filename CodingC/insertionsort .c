#include<stdio.h>

void printarray(int *A,int n) {
    for(int i=0; i<n; i++) {
        printf("%d  ",A[i]);
    }
    printf("\n");
}

void insertionsort(int*A,int n) {
    int key,j;
     
    //for passes
    for(int i=1; i<=n-1; i++) { 
        key=A[i];
        j=i-1;
        //for each passes
        while(j>=0&&A[j]>key){
           A[j+1]=A[j];
           j--; 
        } 
        A[j+1]=key;
    }
}

int main()
{
    int A[10]= {4,15,8,2,9,5},n=6,i=0;
    // int A[10]={1,2,3,4,5,6},n=6,i=0;
   /*
       printf("what is lenght");
     scanf("%d",&n);

     while(i!=n){
     printf(" element %d is:",i+1);
     scanf("%d",&A[i]);
     i++;
     }
     */

    printf("before insertionsort:");
    printarray(A,n);
    insertionsort(A,n);
    printf("after insertionsort:");
    printarray(A,n);

    return 0;
}