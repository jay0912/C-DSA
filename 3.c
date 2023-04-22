#include<stdio.h>
int main(){
    int r1,r2,c1,c2;
    printf("Enter no. of Rows and colums of first matrix : ");
    scanf("%d %d",&r1,&c1);
    int arr1[r1][c1];
    printf("Enter no. of Rows and colums of second matrix : ");
    scanf("%d %d",&r2,&c2);
    if(c1!=r2){
        printf("Matrices with entered ordered can't be multiplied. \n");
    }
    else{
        int arr2[r2][c2],mul[r1][c2],sum=0;
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                printf("Enter the Array element of first matrix at the index arr[%d][%d] : ",i+1,j+1);
                scanf("%d",&arr1[i][j]);
            }
        }
        for (int i = 0; i < r2; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                printf("Enter the Array element of second matrix at the index arr[%d][%d] : ",i+1,j+1);
                scanf("%d",&arr2[i][j]);
            }
        }
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                for (int k = 0; k < r2; k++)
                {
                   sum = sum + arr1[i][k] * arr2[k][j];
                }
                mul[i][j]=sum;
                sum=0;
            }
        }
        printf("The Array element of Multiplied matrix :\n");
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                printf("%d \t",mul[i][j]);
            }
            printf("\n");
        }
    }
 return 0;
}