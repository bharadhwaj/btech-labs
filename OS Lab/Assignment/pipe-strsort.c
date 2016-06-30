#include<stdio.h>
#include<unistd.h>
#include <string.h>
#define MAX 256
int main()
{
		int fdunsorted[2], fdsorted[2];
		
		char parent_sorted[MAX][32], parent_unsorted[MAX][32];
		
		char child_unsorted[MAX][32], temp[32];
		
		int n, num, i, j, pid;

		
		pipe(fdunsorted);
		pipe(fdsorted);
		
		pid = fork();
		
		if(pid){
			printf("Parent proc: \n");
			printf("\tEnter N: ");
			scanf("%d", &n);
			
			write(fdunsorted[1], &n, sizeof(n));
			printf("\tEnter %d strings: ", n);
			for(i = 0; i < n; i++)
				scanf("%s", &parent_unsorted[i]);
				

			write(fdunsorted[1], parent_unsorted, sizeof(parent_unsorted));

			read(fdsorted[0], &parent_sorted, sizeof(parent_sorted));
			
			printf("\nParent proc: \n");
			printf("\tSorted strings: ");
			for(i = 0; i < n; i++)
				printf("%s " , parent_sorted[i]);
			printf("\n");
	
		}else{			
			read(fdunsorted[0], &n, sizeof(n));
			read(fdunsorted[0], &child_unsorted, sizeof(child_unsorted));
			
			printf("Child proc executing...\n");
			for(i = 0; i < n; i++){
				for(j = 0; j < n-1; j++)
					if(strcmp(child_unsorted[j],child_unsorted[j+1])> 0){
						strcpy(temp, child_unsorted[j]);
						strcpy(child_unsorted[j], child_unsorted[j+1]);
						strcpy(child_unsorted[j+1], temp);
					}
			}
			
		
			write(fdsorted[1], child_unsorted, sizeof(child_unsorted));
			
		}
		
		return 0;
}
			
