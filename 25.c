#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};
void insert(struct node**L,struct node**R,int y,int x)
{
    struct node* new = (struct node*) malloc(sizeof(struct node));
    new->info = x;
    if(*R == NULL)
    {
        new->lptr = new->rptr = NULL;           // it works!! but not good way to write like this.
        *L = *R = new;
        return;
    }
    struct node* M = *L;
     for(int i=0; i <= y-1 && M != NULL;i++)
    {
        M = M->rptr;
    }
    if (y==0)
    {
        new->lptr = NULL;
        new->rptr = M;
        M->lptr = new;
        *L = new;
        return;
    }
    new->lptr = M->lptr;
    new->rptr = M;
    (M->lptr)->rptr = new;
    M->lptr = new;
}
void insend(struct node**L,struct node**R,int x)
{
    struct node* new = (struct node*) malloc(sizeof(struct node));
    new->info = x;
    new->rptr = NULL;
    if(*R == NULL)
    {
        new->lptr = new->rptr = NULL;           // it works!! but not good way to write like this.
        *L = *R = new;
        return;
    }
    (*R)->rptr = new;
    new->lptr = *R;
    *R = new;
}
void delete(struct node** L,struct node** R,int y) // here y will be the position of node which user want to delete.
{ 
    if(*R == NULL)
    {
        printf("UNderfllow!!");
        return;
    }
    struct node* old = *L;
    for (int i = 0; i < y; i++)
    {
        old = old->rptr;
    }
    if (*L == *R)
    {
        *L = *R = NULL;
    }
    else if(old == *L)
    {
        *L = (*L)->rptr;
        (*L)->lptr = NULL;
    }
    else if(old == *R)
    {
        *R = (*R)->lptr;
        (*R)->rptr = NULL;
    }
    else
    {
        (old->lptr)->rptr = old->rptr;
        (old->rptr)->lptr = old->lptr;
    }
    free(old);
}
void display(struct node*L,struct node*R)
{
       printf("\n\nLINKED LIST : ");
    while (L != R)
    {
        printf("|%d|-->",L->info);
        L = L->rptr;
    }
    printf("|%d|-->",L->info);
}    
void main()
{
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
                insert(&first,&last,0,x);
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