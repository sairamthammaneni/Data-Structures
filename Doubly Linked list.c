#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *pre,*next;
};
typedef struct node NODE;
NODE *head=NULL;
void create();
void traverse_right();
void traverse_left();
void insert_front(int);
void insert_last(int);
int main()
{
	int item,ch;
	create();
	while(1)
	{
		printf("\nMENU\n");
		printf("1.Traverse right\n");
		printf("2.Traverse left\n");
		printf("3.Insert Front\n");
		printf("4.Insert Last\n");
		printf("5.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				traverse_right();
				break;
			case 2:
				traverse_left();
				break;
			case 3:
				printf("Enter the element:\n");
				scanf("%d",&item);
				insert_front(item);
				break;
			case 4:
				printf("Enter the element:\n");
				scanf("%d",&item);
				insert_last(item);
				break;
			case 5:
				exit(0);
			default:printf("Invalid choice!!\n");
		}
	}
}
void create()
{
	 NODE *temp,*cur=head;
	 int item;
	 char ch; 
	 do
	 {
	 	printf("\nEnter the element:\n");
	 	scanf("%d",&item);
	 	temp=(NODE*)malloc(sizeof(NODE));
	 	temp->data=item;
	 	if(head==NULL)
	 	{
	 		head=cur=temp;
	 		head->pre=NULL;
	 		head->next=NULL;
	 	}
	 	else
	 	{
	 		cur->next=temp;
	 		temp->pre=cur;
	 		cur=cur->next;
	 	}
	 	printf("Do you want to continue?(y/n):");
	 	scanf("%c",&ch);
	 }while(ch=='y'||ch=='Y');
	 cur->next=NULL;
}
void traverse_right()
{
	NODE *cur=head;
	if(head==NULL)
	{
		printf("\nList is empty!!\n");
	}
	else
	{
		while(cur!=NULL)
		{
			printf("%d ",cur->data);
			cur=cur->next;
		}
	}
}
void traverse_left()
{
	NODE*cur=head;
	if(head==NULL)
		printf("List is empty\n");
	else
	{
		while(cur!=NULL)
			cur=cur->next;
		while(cur!=NULL)
		{
			printf("%d ",cur->data);
			cur=cur->pre;
		}
	}
}
void insert_front(int item)
{
	NODE *temp;
	temp=(NODE*)malloc(sizeof(NODE));
	temp->data=item;
	temp->next=head;
	head->pre=temp;
	head=temp;
	head->pre=NULL;
}
void insert_last(int item)
{
	NODE *temp,*cur=head;
	temp=(NODE*)malloc(sizeof(NODE));
	temp->data=item;
	if(head==NULL)
	{
		insert_front(item);
	}
	else
	{
		while(cur->next!=NULL)
		{
			cur=cur->next;
		}
		cur->next=temp;
		temp->pre=cur;
		temp->next=NULL;
	}	
}
