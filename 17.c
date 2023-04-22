#include <stdio.h>
#include<stdlib.h>
#define MAX 50
void insert();
void delete();
void display();
int queue_ar[MAX],front = - 1,rear = - 1;
int main()
{
    int choice;
 do
    {
        printf("\n1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(1);
            default:
            printf("Invalid choice \n");
        }
    }while(choice!=4);
}
void insert()
{
    int item;
    if(rear == MAX - 1)
    printf("\nQueue Overflow \n");
    else
    {
        if(front== - 1)
        front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &item);
        rear++;
        queue_ar[rear] = item;
    }
}
void delete()
{
    if(front == - 1 )
    {
        printf("\nQueue Underflow \n");
        return;
    }
    else
    {
        printf("\nElement deleted from queue is : %d\n\n", queue_ar[front]);
        if(front == rear)
        {
            front=rear=0;
        }
        else
        front = front + 1;
    }
}
void display()
{
    int i;
    if(front == - 1)
    printf("Queue is empty \n");
    else
    {
        printf("\nQueue is :");
        for(i = front; i <= rear; i++)
        printf(" |%d| ", queue_ar[i]);       
    }
    printf("\n");
}