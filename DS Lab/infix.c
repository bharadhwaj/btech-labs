#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
	char data[5];
	struct node *lchild, *rchild;
};
typedef struct node node;
int stack[5], top=-1;
void display(node *root) {
	node *temp = root;
	if(temp != NULL) {
		if(strcmp(temp->data,"*") >= 0 && strcmp(temp->data,"/") <= 0)
			printf("(");
		display(temp->lchild);
		printf(" %s ",temp->data);
		display(temp->rchild);
		if(strcmp(temp->data,"*") >= 0 && strcmp(temp->data,"/") <= 0)
			printf(")");
	}
}
node *build() {
	node *new = (node*)malloc(sizeof(node));
	scanf("%s",  new->data);
	new->lchild = new->rchild = NULL;
	if(strcmp(new->data,"*") >= 0 && strcmp(new->data,"/") <= 0) {
		printf("\n Enter left child of %s : ",new->data);
		new->lchild = build();
		printf("\n Enter right child of %s : ",new->data);
		new->rchild = build();
	}
	return new;
}
void post(node *root) {
	int n1, n2, i;
	if(root != NULL) {
		post(root->lchild);
		post(root->rchild);
		if(strcmp(root->data,"*") >= 0 && strcmp(root->data,"/") <= 0) {
			n2 = stack[top--];
			n1 = stack[top--];
			switch(root->data[0]) {
				case '*':
					stack[++top] = n1*n2;
					break;
				case '/':
					stack[++top] = n1/n2;
					break;
				case '+':
					stack[++top] = n1+n2;
					break;
				case '-':
					stack[++top] = n1-n2;
					break;
			}
		}
		else {
			for(i = 0,n1 = 0;root->data[i] != '\0';i++)
				n1 = n1*10+root->data[i]%'0';
			stack[++top] = n1;
		}
	}
}
main() {
	int i = 0, n, n1, n2, top = -1;
	printf("\n Enter the root operator : ");
	node *root = build();
	printf("\n Infix expression is: \n ");
	display(root);
	post(root);
	printf(" = %d\n", stack[0]);
}

/*
 Enter the root operator : -

 Enter left child of - : *

 Enter left child of * : +

 Enter left child of + : 9

 Enter right child of + : 3

 Enter right child of * : 5

 Enter right child of - : *

 Enter left child of * : 6

 Enter right child of * : -

 Enter left child of - : 15

 Enter right child of - : 5

 Infix expression is: 
 ((( 9  +  3 ) *  5 ) - ( 6  * ( 15  -  5 ))) = 0
*/
