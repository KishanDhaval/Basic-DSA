#include<stdio.h>

void printarray(int *A,int n) {
    for(int i=0; i<n; i++) {
        printf("%d  ",A[i]);
    }
    printf("\n");
}

void bubbleSortAdp(int*A,int n) {

    int issorted=0;
    for(int i=0; i<n-1; i++) { //for number of pass
        printf("sorted pass in number %d\n",i+1);
        issorted=1;

        for(int j=0; j<n-1-i; j++) { //for comparison of num of pass

            if(A[j]>A[j+1]) {
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                issorted=0;

            }
        }
        if(issorted)
            return ;
    }
}


void bubblesort(int*A,int n) {

    for(int i=0; i<n-1; i++) { //for number of pass

        for(int j=0; j<n-1-i; j++) { //for comparison of num of pass

            if(A[j]>A[j+1]) {
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;

             
            }
        }
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

    printf("before bubble sort:");
    printarray(A,n);
    // bubbleSortAdp(A,n);
    bubblesort(A,n);
    printf("after bubble sort:");
    printarray(A,n);

    return 0;
}