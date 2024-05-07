#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct even{
	int d1;
	struct even *n1;
};
struct odd{
	int d2;
	struct odd *n2;
};
typedef struct node NODE;
typedef struct even EVEN;
typedef struct odd ODD;
void create();
void display();
void insert_front(int);
void insert_last(int);
void insert_pos(int,int);
void delete_front();
void delete_last();
void delete_pos(int);
void count();
void search(int );
void split();
void E_O();
NODE *head=NULL;
EVEN*h1=NULL;
ODD *h2=NULL;
int main()
{
 	int choice,item,pos,key;
 	create();
 	while(1)
 	{
 		printf("\nMENU\n");
 		printf("1.Insert front\n");
 		printf("2.Insert last\n");
 		printf("3.Insert at a specified position\n");
 		printf("4.Delete front\n");
 		printf("5.Delete last\n");
 		printf("6.Delete at specified position\n");
 		printf("7.Count the number of nodes\n");
 		printf("8.Search an element in the list\n");
 		printf("9.Split the list\n");
 		printf("10.Even or odd list\n");
 		printf("11.Display\n");
 		printf("12.Exit\n");
 		printf("Enter your choice:");
 		scanf("%d",&choice);
 		switch(choice)
 		{
 			case 1:
 				printf("The element to be inserted");
 				scanf("%d",&item);
 				insert_front(item);
 				break;
 			case 2:
 				printf("The element to be inserted");
 				scanf("%d",&item);
 				insert_last(item);
 				break;
 			case 3:
 				printf("Enter the position:");
 				scanf("%d",&pos);
 				printf("Enter the element:");
 				scanf("%d",&item);
 				insert_pos(item,pos);
 				break;
 			case 4:
 				delete_front();
 				break;
 			case 5:
 				delete_last();
 				break;
 			case 6:
 				printf("Enter the position:");
 				scanf("%d",&pos);
 				delete_pos(pos);
 				break;
 			case 7:
 				count();
 				break;
 			case 8:
 				printf("Enter the element to be searched:");
 				scanf("%d",&key);
 				search(key);
 				break;
 			case 9:
 				split();
 				break;
 			case 10:
 				E_O();
 				break;
 			case 11:
 				display();
 				break;
 			case 12:
 				exit(0);
 			default:
 				printf("Invalid choice!!\n");
 		}
 	}
}
void create()
{
	NODE *cur,*temp;
	int ch;
	int item;
	do{
		printf("Enter the element:");
		scanf("%d",&item);
		temp=(NODE*)malloc(sizeof(NODE));
		temp->data=item;
		if(head==NULL)
		{
			head=cur=temp;
		}
		else
		{
			cur->next=temp;
			cur=temp;
		}
		printf("Do you want to continue(YES-1/NO-0):");
		scanf("%d",&ch);
	}while(ch==1);
		cur->next=NULL;
}
void display()
{
	NODE *temp=head;
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		printf("List content:\n");
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}
void insert_front(int item)
{
	NODE *temp,*cur=head;
	temp=(NODE*)malloc(sizeof(NODE));
	temp->data=item;
	temp->next=cur;
	head=temp;
}
void insert_last(int item)
{
	NODE *temp,*cur=head;
	temp=(NODE*)malloc(sizeof(NODE));
	temp->data=item;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		while(cur->next!=NULL)
		{
			cur=cur->next;
		}
		cur->next=temp;
	}
	temp->next=NULL; 
}
void insert_pos(int item,int pos)
{
	int i;
	NODE *temp,*cur=head;
	if(pos==1)
	{
		insert_front(item);
	}
	else
	{
		for(i=1;i<=(pos-2);i++)
		{
			cur=cur->next;
		}
		if(cur==NULL)
		{
			printf("Invalid position!!\n");
		}
		else
		{
			temp=(NODE*)malloc(sizeof(NODE));
			temp->data=item;
			temp->next=cur->next;
			cur->next=temp;
		}
	}
}
void delete_front()
{
	NODE *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		temp=head;
		head=head->next;
		printf("Deleted element is %d\n",temp->data);
		free(temp);
	}
}
void delete_last()
{
	NODE *temp,*cur=head;
	if(head==NULL)
	{
		printf("List is empty!!!\n");
	}
	else if(head->next==NULL)
	{
		temp=head;
		head=head->next;
		free(temp);
		printf("Deleted element is %d\n",temp->data);
	}
	else
	{
		while(cur->next->next!=NULL)
		{
			cur=cur->next;
		}
		temp=cur->next;
		cur->next=NULL;
		printf("Deleted element is %d\n",temp->data);
		free(temp);
	}
}
void delete_pos(int pos)
{
	int i;
	NODE *temp,*cur=head;
	if(pos==1)
	{
		delete_front();
	}
	else
	{
		for(i=1;i<=(pos-2);i++)
		{
			cur=cur->next;
		}
		if(cur==NULL)
		{
			printf("Invalid position!!\n");
		}
		else
		{
			temp=cur->next;
			cur->next=temp->next;
			printf("Deleted element is %d\n",temp->data);
			free(temp);
		}
	}
}
void count()
{
	int i=0;
	NODE *cur=head;
	if (head==NULL)
	{
		printf("The list has NO nodes");
	}
	else
	{
		while (cur!=NULL)
		{
			i++;
			cur=cur->next;
		}
	printf("The list has %d nodes",i);
	}
}
void search(int key)
{
	int i=0,flag=-1;
	NODE *cur=head;
	if(head==NULL)
		printf("The list is empty!!!");
	else
	{
		while(cur!=NULL)
		{
			i++;
			if(cur->data==key)
			{
				flag=i;
				break;
			}
			cur=cur->next;
		}
		if(flag==-1)
		{
			printf("Key is not found in the list");
		}
		else
		{
			printf("Key is found node-%d",flag);
		}
	}
}
void split()
{
	int i=0,j;
	NODE *cur=head;
	if(head==NULL)
		printf("The list is empty");
	else
	{
		while(cur!=NULL)
		{
			i++;
			cur=cur->next;
		}
		cur=head;
		printf("The first half of the list is:");
		j=i;
		i=(i/2);
		while(i!=0)
		{
			printf("%d ",cur->data);
			cur=cur->next;
			i--;
		}
		if(j%2!=0)
		{
			printf("\nThe middle element is:%d",cur->data);
			cur=cur->next;
			printf("\nThe second half of the list is:");
			while(cur!=NULL)
			{
				printf("%d ",cur->data);
				cur=cur->next;
			}
		}
		else
		{
			printf("\nThe second half of the list is:");
			while(cur!=NULL)
			{
				printf("%d ",cur->data);
				cur=cur->next;
			}
		}
	}
	
}
void E_O()
{
	NODE *cur=head;
	int item;
	EVEN *c1,*t1;
	ODD *c2,*t2;
	if(head==NULL)
		printf("The list is empty");
	else
	{
		while(cur!=NULL)
		{
			item=cur->data;
			if(item%2==0)
			{
				t1=(EVEN*)malloc(sizeof(EVEN));
				t1->d1=item;
				if(h1==NULL)
				{
					h1=c1=t1;
				}
				else
				{
					c1->n1=t1;
					c1=t1;	
				}
				c1->n1=NULL;
			}
			else
			{
				t2=(ODD*)malloc(sizeof(ODD));
				t2->d2=item;
				if(h2==NULL)
				{
					h2=c2=t2;
				}
				else
				{
					c2->n2=t2;
					c2=t2;	
				}
				c2->n2=NULL;
			}
			cur=cur->next;
		}
	}
	printf("\nEven list:");
	c1=h1;
	if(h1==NULL)
		printf("The list is empty!!");
	else
	{
		while(c1!=NULL)
		{
			printf("%d ",c1->d1);
			c1=c1->n1;
		}	
	}
	printf("\nOdd list:");
	c2=h2;
	if(h2==NULL)
		printf("The list is empty!!");
	else
	{
		while(c2!=NULL)
		{
			printf("%d ",c2->d2);
			c2=c2->n2;
		}	
	}
}
