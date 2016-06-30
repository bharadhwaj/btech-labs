#include<stdio.h>
main() {
	int n, i, j, s, g[7][7], key[7], p[7], q[7], temp;
	printf("\n Enter the number of nodes: ");
	scanf("%d",&n);
	for(i = 0; i < n; i++) {
		for(j = i+1; j < n; j++) {
			printf("\n Enter the cost of nodes %d and %d? (If no connection, Enter 0)  ",i+1,j+1);
			scanf("%d",&temp);
			if(temp >= 0)
				g[i][j] = temp;
			else {
				printf("\n ERROR: Try with positive values. \n");
				j = j-1;
			}
			g[j][i]=g[i][j];
		}
		g[i][i] = 0;
		key[i] = q[i] = 9999;
		p[i]=0;
	}
	printf("\n Enter the starting element: ");
	scanf("%d",&s);
	key[s-1] = q[s-1] = j = 0;
	while(j < n) {
		s = 0;
		for(i = 1; i < n; i++)
			if(q[i] < q[s])
				s = i;
			q[s] = 99999;
			for(i = 0; i < n; i++)
				if( g[s][i] != 0 && q[i] != 99999 && g[s][i] < key[i]) {
					p[i] = s+1;
					q[i] = key[i] = g[s][i];
				}
			j++;
	}
	printf("\n\nThe Minimum Spanning Tree is: \n");
	for(i=0;i<n;i++)
		if(p[i]!=0)
			printf(" (%d,%d) --> ",p[i],i+1);
}


/*
 Enter the number of nodes: 5

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


 Enter the starting element: 5


The Minimum Spanning Tree is: 
 (4,1) -->  (1,2) -->  (5,3) -->  (3,4) -->
*/
