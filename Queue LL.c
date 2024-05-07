// To impliment queues using linled list//
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *front=NULL;
NODE *rear=NULL;
void display();
void insert(int item);
void dequeue();
int main(){
	int item,ch;
	while(1){
		printf("\nMENU\n1.Insert\n2.Dequeue\n3.display\n4.exit\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:	printf("Enter the element:");
					scanf("%d",&item);
					insert(item);
					break;
			case 2: dequeue();
					break;
			case 3:	display();
					break;
			case 4:	exit(0);
			default:printf("Invalid choice!!\n");
		}
	}
}
void display(){
	NODE *temp;
	if(front==NULL)
		printf("Queue is empty\n");
	else{
		temp=front;
		printf("Queue content:\n");
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}
void insert(int item){
	NODE *temp;
	temp=(NODE*)malloc(sizeof(NODE));
	temp->data=item;
	if(rear==NULL){
		rear=temp;
		front=rear;
		rear->next=NULL;	
	}
	else{
		rear->next=temp;
		rear=temp;
		rear->next=NULL;
	}
}
void dequeue(){
	NODE *temp;
	temp=front;
	if(front==NULL)
		printf("Queue is empty\n");
	else{
		front=temp->next;
		printf("Deleted element is:%d",temp->data);
		if(front==rear)
			front=rear=NULL;
		free(temp);
	}
}
