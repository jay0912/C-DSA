#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
void insert(struct node**first_ref,struct node**last_ref,int x)
{
    struct node* new = (struct node*) malloc(sizeof(struct node));
    new->info = x;
    if(*first_ref == NULL)
    {
    new->link = new;
    *first_ref = new;
    *last_ref = new;
    return;
    }
    new->link = (*first_ref);
    (*(last_ref))->link = new;
    (*first_ref) = new;
}
void delete(struct node** first_ref,struct node**last_ref,int y) // here y will be the address of node which user want to delete.
{ 
    if (*first_ref == NULL)
	return;
    int i = 1;
    struct node* save = *first_ref;
    if(y == 1)
    {
        *first_ref = save->link;
        (*last_ref)->link = *first_ref;
        free(save);
        return;
    } 
    for(i=1; i < y-1 && save != *last_ref ;i++)
    {
       save = save->link;
    }
    if ( save == *last_ref)
    {
        printf(" \nNode not found!!\n\n");
        return;
    }
    struct node*nodes = save->link->link; ///  get the link from the (deleting(y))node of the next node and attach to link part of save i.e attach to previous node
    free(save->link);
    save->link = nodes;
    return ;   
}
void  insend(struct node**first_ref,struct node**last_ref,int x)
{
    struct node* new = (struct node*) malloc(sizeof(struct node));
    new->info = x;
    if (*first_ref == NULL)
    {
        new->link = new;
        *first_ref = new;
        *last_ref = new;
        return;
    }
    else
    {
    new->link = (*first_ref);
    (*last_ref)->link = new;
    *last_ref = new;
    }
    return;
}
void display(struct node* f,struct node*l)
{
    printf("\n\nLINKED LIST : ");
    while (f != l)
    {
        printf("|%d|-->",f->info);
        f = f->link;
    }
    printf("|%d|-->",f->info);
}
void main(){
    struct node* first = NULL;
    struct node* last = NULL;
    int choice;
    do
    {
        printf("\n1.Insert element to Link list from Front \n");
        printf("2.Insert element to Link list from End \n");
        printf("3.Delete element at paticular position \n");
        printf("4.Display all elements of List \n");
        printf("5.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            int x;
            case 1:
                printf("\nEnter Data : ");
                scanf("%d",&x);
                insert(&first,&last,x);
            break;
            case 2:
                printf("\nEnter Data : ");
                scanf("%d",&x);
                insend(&first,&last,x);
            break;
            case 3:
                printf("\nEnter Element position : ");
                scanf("%d",&x);
                delete(&first,&last,x);
            break;
            case 4:
                display(first,last);
                break;
            case 5:
                break;
            default:
            printf("Invalid choice \n");
            }
    }while(choice!=5);
}