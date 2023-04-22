#include<stdio.h>
struct AddFuns
{
    int a[2][2];
    for (int j = 0; j < 2; j++)
    {
        for(int k = 0; k < 2; k++)
        {
            printf("a[%d][%d] : ",j,k);
            scanf("%d",&a[j][k]);
        }
    }
    printf("\n\n");
}a1[2];
void main()
{
    for (int j = 0; j < 2; j++)
    {
        for(int k = 0; k < 2; k++)
        {
            printf("Sum [%d][%d] = %d \n",j,k,a1[0].a[j][k]+ a1[1].a[j][k]);
        }
    }
}