#include<stdio.h>
#define MAX 256
int rear = -1, front = -1;
int A[MAX][MAX]; 
void enqueue(int Q[MAX],int elt) {
	if(front == -1)
		front = 0;
	rear = rear +1;
	Q[rear] = elt;
}
int dequeue(int Q[MAX]) {
	int temp = Q[front];
	if(front == rear)
		front = rear = -1;
	else
		front = front+1;
	return temp;
}
void bfs(int B[MAX], int n, int e) {
	int i,j,Q[MAX];
	enqueue(Q,n);
	B[n-1] = 1;
    while(rear != -1) {
		j = dequeue(Q);	
		printf("%d ->",j);
		for(i = 0; i < e; i++) {
			if( A[j-1][i] == 1 && B[i] == 0) {
				enqueue(Q,i+1);
				B[i] = 1;
			}
		}
	}
}
void dfs(int C[MAX], int n, int e) {
	int i,Q[MAX];
	printf("%d -> ",n);
		C[n-1] = 1;
	for(i = 0; i < e; i++) {
		if(A[n-1][i] == 1)
			if(C[i] == 0) {
				dfs(C,i+1,e);
				C[i] = 1;
			}
	}				
}
main() {
	int i,j,e,ch,temp,n1,n2;
	printf("\n\n Enter number of nodes: ");
	scanf("%d",&e);
	int B[e], C[e];
	for(i = 0; i < e; i++)
		for(j = 0; j < e; j++) {
			printf("\n Is there connection between nodes %d and %d? (If yes, Enter 1 else 0.)  ",i+1,j+1);
			scanf("%d",&temp);
			if(temp == 0 || temp == 1)
				A[i][j] = temp;
			else {
				printf("\n ERROR: Try with values 0 or 1. \n");
				j = j-1;
			}		
		}
	printf("\n The Adjacency Matrix is: \n");
	for(i = 0; i < e; i++) {
		printf("\n");
		for(j = 0; j < e; j++)
			printf(" %d ",A[i][j]);
	}
	do {
		printf("\n\n Select which type of traversal you need: \n ");
		printf("\n 1. Breadth First Search(BFS) \n 2. Depth First Search(DFS) \n 3. Exit.");
		printf("\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch) {
			case 1:
				printf("\n Enter the starting node for BFS: ");
				scanf("%d",&n1);
				for(i = 0; i < e; i++)
					B[i] = 0;
				if(n1 <= e)
					bfs(B,n1,e);
				else
					printf("\n ERROR: Edge out of Bounds!");
				break;
			case 2:
				printf("\n Enter the starting node for DFS: ");
				scanf("%d",&n2);
				for(i = 0; i < e; i++)
					C[i] = 0;
				if(n2 <= e)
					dfs(C,n2,e);
				else
					printf("\n ERROR: Edge out of Bounds!");
				break;
			case 3:
				break;
			default:
				printf("\n\n Invalid option! Try with numbers 1 - 3!");
		}
	}while(ch != 3 );	
}
