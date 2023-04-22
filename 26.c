#include<stdio.h>
int main()
{
int N;
printf("enter the size of array : ");
scanf("%d",&N);
int arr[N],i,search;
for(i = 0 ; i < N ; i++)
{
    printf("\nEnter the elements [%d] :",i);
    scanf("%d",&arr[i]);
}
    printf("\nEnter the elements want to search in array : ");
    scanf("%d",&search);
for(i = 0 ; i < N ; i++)
{    
if (arr[i]==search)
{
    printf("\nElement founded at index %d\n",i);
    return 0;
}
}
printf("\nElement Not Found!!\n");
}