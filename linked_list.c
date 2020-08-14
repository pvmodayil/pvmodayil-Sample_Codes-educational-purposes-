/* The program contains a single linked list creation and manipulation with the functions InsertAtEnd, InsertAtBeg, InsertAtPos, Display, ListNodeCount, DeleteFromEnd, DeleteFromBeg,
   DeleteFromPos, ReverseDisplay, ReverseList*/

#include<stdio.h>	//Basic header file
#include<stdlib.h>	//Header file for malloc function

//Defining the structure (must be defined before the functions that is used to manipulate the same)...........

struct node{
	int data;		//data in the structure
	struct node *next;	//structure pointer that will point to the next
};

//Declaring the functions...................

void InsertAtEnd(struct node **,int);
void InsertAtBeg(struct node **,int);
void InsertAtPos(struct node **,int,int);
void Display(struct node *);
int ListNodeCount(struct node *);
void DeleteFromEnd(struct node **);
void DeleteFromBeg(struct node **);
void DeleteFromPos(struct node **,int);
void ReverseDisplay(struct node *);
void ReverseList(struct node **,struct node **);	//Sending the head pointer twice as one is needed to set the final node as the head pointer
//Main function.............................

int main()
{
	struct node *head=NULL;	//initializing the first structure pointer that points to the index of the linked list as NULL 
	int choice;		//choice for the function options
	
	while(1){
		printf("Enter your choice from the followig options:\n1.InsertAtEnd\n2.InsertAtBeg\n3.InsertAtPos\n4.Display\n5.listNodeCount\n6.DeleteFromEnd\n7.DeleteFromBeg\n8.DeleteFromPos\n9.ReverseDisplay\n10.ReverseList\n11.Exit\n");
		scanf("%d",&choice);
		int data;	//cannot declare variables within switch
		int pos;
		//switch case option selection

		switch(choice)
		{
			case 1:	printf("Enter an integer number\n");
				scanf("%d",&data);
				InsertAtEnd(&head,data);
				break;
			
			case 2: printf("Enter an integer number\n");
				scanf("%d",&data);
				InsertAtBeg(&head,data);
				break;

			case 3:printf("Enter an integer number\n");
			       scanf("%d",&data);
			       printf("Enter the position at which list should be inserted\n");
			       scanf("%d",&pos);
			       InsertAtPos(&head,data,pos);
			       break;
			
			case 4:Display(head);
			       break;

			case 5:printf("Number of nodes in the list = %d\n",ListNodeCount(head));
			       break;

			case 6:DeleteFromEnd(&head);
			       break;

			case 7:DeleteFromBeg(&head);
			       break;

			case 8:printf("Enter the position from which the node should be deleted\n");
			       scanf("%d",&pos);
			       DeleteFromPos(&head,pos);
			       break;

			case 9: ReverseDisplay(head);
				printf("\n");
				break;

			case 10:ReverseList(&head,&head);	//sending the head pointer twice
				break;

			case 11: exit(0);
				 break;

			default : printf("Enter an option from the list provided\n");
				  break;
		}//end of switch case
	}//end of while loop

}//end of main function

//InsertAtEnd Function definition

void InsertAtEnd(struct node **h,int d){
	struct node *t;		//this structure pointer is created so that we can navigate through the linked list
	t=*h;			//t takes the value of the head pointer. We need this because we don't wish to alter the value held by head pointer
	struct node *temp;	//temp pointer is created to take in the new values
	temp=(struct node *)malloc(sizeof(struct node));

	temp->data=d;
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

}//end of InsertAtEnd

//InsertAtBeg function definition

void InsertAtBeg(struct node **h,int d){
	if(*h==NULL)
	{
		InsertAtEnd(h,d);	//calling the insert function as the list is empty
	}
	else
	{
		struct node *temp;		//temp pointer is created to take in the new values
		temp=(struct node *)malloc(sizeof(struct node));
	
		temp->data=d;
		temp->next=*h;			//temp next now points to the head 
		*h=temp;			//we set the head pointer with the value of the temp pointer
	}
}//end of InsertAtBeg

//InsertAtPos function definition

void InsertAtPos(struct node **h,int d, int p){
	if(*h==NULL)		//if the list is empty we just start creating the list
	{
		printf("The list is empty...........\nInserting at the begining.........\n ");
		InsertAtEnd(h,d);
	}
	else if(p==1)		//if the position to be entered at is 1 then use InsertAtBeg() function
	{
		InsertAtBeg(h,d);	
	}
	else			//if the position is a value greater than 1
	{
		int track=2;		// to track till position number via iteration. track is initialized with 2 as that is the starting position
		struct node *t;		//to navigate through the linked list
		t=*h;
		struct node *temp;	//to take in new values
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=d;
		
		while(track<p)		//the track value is incremented untill it reaches the list just before the position so that t->next is the position we require
		{
			t=t->next;
			track++;
		}
		temp->next=t->next;	//temp->next points to the list at the position
		t->next=temp;		//temp is now placed at the position
	}

}//end of InsertAtPos

//Display function definition

void Display(struct node *h){
	if(h==NULL)
	{
		printf("Empty list\n");
	}
	else
	{
		while(h->next!=NULL)
		{
			printf("-->%d",h->data);
			h=h->next;
		}

			printf("-->%d\n",h->data);
	}

}//end of Display

//listNodeCount function definition

int ListNodeCount(struct node *h){
	if(h==NULL)
	{
		return 0;
	}
	else
	{	int count=0;
		while(h->next!=NULL)
		{
			count++;
			h=h->next;
		}
		count++;
		return count;
	}
}//end of ListNodeCount

//DeleteFromEnd function definition

void DeleteFromEnd(struct node **h){
	if(*h==NULL)
	{
		printf("The list is already empty.........\n");
	}
	else if((*h)->next==NULL)
	{
		*h=NULL;
	}
	else
	{
		struct node *t;		//to navigate through the list
		t=*h;
		struct node *temp;	//to store the previous node address
		while(t->next!=NULL)
		{
			temp=t;
			t=t->next;
		}
		temp->next=NULL;	//deleting the end node
		free(t);		//freeing the deleted node memory so that it can be returned to heap
	}	
}//end of DeleteFromEnd

//DeleteFromBeg function definition

void DeleteFromBeg(struct node **h){
	if(*h==NULL)
	{
		printf("The list is already empty...........\n");
	}
	else if((*h)->next==NULL)
	{
		*h=NULL;
	}
	else
	{
		struct node *temp;
		temp=*h;		//storing address of the head pointer so that it can be freed later
		*h=(*h)->next;
		free(temp);		//freeing the memory of the deleted node

	}
}//end of DeleteFromBeg

//DeleteFromPos function definition

void DeleteFromPos(struct node **h,int p){
	
	if(*h==NULL)
	{
		printf("The list is already empty............\n");
	}
	else if(p==1)		//if the position to be deleted is 1
	{
		DeleteFromBeg(h);
	}
	else			//if the position is a value greater than 1
	{
		int track=2;		// to track till position number via iteration. track is initialized with 2 as that is the starting position
		struct node *t;		//to navigate through the linked list
		t=*h;
		struct node *temp;
		
		while(track<p)		//the track value is incremented untill it reaches the list just before the position so that t->next is the position we require
		{
			t=t->next;
			track++;
		}
		temp=t;			//temp now points to the node before the position
		t=t->next;		//t points to the node at position
		temp->next=t->next;	//temp next which originally points to position node now points to the node which is pointed by the position node
		free(t);		//freeing the deleted node memory
	}
}//end of DeleteFromPos

//ReverseDisplay function definition

void ReverseDisplay(struct node *h){
	if(h==NULL)
	{
		printf("The list is empty..........\n");
	}
	else
	{
		if(h->next!=NULL)
			ReverseDisplay(h->next);
		printf("-->%d",h->data);
	}
}//end of ReverseDisplay

//ReverseList function definition

void ReverseList(struct node **h,struct node **H){	
	if(*h==NULL)
	{
		printf("The list is empty..........\n");
	}
	else
	{
		struct node *t;
		t=*h;
		if(t->next!=NULL)
		{
			ReverseList(&(t->next),H);	//recursively calling the function by passing the address of (pointer to next list and main header as arguments)
		}
		if(t->next==NULL){
		//t should become head pointer as now this is the last node and we are reversing the list
		*H=t;
		}
		else
		{
		(t->next)->next=t;			// reversing list by reversing the pointings of the previous order
		t->next=NULL;				//the current node is set as last node and by going back in the recursive function the first node will be set as the last node
		}
	}
}//end of ReverseList

//END OF PROGRAM
