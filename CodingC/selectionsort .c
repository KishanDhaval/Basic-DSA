#include<stdio.h>

void printarray(int *A,int n) {
    for(int i=0; i<n; i++) {
        printf("%d  ",A[i]);
    }
    printf("\n");
}

void selectionsort(int*A,int n) {
    int indexofmin,temp;
    
    for(int i=0; i<n-1; i++) {
        indexofmin=i; 
        //for comparison with indexofmin 
        for(int j=i+1;j<n-1;j++){
            if(A[indexofmin]>A[j]){
                indexofmin =j;
            }
        }
        temp=A[i];
        A[i]= A[indexofmin];
        A[indexofmin]=temp;
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
    selectionsort(A,n);
    printf("after insertionsort:");
    printarray(A,n);

    return 0;
}