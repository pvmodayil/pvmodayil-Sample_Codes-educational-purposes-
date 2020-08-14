// Program contains array approach for basic stack operations like push,pop,peep,displaystack,isstackfull,isstackempty................

//including required libraries

//start of program............

#include<stdio.h>
#include<stdlib.h>

//declaring required functions

void push(int *,int *,int,int);
int isStackfull(int,int);
int isStackempty(int);
int  pop(int *,int *);
int peep(int,int *);
void displaystack(int *,int);

//.............................

int main()
{
	int top=-1;	//initializing the top variable
	int capacity;
	int stack[10]={0};
	capacity=sizeof(stack)/sizeof(int);
	int element;
	printf("stack capacity is %d elements.........\n",capacity);
	while(1)
	{
		int choice;
		printf("Enter any of the options...........\n1.push\n2.pop\n3.peep\n4.displaystack\n5.isStackfull\n6.isStackempty\n7.exit\n");
		scanf("%d",&choice);

		switch(choice)	//switch case begins
		{
			case 1:
				printf("Enter the integer number to be entered\n");
				scanf("%d",&element);
				push(&top,stack,capacity,element);
				break;

			case 2:
				printf("element popped from stack is %d \n",pop(&top,stack));
				break;

			case 3:
				printf("top element in stack is %d \n",peep(top,stack));
				break;

			case 4:
				displaystack(stack,capacity);
				break;

			case 5:
				if(isStackfull(top,capacity))
					printf("Stack is full............\n");
				else
					printf("Stack is not full.........\n");
				break;

			case 6:
				if(isStackempty(top))
					printf("Stack is empty............\n");
				else
					printf("Stack is not empty.........\n");
				break;

			case 7:
				exit(0);
				break;

			default:
				printf("Enter a valid option............\n");
				break;

		}//end of switch
	}//end of while
}//end of main

//definition of push function

void push(int *t,int *st,int cap,int ele){
	if(isStackfull(*t,cap))
	{
		printf("Stack is full cannot add new element..........\n");
	}
	else
	{
		(*t)++;		//increment the top
		st[(*t)]=ele;
	}
}
//end of push function

//definition of isStackfull

int isStackfull(int t,int cap){
	if(t==cap-1)
		return 1;
	else
		return 0;
}
//end of isStackfull

//definition of displaystack

void displaystack(int *st,int cap){
	for(int i=cap-1;i>=0;i--)
		printf("|%d|\n",st[i]);
}
//end of display stack

//definition of pop function

int pop(int *t,int *st){
	if(isStackempty(*t))
	{
		printf("Stack is empty........\nReturned value is garbage.........\n");
	}
	else
	{
		int temp=st[(*t)];
		st[(*t)]=0;
		(*t)--;
		return temp;
	}
}

//end of pop

//definition of isStackempty function

int isStackempty(int t){
	if(t==-1)
		return 1;
	else
		return 0;
}
//end of isStackempty

//

int peep(int t,int *st){
	if(isStackempty(t))
	{
		printf("Stack is empty..........\nReturned value is garbage..........\n");
	}
	else
		return st[t];
}

//
//end of program...............
