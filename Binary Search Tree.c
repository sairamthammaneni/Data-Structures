/*C protgram to represent Binary Search Trees*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *lchild,*rchild;
};
typedef struct node NODE;
NODE *root=NULL;

NODE *insert(NODE *,int );
void inorder(NODE *);
void preorder(NODE *);
void postorder(NODE *);
void search(NODE *,int );
int height(NODE *);
int count(NODE *);

int main(){
	int ch,item;
	while(1){
		printf("\n*****MENU*****\n1.Insert\n2.Inorder Traversal\n3.Pre order Traversal\n4.Post oreder Traversal\n5.Search\n6.Height of the tree\n7.Count the number of nodes\n");
		printf("8.Number of edges in tree\n9.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1 :	printf("Enter the element to be inserted:");
						scanf("%d",&item);
						root=insert(root,item);
						break;
			case 2 :	inorder(root);
						break;
			case 3 :	preorder(root);
						break;
			case 4 :	postorder(root);
						break;
			case 5 :	printf("Enter the element to be seached:");
						scanf("%d",&item);
						search(root,item);
						break;
			case 6 :	printf("Height (or) Depth of the BST is %d",height(root););
						break;
			case 7 :	printf("Number of nodes in the tree are %d",count(root));
						break;
			case 8 :	printf("Number of edges in the tree are %d",(count(root)-1));
						break;
			case 9:		exit(0);
			default:	printf("Invalid choice!!!");
		}
	}
}

NODE *insert(NODE *root,int item){
	if(root==NULL){
		root=(NODE*)malloc(sizeof(NODE));
		root->data=item;
		root->lchild=root->rchild=NULL;
	}
	else if(item>root->data){
		root->rchild=insert(root->rchild,item);
	}
	else{
		root->lchild=insert(root->lchild,item);
	}
	return root;
}

void inorder(NODE *root){
	if(root->lchild!=NULL)
		inorder(root->lchild);
	printf("%d ",root->data);
	if(root->rchild!=NULL)
		inorder(root->rchild);
}

void preorder(NODE *root){
	printf("%d ",root->data);
	if(root->lchild!=NULL)
		inorder(root->lchild);
	if(root->rchild!=NULL)
		inorder(root->rchild);
}

void postorder(NODE *root){
	if(root->lchild!=NULL)
		inorder(root->lchild);
	if(root->rchild!=NULL)
		inorder(root->rchild);
	printf("%d ",root->data);
}

void search(NODE *root,int key){
	if(root==NULL){
		printf("Key is not found");
	}
	else if(key==root->data)
		printf("Key is found");
	else if(key>root->data)
		search(root->rchild,key);
	else
		search(root->lchild,key);
}

int height(NODE *root){
	int lsh,rsh;
	if(root==NULL)
		return 0;
	else{
		lsh=height(root->lchild);
		rsh=height(root->rchild);
		if(lsh>rsh)
			return (lsh+1);
		else
			return (rsh+1);
	}
}

int count(NODE *root){
	if(root==NULL)
		return 0;
	else{
		return (count(root->lchild)+count(root->rchild)+1);
	}
}
