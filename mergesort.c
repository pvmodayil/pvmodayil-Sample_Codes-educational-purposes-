//program for merge sort implementation
#include<stdio.h>
int * merge(int *,int,int*,int);
void merge_sort(int *,int);
int main()
{
	int n,i;
	//int *mer;
	printf("n=\n");
	scanf("%d",&n);
	printf("array:\n");
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	merge_sort(a,n);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
int * merge(int *f,int nf,int *l,int nl)
{
	int i=0,j=0,k=0;
	static int c[100];
	while(i<nf && j<nl)
	{
		if(f[i]<l[j])
		{
			c[k]=f[i];
			i++;
		}
		else
		{
			c[k]=l[j];
			j++;
		}
		k++;
	}
	if(i<nf)
	{
	for(;i<nf;i++)
	{
		c[k]=f[i];
		k++;
	}
	}
	else if(j<nl)
	{
		for(;j<nl;j++)
		{
			c[k]=l[j];
			k++;
		}
	}
	return c;

}
void merge_sort(int *a,int n)
{
	int *mer;
	if(n==1)
		return;
	int i;
	int f[n/2],l[n/2];
	for(i=0;i<n/2;i++)
	{
		f[i]=a[i];
		l[i]=a[n/2 + i];
	}
	merge_sort(f,n/2);
	merge_sort(l,n/2);
	mer=merge(f,n/2,l,n/2);
	for(i=0;i<n;i++)
		a[i]=mer[i];
}
