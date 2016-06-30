#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node  {
	int elemnt,count,parent;
	char setname[1];
};
typedef struct node node;
node *ptr[50];
int root[2], k = -1;
void readset() {
	int n, i;
	struct node *temp;
	int temparray[20];
	temp= (struct node*) malloc ( sizeof(node) );
	temp->parent = -1;
	printf("\n Enter name of this Set : ");
	scanf("%s",temp->setname);
	printf("\n Enter the number of elements : ");
	scanf("%d",&n);
	temp->count = n;
	printf("\n Enter the root element : ");
	scanf("%d",&temp->elemnt);
	root[++k] = temp->elemnt;
	ptr[temp->elemnt] = temp;
	printf("\n Enter the set elements : ");
	for(i = 0; i < n-1; i++)
		scanf("%d",&temparray[i]);
	for(i = 0; i < n-1; i++) {
		temp = (struct node*)malloc(sizeof(node));
		temp->count = -1;
		temp->elemnt = temparray[i];
		printf("\n Enter the parent of %d : ",temparray[i]);
		scanf("%d",&temp->parent);
		ptr[temp->elemnt] = temp;
	}
}
void uniono() {
	struct node *t1, *t2;
	t1 = ptr[root[0]];
	t2 = ptr[root[1]];
	if(t1->count > t2->count) {
		t1->parent = t2->elemnt;
		t2->count += t1->count;
	}
	else {
		t2->parent = t1->elemnt;
		t1->count += t2->count;
	}
}
void display() {
	int i;
	printf("\n\tElement\t\tParent");
	for(i = 0; i < 50; i++)  
		if(ptr[i] != NULL)
			printf("\n\t%d\t \t%d",ptr[i]->elemnt,ptr[i]->parent);
}
void find(int x) {
	struct node *temp;
	int root, par;
	temp = ptr[x];
	while(temp->parent != -1)
		temp = ptr[temp->parent];
	root = temp->elemnt;
	temp = ptr[x];
	while(temp->parent != -1) {
		par = temp->parent;
		if(temp->parent != root)
			temp->parent = root;
		temp = ptr[par];
	}
	printf("\n Element is in to set %s. ",temp->setname);
}
int main() {
	int ch, x;
	for(x = 0; x < 50; x++)
	ptr[x] = NULL;	
	do {
		printf("\n\n 1. Create set \n 2. Find an element \n 3. Join Trees \n 4. Exit ");
		printf("\n\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch) {
			case 1:
				printf("\n Details of First Tree: \n");
				readset();
				printf("\n Details of Second Tree: \n");
				readset();
				break;
			case 2:
				printf("\n Enter the element to be searched : ");
				scanf("%d",&x);
				find(x);
				break;
			case 3:
				uniono();
				display();
				break;
			case 4:
				break;
			default:
				printf("\n Invalid Entry! Try with numbers 1-3!\n");
		}
	}while(ch!=4);
}


/*
 1. Create set 
 2. Find an element 
 3. Join Trees 
 4. Exit 

 Enter your choice: 1

 Details of First Tree: 
 
 Enter name of this Set : A

 Enter the number of elements : 4

 Enter the root element : 1

 Enter the set elements : 3 5 7

 Enter the parent of 3 : 1

 Enter the parent of 5 : 1

 Enter the parent of 7 : 3

 Details of Second Tree: 
 
 Enter name of this Set : B

 Enter the number of elements : 4

 Enter the root element : 2

 Enter the set elements : 4 6 8 

 Enter the parent of 4 : 2

 Enter the parent of 6 : 2

 Enter the parent of 8 : 6


 1. Create set 
 2. Find an element 
 3. Join Trees 
 4. Exit 

 Enter your choice: 2

 Enter the element to be searched : 3

 Element is in to set A. 

 1. Create set 
 2. Find an element 
 3. Join Trees 
 4. Exit 

 Enter your choice: 3

	Element		Parent
	1	 		-1
	2	 		1
	3	 		1
	4	 		2
	5	 		1
	6	 		2
	7	 		3
	8	 		6

 1. Create set 
 2. Find an element 
 3. Join Trees 
 4. Exit 

 Enter your choice: 4

*/
