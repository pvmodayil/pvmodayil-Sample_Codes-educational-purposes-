//Array traversal,insertion,search,print,etc
#include<stdio.h>
#include<stdlib.h>
void insert_at_index(int *,int,int);
void display(int *,int);
void delete_at_index(int *,int);
int min_value(int *,int);
int max_value(int *,int);
void reverse_display(int *,int);
void search_element(int *,int,int);
int element_count(int *,int);
float average_elements(int *,int);
void duplicate_find(int *,int);
void reverse_array(int *,int);
int main(){
	int choice,size,index,val;
	printf("Enter the size of array\n");
	scanf("%d",&size);
	int arr[size];
	for(int i=0;i<size;i++)
		arr[i]=0;
	while(1)
	{
	printf("Enter an option\n1.Insert element at index\n2.Delete element at index\n3.Find min value\n4.Find max value\n5.Display\n6.Reverse display\n7.Search for element\n8.Element count\n9.Average of elements\n10.Determine presence of duplpicates\n11.Reverse array\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("Enter the value to be inserted\n");
			scanf("%d",&val);
			printf("Enter the index position\n");
			scanf("%d",&index);
			insert_at_index(arr,val,index);
			break;
		case 2:
			printf("Enter the index position\n");
			scanf("%d",&index);
			delete_at_index(arr,index);
			break;
		case 3:
			printf("Minimum value is : %d\n",min_value(arr,size));
			break;
		case 4:
			printf("Maximum value is : %d\n",max_value(arr,size));
			break;
		case 5:
			display(arr,size);
			break;
		case 6:
			reverse_display(arr,size);
			break;
		case 7:
			printf("Enter the element to be searched for\n");
			scanf("%d",&val);
			search_element(arr,size,val);
			break;
		case 8:
			printf("Number of elements in the array is :%d\n",element_count(arr,size));
			break;
		case 9:
			printf("Avaerage of the elements is :%f\n",average_elements(arr,size));
			break;
		case 10:
			duplicate_find(arr,size);
			break;
		case 11:
			reverse_array(arr,size);
			break;
	}
	}	
}
void insert_at_index(int *a,int v, int i)
{	char yn;
	if(a[i-1]!=0)
	{
		printf("An element already exist at this position\n");
		printf("Do you wish to overwrite (y/n)\n");
		scanf(" %c",&yn);
		if(yn=='y'){
			//will automatically exit from if loop and execute next instructions in the function
		}
		else if(yn=='n')
			exit(0);
	}
	a[i-1]=v; //storing value at the index position
}
void display(int *a,int n)
{
	for(int i=0;i<n;i++)
		printf("%d->%d ",i+1,a[i]);
	printf("\n");
}
void delete_at_index(int *a,int i)
{
	a[i-1]=0;
}
int min_value(int *a,int n)
{
	int min=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]<min)
			min=a[i];
	}
	return min;
}
int max_value(int *a,int n)
{
	int max=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	return max;
}
void reverse_display(int *a,int n)
{
	for(int i=n-1;i>=0;i--)
		printf("%d->%d ",i+1,a[i]);
}
void search_element(int *a,int n,int v)
{	
	int f=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==v)
		{
			f=1;
			printf("Element found at position %d\n",i+1);
		}
	}
	if(f==0)
		printf("Element not found in the array\n");
}
int element_count(int *a,int n)
{
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=0)
			count++;
	}
	return count;
}
float average_elements(int *a,int n)
{
	int sum=0,count=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=0)
		{
			sum+=a[i];
			count++;
	
		}
	}
	return (sum/count);
}
void duplicate_find(int *a,int n)
{
	int f=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i]==a[j])
				printf("Duplicate of %d found at %d\n",a[i],j+1);
		}

	}
}
void reverse_array(int *a,int n)
{
	int t;
	for(int i=0;i<n/2;i++)
	{
		t=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=t;
	}
}
