#include<stdio.h>
#include<unistd.h>
#include <string.h>
#define MAX 256
int main()
{
		int fdunsorted[2], fdsorted[2];
		
		int parent_num;
		
		int child_rev = 0;
		int rem, pid;
		

		
		pipe(fdunsorted);
		pipe(fdsorted);
		
		pid = fork();
		
		if(pid){
			printf("Parent proc: \n");
			printf("\tEnter No: ");
			scanf("%d", &parent_num);
			
			write(fdunsorted[1], &parent_num, sizeof(parent_num));

			read(fdsorted[0], &child_rev, sizeof(child_rev));
			
			printf("\nParent proc: \n");
			printf("\tReversed no: ");
			printf("%d\n", child_rev);
	
		}else{			
			read(fdunsorted[0], &parent_num, sizeof(parent_num));
			
			printf("Child proc executing...\n");
			while(parent_num != 0){
				rem = parent_num % 10;
				child_rev *= 10;
				child_rev += rem;
				parent_num /= 10;
			}
			
		
			write(fdsorted[1], &child_rev, sizeof(child_rev));
			
		}
		
		return 0;
}
			
