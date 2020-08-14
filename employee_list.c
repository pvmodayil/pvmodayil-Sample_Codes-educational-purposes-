#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee_details
{
	int empid;
	char empname[20];
	int salary;
	int joining_year;
	struct employee_details *next;
};

void insert(struct employee_details **,int,char *,int,int);
void display(struct employee_details *);
int total_salary(struct employee_details *);
float average_salary(struct employee_details *);
int min_salary(struct employee_details *);
int max_salary(struct employee_details *);
int main()
{
	struct employee_details *head=NULL;
	int choice;
	while(1)
	{
		printf("Enter your option\n1.Insert data\n2.Find total salary\n3.Find average of salaries\n4.Find minimum of all salaries\n5.Find maximum of all salaries\n6.Display\n7.Exit\n");
		scanf("%d",&choice);

		if(choice==1)
		{
		int empid;
		char empname[20];
		int salary,joining_year;
		printf("Enter the employee id\n");
		scanf("%d",&empid);
		printf("Enter the employee name\n");
		scanf("%s",empname);
		printf("Enter the salary\n");
		scanf("%d",&salary);
		printf("Enter the joining year\n");
		scanf("%d",&joining_year);
		insert(&head,empid,empname,salary,joining_year);
		}
		else if(choice==2)
		{
		printf("The total salary = %d\n",total_salary(head));
		}
		else if(choice==3)
		{
		printf("The average of the salaries = %f\n",average_salary(head));
		}
		else if(choice==4)
		{
		printf("minimum = %d\n",min_salary(head));
		}
		else if(choice==5)
		{
		printf("maximum = %d\n",max_salary(head));
		}
		else if(choice==6)
		{
		display(head);
		}
		else if(choice==7)
		{
			exit(0);
		}
	}
}
void insert(struct employee_details **h,int id,char *name,int sal,int year)
{	
	struct employee_details *t;
	t=*h;
	struct employee_details *temp;
	temp=(struct employee_details *)malloc(sizeof(struct employee_details));
	temp->empid=id;
	strcpy(temp->empname,name);
	temp->salary=sal;
	temp->joining_year=year;
	temp->next=NULL;
	if(*h==NULL)
	{
		*h=temp;
	}
	else
	{
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=temp;
	}
}
void display(struct employee_details *h)
{
	struct employee_details *t=h;
	if(h==NULL)
	{
		printf("List is empty\n");
		exit(0);
	}
	while(t->next!=NULL)
	{
		printf("-->\n");
		printf("%d\n",t->empid);
		printf("%s\n",t->empname);
		printf("%d\n",t->salary);
		printf("%d\n",t->joining_year);
		t=t->next;
	}
		printf("-->\n");
		printf("%d\n",t->empid);
		printf("%s\n",t->empname);
		printf("%d\n",t->salary);
		printf("%d\n",t->joining_year);
}

int total_salary(struct employee_details *h)
{
	int sum=0;
	struct employee_details *t=h;
	if(h==NULL)
	{
		printf("List is empty\n");
		exit(0);
	}
	while(t->next!=NULL)
	{
		sum+=t->salary;
		t=t->next;
			
	}
	sum+=t->salary;
	return sum;
}
float average_salary(struct employee_details *h)
{
	int sum=0,count=0;
	struct employee_details *t=h;
	if(h==NULL)
	{
		printf("List is empty\n");
		exit(0);
	}
	while(t->next!=NULL)
	{
		sum+=t->salary;
		count++;
		t=t->next;
	}
	sum+=t->salary;
	count++;
	return sum/count;
}
int min_salary(struct employee_details *h)
{
	struct employee_details *t=h;
	if(h==NULL)
	{
		printf("List is empty\n");
		exit(0);
	}
	int min=h->salary;
	while(t->next!=NULL)
	{
		t=t->next;
		if(t->salary<min)
			min=t->salary;
	}
	return min;
}
int max_salary(struct employee_details *h)
{
	struct employee_details *t=h;
	if(h==NULL)
	{
		printf("List is empty\n");
		exit(0);
	}
	int max=t->salary;
	while(t->next!=NULL)
	{
		t=t->next;
		if(t->salary>max)
			max=t->salary;
	}
	return max;
}
