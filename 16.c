#include<stdio.h>
#include<math.h>
# define n 100
struct Stack
{
    int str[100];
    int top;
}s1,inv;
void Push(int x)
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
int Pop()
{
    if( s1.top == -1)
    {
        printf("STACK UNDERFLOW!!! ");
        return 0;
    }
    else
    {
        int x = s1.str[s1.top];
        s1.str[s1.top--] = '\0';
        // s1.top--;
        return x;
    }
}
int Digit(char x)
{
    if( x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
    {
        return 0;
    }
    else return 1;
}
int performOperation(int x2,int x1,char x)
{
    if(x =='+')
    {
        return x1 + x2;
    }
    else if (x == '-')
    {
        return x2 - x1;
    }
    else if (x == '*')
    {
        return x1 * x2;
    }
    else if (x == '/')
    {
        return x2 / x1;
    }
    else if (x == '^')
    {
        return pow(x2,x1);
    }
    else return 0;
}
void Inverse()
{

}
int Prefix_Evaluation()
{
    char s[100],inv[100];
    int i,j,y;
    i=j=y=0;
    printf("Enter Prefix Expression : ");  //getting string.
    scanf("%s",s);
    while(s[i]!='\0')           //getting Length of string in i .
    {
        i++;                    
    }
    j = i-1;
    while (j>=0){
        inv[y++] = s[j];                //reversed the string.
        printf("|%c|",inv[y-1]);        // Showing the reverse string. (Optional)!
        j--;
    }
    for(int i = 0; inv[i] !='\0'; i++)
    {
        char temp = inv[i];
        if( Digit(temp) == 1)
        {
            Push(temp - '0');
        }
        else
        {
            int value = performOperation(Pop(),Pop(),temp) ;
            Push(value);
        }
    }
    printf("\n Answer = %d \n\n",Pop() );
    return 0; //Pop();
}
void main(){
    Prefix_Evaluation();
    return ;
}