#include<stdio.h>
#include<stdlib.h>
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
void Display(struct node* ptr)
{
    printf("\n\nLINKED LIST : ");
    while (ptr != NULL)
    {
        printf("|%d|-->",ptr->info);
        ptr = ptr->link;
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
void main()
{
    struct node* first = NULL;
   int choice;
    do
    {
        printf("\n1.Insert element to Link list from end \n");
        printf("2.Delete element From End \n");
        printf("3.Display all elements of List \n");
        printf("4.Quit \n");
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
                delete_from_end(&first);
                break;
            case 3:
                Display(first);
                break;
            case 4:
                break;
            default:
            printf("Invalid choice \n");
            }
    }while(choice!=4);
}