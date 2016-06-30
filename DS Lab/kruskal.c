#include<stdio.h>
int set[10][10],pos[10];
int find(int e,int n) {
	int i,j;
	for(i = 0; i < n; i++)
		for(j = 0; j < pos[i]; j++)
			if(set[i][j] == e)
				return i;
}
struct node {
	int i, j, w;
}st[10];
struct sets {
	int i, j;
}mst[10];
main() {
	int n, g[7][7], i, j, k, p, l, temp;
	printf("\n Enter the number of Nodes: ");
	scanf("%d",&n);
	for(i = 0, k = 0; i < n; i++) {
		for(j = i+1; j < n; j++) {
			printf("\n Enter the cost of nodes %d and %d? (If no connection, Enter 0)  ",i+1,j+1);
			scanf("%d",&temp);
			if(temp >= 0) {
				g[i][j] = temp;
				g[j][i] = g[i][j];
				if(g[i][j] != 0) {
					st[k].w = g[i][j];
					st[k].i = i+1;
					st[k].j = j+1;
					k++;
				}
			}
			else {
				printf("\n ERROR: Try with positive values. \n");
				j = j-1;
			}
		}
		g[i][i] = 0;
	}
	for(i = 0; i < n; i++) {
		set[i][0] = i+1;
		pos[i] = 1;
	}
	for(i = 0; i < k-1; i++)
		for(j = 0; j < k-i-1; j++)
			if(st[j].w > st[j+1].w) {
				p = st[j].w;
				st[j].w=st[j+1].w;
				st[j+1].w=p;
				
				p=st[j].i;
				st[j].i=st[j+1].i;
				st[j+1].i=p;
				
				p=st[j].j;
				st[j].j=st[j+1].j;
				st[j+1].j=p;
			
			}
	for(i=0;i<k+1;i++) {
		j = find(st[i].i,n);
		p = find(st[i].j,n);
		if(j != p) {
			for(l = 0; l < pos[p]; l++)
				set[j][l+pos[j]] = set[p][l];
			pos[j] += pos[p];
			pos[p] = 0;
			mst[i].i = st[i].i;
			mst[i].j = st[i].j;
		}
	}
	printf("\n The Minimum Spanning Tree is: \n");
	for(i = 0 ; i < n-1; i++)
		printf(" (%d,%d)--> ", mst[i].i, mst[i].j);
}

/*
 Enter the number of Nodes: 5

 Enter the cost of nodes 1 and 2? (If no connection, Enter 0)  10

 Enter the cost of nodes 1 and 3? (If no connection, Enter 0)  0

 Enter the cost of nodes 1 and 4? (If no connection, Enter 0)  20

 Enter the cost of nodes 1 and 5? (If no connection, Enter 0)  0

 Enter the cost of nodes 2 and 3? (If no connection, Enter 0)  30

 Enter the cost of nodes 2 and 4? (If no connection, Enter 0)  0

 Enter the cost of nodes 2 and 5? (If no connection, Enter 0)  20

 Enter the cost of nodes 3 and 4? (If no connection, Enter 0)  10

 Enter the cost of nodes 3 and 5? (If no connection, Enter 0)  10

 Enter the cost of nodes 4 and 5? (If no connection, Enter 0)  0
 

 The Minimum Spanning Tree is: 
 (1,2)-->  (3,4)-->  (3,5)-->  (1,4)-->
*/
