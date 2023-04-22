#include<stdio.h>
struct Student_detail
{
	int enroll_no;
	char Name[20];
	int sem;
	int cpi;
}s[5];
void main(){
	for(int i = 0; i < 5; i++)
	{
	printf("Enter Student Enrollment no. : ");
	scanf("%d",&s[i].enroll_no);
	printf("Enter Student name : ");
	scanf("%s",&s[i].Name[0]);
	printf("Enter Semester : ");
	scanf("%d",&s[i].sem);
	printf("Enter Student CPI : ");
	scanf("%d",&s[i].cpi);
	}
	for(int i=0; i<5; i++)
	{
	printf("\n\nStudent id  : %d \n",s[i].enroll_no);
	printf("Student Name  : %s \n",s[i].Name);
	printf("Student sem  : %d \n",s[i].sem);
	printf("Student cpi  : %d \n",s[i].cpi);
	}
}