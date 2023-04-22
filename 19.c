#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link ;
}*n1;
void main()
{    
    n1 = (struct node *)malloc(sizeof(struct node *));
    printf("\nEnter the data of Node : ");
    scanf("%d",&n1->info);
    printf("Befor --> |%d|%d|",n1->info,n1->link);
    n1 = (struct node *)realloc(n1,0);              //(free/delete) the node.
    printf("After -- > |%d|%d|",n1->info,n1->link); //nothing will print as there is no such node in storage now. 
    return;
}
