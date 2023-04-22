#include<stdio.h>
void swap(int a, int b);
void main(){
	int a,b;
	printf("Enter value of a : ");
	scanf("%d",&a);
	printf("Enter value of b : ");
	scanf("%d",&b);
	printf("Before swapping a = %d and b = %d \n",a,b);
	swap(a,b);
}
void swap(int a,int b){
	int c = a;
	a = b;
	b = c;
	printf("After swapping a = %d and b = %d .\n",a,b);
}