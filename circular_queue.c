//The program contains basic circular_queue data structure using array with operations like add,delete,peep,displayQueue,isQueuefull,isQueueempty

//including the header files

#include<stdio.h>
#include<stdlib.h>
//..........................

//declaring functions.......

void add(int *,int *,int *,int);
void displayQueue(int,int,int,int *);
int isQueuefull(int,int,int);
int isQueueempty(int);
void delete(int *,int *,int,int *);
int peep(int,int *);
//.........................

int main()
{
	int head=-1,tail=-1,choice,capacity;
	int queue[5]={0};
	capacity=(sizeof(queue)/sizeof(int));
	
	while(1){
		printf("Enter an option\n1.add\n2.delete\n3.peep\n4.displayQueue\n5.isQueuefull\n6.isQueueempty\n7.exit\n");
		scanf("%d",&choice);

		switch(choice){
			
			case 1:
				add(&head,&tail,queue,capacity);
				break;

			case 2:
				delete(&head,&tail,capacity,queue);
				break;

			case 3:
				printf("The head element in queue is %d\n",peep(head,queue));
				break;

			case 4:
				displayQueue(head,tail,capacity,queue);
				printf("\n");
				break;

			case 5:
				if(isQueuefull(head,tail,capacity))
					printf("Queue is full..............\n");
				else
					printf("Queue is not full.........\n");
				break;

			case 6:
				if(isQueueempty(head))
					printf("Queue is empty............\n");
				else
					printf("Queue is not empty............\n");
				break;

			case 7:
				exit(0);
				break;

			default :
				printf("Enter a valid option.............\n");
				break;

		}
	}//end of while
}//end of main

//defining add function

void add(int *h,int *t,int *q,int cap){
	if(isQueuefull(*h,*t,cap)){
		printf("The queue is full\n");
	}
	else
	{
		if(*h==-1){
			(*h)=0;
			(*t)=0;
		}
		else{ 
			if(*t==cap-1){
				*t=0;
			}	
			else{
				(*t)++;
			}
		}
		int element;
		printf("Enter the integer to be added in the queue\n");
		scanf("%d",&element);
		q[(*t)]=element;
	}
}

//end of add

//definition of isQueuefull

int isQueuefull(int h,int t,int cap){
	if((h==0 && t==cap-1) || (h==t+1))
		return 1;
	else
		return 0;
}
//end of isQueuefull

//definition of displayQueue

void displayQueue(int h,int t,int cap,int *q){
	if(isQueueempty(h)){
		printf("Queue is empty\n");
	}
	else{
	
		if(h<=t){
		for(int i=h;i<=t;i++)
			printf("<-- %d",q[i]);
		}
		else{
			int i;
			for(i=h;i<=cap-1;i++)
				printf("<-- %d",q[i]);
			for(i=0;i<=t;i++)
				printf("<--%d",q[i]);
		}
	}
}
//end of displayQueue

//definiiton of isQueueempty

int isQueueempty(int h){
	if(h==-1)
		return 1;
	else
		return 0;
}
//end of isQueueemptyy

//definition of delete

void delete(int *h,int *t,int cap,int *q){
	if(*h==-1)
		printf("Queue is empty..........\n");
	else{
		if((*h)<(*t))
		{	
			printf("%d is exiting from the queue.........\n",q[*h]);
			q[(*h)++]=0;	//post increment-increments after assigning.
		}
		else if((*h)==(*t))
		{
			printf("%d is exiting from the queue.........\n",q[*h]);
			q[*h]=0;
			printf("Queue is empty..........\n");
			*h=-1;
			*t=-1;
			printf("Add new elements now.......\n");
		}
		else if(*h==cap-1)
		{
			printf("%d is exiting from the queue.........\n",q[*h]);
			q[*h]=0;
			*h=0;
		}
	}
}

//end of delete

//definition of peep

int peep(int h,int *q){
	if(isQueueempty(h))
	{
		printf("The queue is empty...........\n");
		printf("Returned value is garbage.........\n");
	}
	else
		return q[h];
}

//end of peep

//end of program
