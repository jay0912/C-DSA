#include<stdio.h>
int flag=1;
int fact(int n){
    flag = flag * n;
    n--;
    if(n>0)
    fact(n);
    return flag;
}
void main(){
    int m;
    printf("Enter the no. You want to find Factorial : ");
    scanf("%d",&m);
    printf("Factorial of %d is %d",m,fact(m));
}