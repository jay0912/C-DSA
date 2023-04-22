#include<stdio.h>
int arr[100];
int binnary_search(int srch,int n, int m)
{
    while(m >= 0)
    {
        if(arr[(m-n)/2]>srch)
        {
            return binnary_search(srch,n/2,m);
        }
        else if(arr[m-n]/2<srch)
        {
            return binnary_search(srch,n,m/2);
        }
        else if(arr[(m-n)/2] == srch)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int N,i,search;
    printf("enter the size of array : ");
    scanf("%d",&N);
    for(i = 0 ; i < N ; i++)
    {
        printf("\nEnter the elements [%d] :",i);
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the elements want to search in array : ");
    scanf("%d",&search);    
        int temp;
        for (int j = 0; j < N-1; j++)
        {
            i=0;
        while(arr[j]>arr[i+1] && i<N)
            {
            temp =arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
            i++;
            }
        }
        
    if(binnary_search(search,0,N)==1)
    printf("\nElement founded at index\n");
    printf("\nElement Not Found!!\n");
    return 0;
}