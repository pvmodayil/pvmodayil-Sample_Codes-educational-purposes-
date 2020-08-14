#include<stdio.h>
#include<stdlib.h>
void linear_search_iteration(int *,int,int);
void linear_search_recursion(int *,int,int);
void binary_search_iteration(int *,int,int,int,int);
void binary_search_recursion(int *,int,int,int,int);
void bubble_sort(int *,int);
void selection_sort(int *,int);
void insertion_sort(int *,int);
void merge_sort(int *,int,int);
void  merge(int *,int,int,int);
void partition(int *,int,int);
void quick_sort(int *,int,int);
void heap_sort(int *,int);
void heapify(int *,int,int);
int main()
{
	int n,choice,first,last,middle,search,i,low,high;
	char c='y';
	while(c=='y')
	{
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the array elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	while(1)
	{
	printf("Enter choice\n1.Search for element(linear search)\n2.Search for element(binary search)\n3.Bubble Sort\n4.Selection Sort\n5.Insertion Sort\n6.Merge Sort\n7.Quick Sort\n8.Heap Sort\n9.Display\n10.With another array\n11.Exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("Enter the element to be searched\n");
			scanf("%d",&search);
			//linear_search_iteration(a,n,search);
			linear_search_recursion(a,n,search);
			break;	
		case 2:
			first=0; last=n-1;
			middle=(first+last)/2;
			printf("Enter the element to be searched\n");
			scanf("%d",&search);
			bubble_sort(a,n);
        		printf("Array sorted in ascending order\n");
			//binary_search_iteration(a,search,first,last,middle);
			binary_search_recursion(a,search,first,last,middle);
			break;
		case 3:
			bubble_sort(a,n);
			break;
		case 4:
			selection_sort(a,n);
			break;
		case 5:
			insertion_sort(a,n);
			break;
		case 6:
			merge_sort(a,0,n-1);
			break;
		case 7:
			low = 0,high=n-1;
			quick_sort(a,low,high);
			break;
		case 8:
			heap_sort(a,n);
			break;
		case 9:
			for(i=0;i<n;i++)
				printf("%d ",a[i]);
			printf("\n");
			break;
		case 11:
			exit(0);
			break;
	}//end of switch
	if(choice==10)
		break;
	}//end of while
	printf("Continue(y/n)\n");
	scanf(" %c",&c);
	}//end of main while
}
//end of main

//linear search iteration
void linear_search_iteration(int *a,int n,int s)
{
	int f=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==s){
			printf("%d found at pos %d\n",s,i+1);
			f=1;
		}
	}
	if(f==0)
		printf("Element not found\n");
}
//end of linear search iteration

//linear search recursion
void linear_search_recursion(int *a,int n,int s)
{
	static int f=0;
	if(n!=0)
	{
	if(a[n-1]==s)
	{
		f=1;
		printf("%d found at pos %d\n",s,n);
	}
	linear_search_recursion(a,n-1,s);
	}
	else{
	if(f==0)
		printf("Element not found\n");
	}
}
//end of linear search

//binary search iterations
void binary_search_iteration(int *a,int s,int f,int l,int m)
{
	while(f<=l)
	{
		if(a[m]==s)
		{
			printf("Element found at pos %d\n",m+1);
			break;
		}
		else if(a[m]<s)
			f=m+1;
		else
			l=m-1;
		m=(f+l)/2;
	}
	if(f>l)
		printf("Element not found\n");
}
//end of binary search iterations

//binary search recursion
void binary_search_recursion(int *a,int s,int f,int l,int m)
{
		if(f<=l)
		{
			if(a[m]==s)
			{
				printf("Element found at pos %d\n",m+1);
				return;
			}
			else if(a[m]<s)
				f=m+1;
			else
				l=m-1;
			m=f + (l - f) / 2;
			binary_search_recursion(a,s,f,l,m);
		}	
		else
		{
			printf("Element not found\n");
		}
}
//end of binary search recursion

//bubble sort section
void bubble_sort(int *a,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(a[j]<a[i])
			{
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
}
//end of bubble sort section

//selection sort section
void selection_sort(int *a,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		int m=i;
		for(j=i+1;j<n;j++)
		{
			if(a[m]>a[j])
				m=j;

		}
		int t=a[m];
		a[m]=a[i];
		a[i]=t;
	}
}
//end of selection sort section

//insertion sort section
void insertion_sort(int *a,int n)
{	int i,j,t,temp;
	for(i=1;i<n;i++)
	{
		j=i-1;
		temp=a[i];
		while((j>=0) && (a[j]>temp))
		{
			a[j+1]=a[j];
			j--;	
		}
		a[j+1]=temp;
	}
}
//end of insertion sort section

//quick_sort section
void quick_sort(int *a,int l,int h)
{
	//pivot point is set as the lowest of the array section being considered
	if(l<h && h>=0)
	{
		partition(a,l,h);
	}
}
void partition(int *a,int p,int h)
{	
	int i=p,j=h,t;
	while(i<j)
	{	
		while(a[i]<a[p] && i<=h)
			i++;	
		while(a[j]>a[p] && j>p)
			j--;
		if(i<j)
		{
		t=a[i];
		a[i]=a[j];
		a[j]=t;
		}
	}
	if(i>=j)
	{
	t=a[p];
	a[p]=a[j];
	a[j]=t;
	quick_sort(a,p,j-1);
	quick_sort(a,j+1,h);
	}
	
}
//end of quick_sort section

//heap sort section
void heapify(int *a, int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && a[l] > a[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && a[r] > a[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        //swap a[i]  a[largest]
	int temp=a[i];
	a[i]=a[largest];
	a[largest]=temp;
  
        // Recursively heapify the affected sub-tree 
        heapify(a, n, largest); 
    } 
} 
   
void heap_sort(int *a, int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(a, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>0; i--) 
    { 
        // Move current root to end 
        int temp=a[0];
	a[0]=a[i];
 	a[i]=temp;	
  
        // call max heapify on the reduced heap 
        heapify(a, i, 0); 
    } 
} 
//end of heap sort section

//merge_sort section
void merge(int *a, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int *a, int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);

        merge(a, l, m, r);
    }
}
//end of merge_sort section

//end of program
