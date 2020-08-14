/* 
 * The program defines functions to manipulate a binary search tree:
 * includes function: 
 * to insert new node, 
 * to display the tree in pre-order, in-order, post-order
 * to delete node
 * to rotate tree and get balanced tree
 */

//START OF PROGRAM...................................................

//header files

#include<stdio.h>		//standard library
#include<stdlib.h>		//to aloow malloc and free functions

//defining macros

#define TRUE 1
#define FALSE 0

//defining structure as nodes of the binary tree (structure must be defined above the functions that maanipulate it)

struct node{
	int data;
	struct node *left;
	struct node *right;
};

//declaring functions................................................
void Insert(struct node **,int);
void PreOrderDisplay(struct node *);
void InOrderDisplay(struct node *);
void PostOrderDisplay(struct node *);
void Delete(struct node **,int);
void search(struct node **,struct node **,int,int *);
//..................................................................

//main function.....................................................

int main(){
	struct node *root=NULL;
	int choice,element;
	while(1){
		printf("Enter a choice from the following options: \n1.Insert\n2.PreOrderDisplay\n3.InOrderDisplay\n4.PostOrderDisplay\n5.Delete\n6.Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter an integer element to be inserted\n");
				scanf("%d",&element);
				Insert(&root,element);
				break;

			case 2:
				PreOrderDisplay(root);
				printf("\n");
				break;

			case 3:
				InOrderDisplay(root);
				printf("\n");
				break;

			case 4:
				PostOrderDisplay(root);
				printf("\n");
				break;

			case 5:
				printf("Enter the value to be deleted\n");
				scanf("%d",&element);
				printf("Deleting %d......................\n",element);
				Delete(&root,element);
				break;

			case 6:
				printf("EXITING...........................\n");
				exit(0);
				break;

			default:
				printf("Enter a valid option please................\n");
				break;
		}//end of switch
	}//end of while
}//end of main function

//Insert function definition

void Insert(struct node **r,int ele){
	
	if(*r==NULL)	//adding root node to an empty tree
	{
		struct node *temp;
		temp=(struct node *)malloc(sizeof(struct node));	//creating a node
		temp->data=ele;
		temp->left=NULL;
		temp->right=NULL;
		*r=temp;
	}
	else		//the root is not empty
	{
		if(ele>(*r)->data)	//if the value is greater than that of the node then move to the right branch and repeat same process
		{
			Insert(&((*r)->right),ele);
		}
		else			//if the value is less than that of the node then move to the left branch and repeat same process
		{
			Insert(&((*r)->left),ele);
		}
	}
}

//end of function Insert()

//PreOrderDisplay function definition

void PreOrderDisplay(struct node *r){				//root->left->right
	if(r==NULL)
	{
		printf("The tree is empty................\n");
	}
	else
	{
		printf("--> %d ",r->data);
		if(r->left!=NULL)
		{
			PreOrderDisplay(r->left);
		}
		if(r->right!=NULL)
		{
			PreOrderDisplay(r->right);
		}
	}
}//end of function PreOrderDisplay

//InOrderDisplay function definition

void InOrderDisplay(struct node *r){				//left->root->right
	if(r==NULL)
	{
		printf("The tree is empty................\n");
	}	
	else
	{
		if(r->left!=NULL)
		{
			InOrderDisplay(r->left);
		}
	
		printf("--> %d ",r->data);
	
		if(r->right!=NULL)
		{
			InOrderDisplay(r->right);
		}
	}
}//end of function InOrderDisplay

//PostOrderDisplay function definition

void PostOrderDisplay(struct node *r){				//left->right->root
	if(r==NULL)
	{
		printf("The tree is empty..................\n");
	}
	else
	{
		
		if(r->left!=NULL)
		{
			PostOrderDisplay(r->left);
		}
	
		if(r->right!=NULL)
		{
			PostOrderDisplay(r->right);
		}

		printf("--> %d ",r->data);
	}
}//end of function PostOrderDisplay

//Delete function definition

void Delete(struct node **r,int ele){
	
	int found=0;
	struct node *parent=*r;		//creating a parent and current node to search for element and the subsequent deletion
	struct node *current=*r;
	search(&parent,&current,ele,&found);
	if(found == FALSE )
	{
		printf("This element is not found in this tree\n");
	}
	else
	{
		//case 1 leaf node............
		if(current->left==NULL && current->right==NULL)
		{
			if(current!=NULL)
			{
			if(ele>(parent->data))
				parent->right=NULL;
			else
				parent->left=NULL;	
			}
			else 
				*r=NULL;
			free(current);
			
		}
		//case 2 element with one child
		//Here we replace the deletion node with its child
		else if(current->left!=NULL && current->right==NULL)
		{
			if(ele>(parent->data))
				parent->right=current->left;
			else
				parent->left=current->left;	
			free(current);
		}

		else if(current->left==NULL && current->right!=NULL)
		{
			printf("Deleting %d .............\n",ele);
			if(ele>(parent->data))
				parent->right=current->right;
			else
				parent->left=current->right;	
			free(current);
		}
		//case 3 element with two children
		//Here we replace the deletion node with its left child and recursively call delete on that left child.
		else
		{
			parent=current;
			current=current->left;
			int value=current->data;
			Delete(&parent,value);		//not freeing anything here as we are calling recursive function which will thereby free in either of the above two cases.
			parent->data=value;
		}
	}
		
}//end of function Delete

//search function definition

void search(struct node **par,struct node **cur,int e,int *f){

		if((*cur)->data==e)		//if the value matches  we return a indication that the value was found and the parent pointer will contain the element node address
		{
			*f=1;
			return;
		}
		else if(e>(*cur)->data)		//shifting the search to the right branch
		{
			*par=*cur;
			*cur=(*cur)->right;
			search(par,cur,e,f);
		}
		else if(e<(*cur)->data)		//shifting the search to the left branch
		{
			*par=*cur;
			*cur=(*cur)->left;
			search(par,cur,e,f);
		}
		else if(*cur==NULL)		//element not found
		{
			return;
		}

}//end of function search

//END OF PROGRAM.....................................................
