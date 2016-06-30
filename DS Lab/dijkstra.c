#include<stdio.h>
int mindist(int a[10], int n) {
	int i, small=0;
	for(i = 1; i < n; i++)
		if(a[i] < a[small])
			small = i;
	return small;
}
main() {
	int i, j, n, s, u, a[7][7], dis[7], arr[7], l, temp;
 	printf("\n Enter the number of nodes: ");
 	scanf("%d",&n);
 	for(i = 0,l = n; i < n; i++) {
 		for(j = i+1; j < n; j++) {
 			printf("\n Enter the cost of nodes %d and %d? (If no connection, Enter 0)  ",i+1,j+1);
			scanf("%d",&temp);
			if(temp >= 0)
				a[i][j] = temp;
			else {
				printf("\n ERROR: Try with positive values. \n");
				j = j-1;
			}
 			a[j][i] = a[i][j];
 		}
 		a[i][i] = 0;
 		dis[i] = arr[i] = 9999;
 	}
 	printf("\n Enter the source node: ");
 	scanf("%d",&s);
 	dis[s-1] = arr[s-1] = 0;
 	while(l != 0) {
	 	u=mindist(arr,n);
	 	l--;
	 	for(i = 0; i < n; i++)
	 		if(a[u][i] != 0 && dis[i] > dis[u]+a[u][i])
				arr[i] = dis[i] = dis[u]+a[u][i];
	 	arr[u]=99999;
	}
 	printf("\n The shortest path from %d to all other nodes are: ",s);
 	for(i = 0; i < n; i++)
 	printf("\n\t%d --> %d = %d", s, i+1, dis[i]);
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

 Enter the source node: 1

 The shortest path from 1 to all other nodes are: 
	1 --> 1 = 0
	1 --> 2 = 10
	1 --> 3 = 30
	1 --> 4 = 20
	1 --> 5 = 30
*/
