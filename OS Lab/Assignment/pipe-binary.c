#include<stdio.h>
#include<unistd.h>
#include <string.h>
#define MAX 256
int main()
{
		int fdunsorted[2], fdsorted[2];
		
		int parent_array[MAX];
		
		
		int n, elt, beg, end, pid, mid, i;

		
		pipe(fdunsorted);
		pipe(fdsorted);
		
		pid = fork();
		
		if(pid){
			printf("Parent proc: \n");
			printf("\tEnter N: ");
			scanf("%d", &n);
			
			printf("\tEnter %d numbers: ", n);
			for(i = 0; i < n; i++)
				scanf("%d", &parent_array[i]);
				

			printf("\tEnter element to search: ");
			scanf("%d", &elt);
			write(fdunsorted[1], &n, sizeof(n));
			write(fdunsorted[1], parent_array, sizeof(parent_array));
			write(fdsorted[1], &elt, sizeof(elt));
	
		}else{			
			read(fdunsorted[0], &n, sizeof(n));
			read(fdunsorted[0], parent_array, sizeof(parent_array));
			read(fdsorted[0], &elt, sizeof(elt));
			
			printf("Child proc:\n");
			beg = 0;
			end = n-1;
			while(beg <= end){
				mid = (beg+end)/2;
				if(parent_array[mid] == elt){
					printf("\tFound at position %d\n", mid+1);
					break;
				}

				else if(parent_array[mid] < elt)
					beg = mid + 1;
				
				else if(parent_array[mid] > elt)
					end = mid - 1;


			}
			if(beg > end)
				printf("\tNot found.\n");
			
		}
		
		return 0;
}
			
