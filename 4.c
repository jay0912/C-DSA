#include<stdio.h>
struct Add
{
    int a[2][2];
    // int b[2][2];
}a1[2];
void AddFun()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for(int k = 0; k < 2; k++)
            {
                printf("a%d [%d][%d] : ",i+1,j,k);
                scanf("%d",&a1[i].a[j][k]);
            }
        }
        printf("\n");       
    }
    printf("\n\n");
    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         for(int k = 0; k < 2; k++)
    //         {
    //             printf("a%d [%d][%d] = %d \n",i+1,j,k,a1[i].a[j][k] + a1[i].a[j][k]);
    //         }
    //     }
    //     printf("\n");       
    // }
};

int main()
{
    AddFun();
    for (int j = 0; j < 2; j++)
        {
            for(int k = 0; k < 2; k++)
            {
                printf("Sum [%d][%d] = %d \n",j,k,a1[0].a[j][k] + a1[1].a[j][k]);
            }
        }
    return 0;
}