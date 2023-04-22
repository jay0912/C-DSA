#include<stdio.h>
int top=-1,n=30;
char arr[30];
void PUSH(char x){
	if (top == n-1){
		printf("STACK OVERFLOW!! \n");
		return;
	}
	else{
		top++;
		arr[top]= x;
	}
}
char POP(){
	if(top==-1){
		printf("STACK UNDERFLOW!!\n");
		return 0;
	}
	else{
		top--;
		return (arr[top+1]);
	}
}
void main(){
	int b=0, i=0;
	char arr1[25];

	printf("\nEnter the string : ");
	scanf("%s",arr1);

	while(arr1[i]!='\0')
	{
		if(arr1[i]=='a')
		{
			PUSH(arr1[i]);
		}
		else
		{
			b++;
		}
		i++;
	}
	while(top !=-1)
	{
		POP();
		b--;
	}
	if(b!=0)
	{
		printf("\n\tINVALID STRING\n");
	}
	else
	{
		printf("\n\tVALID STRING\n");
	}
}