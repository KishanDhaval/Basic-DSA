#include<stdio.h>
#include<stdlib.h>

int main()
{
  
    int row,col;

    printf("How many row");
    scanf("%d",&row);
    printf("How many col");
    scanf("%d",&col);

    int arr[row][col];
    
    // Taking array Element
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf(" Element(%d,%d) is : ",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }

    // Printing Array Element
    printf("matrix is \n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d  ",arr[i][j]);
        }
        printf("\n") ;
    }
     

    return 0;
}