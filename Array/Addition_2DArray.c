#include<stdio.h>
#include<stdlib.h>

int main()
{
  
    int row1,col1, row2 , col2;

    printf("For Addition both arrays row and col must be same\n\n");

    printf("How many row in array 1 :");
    scanf("%d",&row1);
    printf("How many col in array 1 :");
    scanf("%d",&col1);
   
    int arr1[row1][col1];
    
    // Taking 1st array Element
   
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            printf(" Element(%d,%d) is : ",i+1,j+1);
            scanf("%d",&arr1[i][j]);
        }
    }

    printf("How many row in array 2 :");
    scanf("%d",&row2);
    printf("How many col in array 2 :");
    scanf("%d",&col2);

    int arr2[row2][col2];

    // Taking 1st array Element
  
    for(int i=0;i<row2;i++){
        for(int j=0;j<col2;j++){
            printf(" Element(%d,%d) is : ",i+1,j+1);
            scanf("%d",&arr2[i][j]);
        }
    }

    // array 1
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            printf("%d  ",arr1[i][j]);
        }
        printf("\n") ;
    }

 printf("\n") ;

    // array 2
    for(int i=0;i<row2;i++){
        for(int j=0;j<col2;j++){
            printf("%d  ",arr2[i][j]);
        }
        printf("\n") ;
    }
 
 printf("\n") ;

    int arr[row1][col1];
    // addition of arrays
    printf("\nAddition  \n");
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            arr[i][j] = arr1[i][j] +arr2[i][j];
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    // substracton of arrays
    printf(" \nSubstraction\n");
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            arr[i][j] = arr1[i][j] - arr2[i][j];
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }


    return 0;
}