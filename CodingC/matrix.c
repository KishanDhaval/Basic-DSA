#include<stdio.h>

int main()
{   int i;
    int a,b,c,d;
    int  n[4][4],m[4][4],p[4][4];

    printf("give number of row of A");
    scanf("%d",&a);
    printf("give number of columns of A");
    scanf("%d",&b);
    printf("give number of row of B");
    scanf("%d",&c);
    printf("give number of columns of B");
    scanf("%d",&d);

    if(a!=c&&b!=d)
    {
        printf("give valid matrix size");
        return 0;
    }

    printf("enter matrix A row wise :");
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++) {
            printf("enter n[%d][%d]",i+1,j+1);
            scanf("%d",&n[i][j]);
        }
    }
    printf("enter matrix B row wise :");
    for(int i=0; i<c; i++)
    {
        for(int j=0; j<d; j++) {
            printf("enter n[%d][%d]",i+1,j+1);
            scanf("%d",&m[i][j]);
        }
    }

printf("matrix A\n");
for(int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++) {
            printf("%d ", n[i][j]);
            
        }printf("\n");
    }
    printf("matrix B\n");
    for(int i=0; i<c; i++)
    {
        for(int j=0; j<d; j++) {
            printf("%d",m[i][j]);
            
        } printf("\n");
    }


for(int i=0; i<c; i++)
    {
        for(int j=0; j<d; j++) {
        p[i][j]=n[i][j]+m[i][j];
            printf("%d",p[i][j]);
            
        } printf("\n");
    }









    return 0;
}


