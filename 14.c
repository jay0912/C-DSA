#include<stdio.h>
struct Stack
{
    char str[100];
    int top;
}s1,Next,polish;
# define n 100
void Push(char x)
{
    if( s1.top==n-1 )
    {
        printf("STACK OVERFLOW!!! \n");
        return;
    }
    else
    {
        s1.top++;
        s1.str[s1.top] = x;
    }
}
char Pop()
{
    if( s1.top == -1)
    {
        printf("STACK UNDERFLOW!!! ");
        return 0;
    }
    else
    {
        s1.top--;
        return s1.str[s1.top+1];
    }
}
int G(char x)
{
    if( x == '+' || x == '-' )
    {
        return 2;
    }
    else if( x == '*' || x == '/' )
    {
        return 4;
    }
    else if( x == '^')
    {
        return 5;
    }
    else if ( x == '(')
    {
        return 0;
    }
    else
    {
        return 8;
    }
}
int F(char x)
{
    if( x == '+' || x == '-' )
    {
        return 1;
    }
    else if( x == '*' || x == '/' )
    {
        return 3;
    }
    else if( x == '^')
    {
        return 6;
    }
    else if ( x == '(')
    {
        return 9;
    }
    else if ( x == ')')
    {
        return 0;
    }
    else
    {
        return 7;
    }
}
int Rank(char x)
{
    if ( x == '+' || x == '-' || x == '*' || x =='/' || x == '^')
    {
        return -1;
    }
    else if( x == '(' || x == ')' )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
char NextString()
{
    Next.top++;   
    return Next.str[Next.top];
}
void Display()
{
    polish.top=0;
    printf("\n\tPostfix : %c ",polish.str[polish.top]);
    while(polish.str[polish.top] !='\0')
    {
    polish.top++;
    printf("%c ",polish.str[polish.top]);
    }
}
void REVPOL()
{
    int rank = 0;
    char next;
    s1.top = -1; Next.top = -1; polish.top=0;
    Push('(');
    next = NextString();
    while( next != '\0')
    {
        if (s1.top < 0)
        {
            printf("Invalid Expression!!!");
            return;
        }
        while( G(s1.str[s1.top]) > F(next) )
        {
            char temp;
            temp = Pop();
            polish.str[polish.top++] = temp;
            rank += Rank(temp);
            if(rank<1)
            {
                printf("\nINVALID\n");
                return;
            }
        }
        if (G(s1.str[s1.top]) != F(next))
        {
            Push(next);
        }
        else
        {
            Pop();
        }
        next = NextString();
    }
    if ( s1.top != -1 || rank != 1)
    {
        printf(" \n Invalid Expression!! \n");
    }
    else
    {
        printf("\n\tVALID Expression!!\n");
        Display();
    }
}
void main()
{
    printf("\nEnter the Infix Expression : ");
    scanf("%s",Next.str);
    REVPOL();
    printf("\n\n\n");
}   