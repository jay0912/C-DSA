#include<stdio.h>
struct employee_detail
{
	int employee_id;
	char Name[20];
	char Designation[20];
	int salary;
}s1;
void main(){
	printf("Enter employee id : ");
	scanf("%d",&s1.employee_id);
	printf("Enter employee name : ");
	scanf("%s",&s1.Name[0]);
	printf("Enter employee Designation : ");
	scanf("%s",&s1.Designation[0]);
	printf("Enter employee salary : ");
	scanf("%d",&s1.salary);
	printf("\n\nemployee id  : %d \n",s1.employee_id);
	printf("employee Name  : %s \n",s1.Name);
	printf("employee Designation  : %s \n",s1.Designation);
	printf("employee salary  : %d \n",s1.salary);
}