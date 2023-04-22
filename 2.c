#include<stdio.h>
int main()
{
  int n;
  printf("enter no. of elements you want to add in array : ");
  scanf("%d",&n);
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    printf("Enter the Array element at the index %d :",i+1);
    scanf("%d",&arr[i]);
  }
  for (int i = 0; i < n; i++)
  {
    if(arr[i]!=arr[i+1]){
      arr[i]=arr[i+1];
      break;
    }
  }
  for (int i = 0; i < n; i++)
  {
    printf("\nThe Array element at the index %d is %d : ",i+1,arr[i]);
  }
}