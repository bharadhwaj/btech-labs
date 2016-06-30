#include<stdio.h>
#include<stdlib.h> 
struct node {
	int data;
	struct node *lchild, *rchild;
};
typedef struct node node;
node* insert(node *root, int elt) {
	node *temp;
	temp = root;
	if(temp == NULL) {
		node *new = (node*) malloc (sizeof(node));
		new->data = elt;
		new->lchild = NULL;
		new->rchild = NULL;
		root = new;
	}
	else if(temp->data < elt)
		temp->rchild = insert(temp->rchild,elt);
	else if(temp->data > elt)
		temp->lchild = insert(temp->lchild,elt);
	else
		printf("\n\n Element already exists!");
	return root;
}
int search(node *root, int elt) {
	
	node *temp;
	temp = root;
	if(temp == NULL)
		printf("\n\n Element not in Binary search tree.");
	else if(temp->data == elt) 
		return 1;
	else if(temp->data > elt)
		search(temp->lchild,elt);
	else
		search(temp->rchild,elt);

}
node* findmin(node *root) {
	node *temp = root;
	while(temp->lchild != NULL)
		temp = temp->lchild;
	return temp;
}
node* delete(node *root, int elt) {

	int s;
	node *temp = root;
	s = search(root,elt);
	if(s == 1) {
		if(root == NULL)
			printf("\n Binary Search Tree is empty.");
		else if(root->data == elt) {
			if(root->lchild == NULL)
				root = root->rchild;
			else if(root->rchild == NULL)
				root = root->lchild;
			else if(root->lchild != NULL && root->rchild != NULL) {
				node *minnode = findmin(root->rchild);
				root->data = minnode->data;
				root->rchild = delete(root->rchild,minnode->data);
			}
			else {
				temp = root;
				free(temp);
			}
		}
		else if(root->data > elt)
			root->lchild = delete(root->lchild,elt);
		else if(root->data < elt)
			root->rchild = delete(root->rchild,elt);
	}
	return root;
}	
void inorder(node *root) {
	node *temp = root;
	if(temp != NULL) {
		inorder(temp->lchild);
		printf("%d -> ",temp->data);
		inorder(temp->rchild);
	}
}

void preorder(node *root) {
	node *temp = root;
	if(temp != NULL) {
		printf("%d -> ",temp->data);
		preorder(temp->lchild);
		preorder(temp->rchild);
	}
}

void postorder(node *root) {
	node *temp = root;
	if(temp != NULL) {
		postorder(temp->lchild);
		postorder(temp->rchild);
		printf("%d -> ",temp->data);
	}
}	

int main() {

	int ch,ch1,elt,elt1,elt2,s;
	node *root = NULL;

	do {
		printf("\n\n 1. Insert into a Binary Search Tree.");
		printf("\n 2. Delete from a Binary Search Tree.");
		printf("\n 3. Search an element in the Binary Search Tree.");
		printf("\n 4. Display the binary search tree.");
		printf("\n 5. Exit.");
		printf("\n\n Enter your choice: ");
		scanf("%d",&ch);
		printf("\n");
		switch(ch) {
			case 1:
				do {
				printf("\n Enter the element to be inserted(-999 to stop): ");
				scanf("%d",&elt);
				if(elt != -999)	
					root = insert(root,elt);
				}while(elt != -999);
				break;
			case 2:
				printf("\n\n Enter the element to be deleted: ");
				scanf("%d",&elt1);
				root = delete(root,elt1);
				break;
			case 3:
				
				
				printf("\n\n Enter the element to be searched: ");
				scanf("%d",&elt2);
				s = search(root,elt2);
				if(s == 1)
					printf("\n Element is found!");
				break;
			case 4:
				do {
					printf("\n\n 1. Inorder display.");
					printf("\n 2. Preorder display.");
					printf("\n 3. Postorder display.");
					printf("\n 4. Back.");
					printf("\n\n Enter the choice: ");
					scanf("%d",&ch1);
					switch(ch1) {
						case 1:
							inorder(root);
							break;
						case 2:
							preorder(root);
							break;
						case 3:
							postorder(root);
							break;
						case 4:
							break;
						default:
							printf("\n\n Invalid choice!");
					}
				}while(ch1 != 4);
				break;
			case 5:
				return 0;
			default:
				printf("\n\n Invalid choice!");
		}
	}while(ch != 5);
}
