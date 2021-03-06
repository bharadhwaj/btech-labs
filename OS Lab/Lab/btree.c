#include<stdio.h>
#include<stdlib.h>
#define M 5

struct node{
	int n;
	int keys[M-1];
	struct node *p[M];
}*root=NULL;

enum KeyStatus { Duplicate,SearchFailure,Success,InsertIt,LessKeys };

void insert(int key);
void display(struct node *root,int);
void DelNode(int x);
enum KeyStatus ins(struct node *r, int x, int* y, struct node** u);
int searchPos(int x,int *key_arr, int n);


int main() {
	int key;
	int choice;
	printf("\nB tree is of order 5\n\n");
	while(1) {
		printf("\t1.Insert\n");
		printf("\t2.Display\n");
		printf("\t3.Quit\n");
		printf("\tEnter your choice : ");
		scanf("%d",&choice);
		switch(choice) {
			case 1:
			    printf("Enter the key : ");
				scanf("%d",&key);
				insert(key);
				printf("\n %d inserted\n\n",key);
				break;
			case 2:
				printf("Btree is :\n");
				display(root,0);
				break;
			case 3:
				exit(1);
			default:
				printf("Wrong choice\n");
				break;
		}
	}
	return 0;
}

void insert(int key)
{
	struct node *newnode;
	int upKey;
	enum KeyStatus value;
	
	value = ins(root, key, &upKey, &newnode);
	
	if (value == Duplicate)
		printf("Key already available\n");
	if (value == InsertIt)
	{
		struct node *uproot = root;
		root=(struct node*)malloc(sizeof(struct node));
		root->n = 1;
		root->keys[0] = upKey;
		root->p[0] = uproot;
		root->p[1] = newnode;
	}
}

enum KeyStatus ins(struct node *ptr, int key, int *upKey,struct node **newnode)
{
	struct node *newPtr, *lastPtr;
	int pos, i, n,splitPos;
	int newKey, lastKey;
	enum KeyStatus value;

	if (ptr == NULL)
	{
		*newnode = NULL;
		*upKey = key;
		return InsertIt;
	}
	n = ptr->n;
	pos = searchPos(key, ptr->keys, n);
	if (pos < n && key == ptr->keys[pos])
		return Duplicate;
		
	value = ins(ptr->p[pos], key, &newKey, &newPtr);
	if (value != InsertIt)
		return value;

	if (n < M - 1)
	{
		pos = searchPos(newKey, ptr->keys, n);

		for (i=n; i>pos; i--)
		{
			ptr->keys[i] = ptr->keys[i-1];
			ptr->p[i+1] = ptr->p[i];
		}
		
		ptr->keys[pos] = newKey;
		ptr->p[pos+1] = newPtr;
		++ptr->n; 
		
		return Success;
	}
	if (pos == M - 1)
	{
		lastKey = newKey;
		lastPtr = newPtr;
	}
	else
	{
		lastKey = ptr->keys[M-2];
		lastPtr = ptr->p[M-1];
		
		for (i=M-2; i>pos; i--)
		{
			ptr->keys[i] = ptr->keys[i-1];
			ptr->p[i+1] = ptr->p[i];
		}
		
		ptr->keys[pos] = newKey;
		ptr->p[pos+1] = newPtr;
	}
	splitPos = (M - 1)/2;
	(*upKey) = ptr->keys[splitPos];
	(*newnode)=(struct node*)malloc(sizeof(struct node));
	ptr->n = splitPos; 
	(*newnode)->n = M-1-splitPos;
	
	for (i=0; i < (*newnode)->n; i++)
	{
		(*newnode)->p[i] = ptr->p[i + splitPos + 1];
		if(i < (*newnode)->n - 1)
			(*newnode)->keys[i] = ptr->keys[i + splitPos + 1];
		else
			(*newnode)->keys[i] = lastKey;
	}
	(*newnode)->p[(*newnode)->n] = lastPtr;
	return InsertIt;
}

void display(struct node *ptr, int blanks) {
	if (ptr)
	{
		int i;
		for(i=1;i<=blanks;i++) 
			printf(" ");
		for (i=0; i < ptr->n; i++)
			printf("%d ",ptr->keys[i]);
		printf("\n");
		for (i=0; i <= ptr->n; i++)
			display(ptr->p[i], blanks+10);
	}
}

int searchPos(int key, int *key_arr, int n) {
	int pos=0;
	while (pos < n && key > key_arr[pos])
		pos++;
	return pos;
}
