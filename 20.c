#include<stdio.h>
struct node
{
    int info;
    struct node* link;
};
void insert(struct node**first_ref, int x)
{
    struct node* new = (struct node*) malloc(sizeof(struct node));
    new->info = x;
    new->link = (*first_ref);
    (*first_ref) = new; 
}
void  insend(struct node**first_ref,int x)
{
    struct node* new = (struct node*) malloc(sizeof(struct node));
    new->info = x;
    new->link = NULL;
    if (*first_ref == NULL)
    {
        *first_ref = new;
        return;
    }
    struct node* save = *first_ref;
    while (save->link != NULL)
    {
        save = save->link;
    }
    save->link = new;
    return;
}
void insord(struct node** first_ref,int x)
{
    struct node* new = (struct node*) malloc(sizeof(struct node));    
    new->info = x;
    if (*first_ref == NULL)
    {
        new->link = NULL;
        *first_ref = new;
        return;
    }
    if(new->info <= (*first_ref)->info)
    {
        new->link = *first_ref;
        *first_ref = new;
        return;
    }
    struct node* save = *first_ref;
    while (save->link != NULL && new->info >= save->link->info)
    {
        save = save->link;
    }
    new->link = save->link;
    save->link = new;
    return;
}
void delete(struct node** first_ref,int y) // here y will be the position of node which user want to delete.
{ 
    if (*first_ref == NULL)
	return;
    int i = 0;
    struct node* save = *first_ref;
    if(y == 0)
    {
        *first_ref = save->link;
        free(save);
        return;
    } 
    for(i=0; i < y-1 && save != NULL;i++)
    {
        save = save->link;
    }
    if ( save == NULL || save->link == NULL)
    {
        printf(" \nNode not found!!\n\n");
        return;
    }
    struct node*nodes = save->link->link; ///  get the link from the (deleting(y))node of the next node and attach to link part of save i.e attach to previous node
    free(save->link);
    save->link = nodes;
    return ;   
}
void delete_from_front(struct node** first_ref)
{
    if(*first_ref == NULL)
    {
        printf("\n\nList Empty!!\n\n");
        return;
    }
    else
    {
        struct node* temp = *first_ref;
        *first_ref = temp->link;
        free(temp);
    }
}
void delete_from_end(struct node** first_ref)
{
    if(*first_ref == NULL)
    {
        printf("\n\nList Empty!!\n\n");
        return;
    }
    
        struct node* save = *first_ref,*pred=NULL;
        while (save->link != NULL)
        {
            pred = save;
            save = save->link;
        }
            pred->link = NULL;
            free(save);
    
}
void display(struct node* ptr)
{
    printf("\n\nLINKED LIST : ");
    while (ptr != NULL)
    {
        printf("|%d|-->",ptr->info);
        ptr = ptr->link;
    }
}
void main()
{
    struct node* first = NULL;
    int choice;
    do
    {
        printf("\n1.Insert element to Link list from Front \n");
        printf("2.Insert element to Link list from End \n");
        printf("3.Insert element to Link list in Order \n");
        printf("4.Delete element at paticular position \n");
        printf("5.Delete element From Front \n");
        printf("6.Delete element From End \n");
        printf("7.Display all elements of List \n");
        printf("8.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            int x;
            case 1:
                printf("\nEnter Data : ");
                scanf("%d",&x);
                insert(&first,x);
            break;
            case 2:
                printf("\nEnter Data : ");
                scanf("%d",&x);
                insend(&first,x);
            break;
            case 3:
                printf("\nEnter Data : ");
                scanf("%d",&x);
                insord(&first,x);
                break;
            case 4:
                printf("\nEnter Element position : ");
                scanf("%d",&x);
                delete(&first,x);
                break;
            case 5:
                delete_from_front(&first);
                break;
            case 6:
                delete_from_end(&first);
                break;
            case 7:
                display(first);
                break;
            case 8:
                break;
            default:
            printf("Invalid choice \n");
            }
    }while(choice!=8);
}