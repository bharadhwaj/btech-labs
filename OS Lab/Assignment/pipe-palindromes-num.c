#include<stdio.h>
#include<unistd.h>
#include <string.h>
#define MAX 256

int palindrome(int a){
	int rem;
	int rev = 0;
	int temp = a;
	while(a != 0){
		rem = a % 10;
		rev *= 10;
		rev += rem;
		a /= 10;
	}
	if(rev == temp)
		return 1;
	else
		return 0;
}
int main()
{
		int fdptoc[2], fdctop[2];
		
		int parent_nums[MAX];
		
		int child_palindromes[MAX];
		
		int n, num, i, j, pid, npalindromes;

		int k = 0;
		
		pipe(fdptoc);
		pipe(fdctop);
		
		pid = fork();
		
		if(pid){
			printf("Parent proc: \n");
			printf("\tEnter N: ");
			scanf("%d", &n);
			
			write(fdptoc[1], &n, sizeof(n));
			printf("\tEnter %d numbers: ", n);
			for(i = 0; i < n; i++)
				scanf("%d", &parent_nums[i]);
				

			write(fdptoc[1], parent_nums, sizeof(parent_nums));

			read(fdctop[0], &npalindromes, sizeof(npalindromes));
			read(fdctop[0], &child_palindromes, sizeof(child_palindromes));
			
			printf("\nParent proc: \n");
			printf("\tPalindromes: ");
			for(i = 0; i < npalindromes; i++)
				printf("%d " , child_palindromes[i]);
			printf("\n");
	
		}else{			
			read(fdptoc[0], &n, sizeof(n));
			read(fdptoc[0], &parent_nums, sizeof(parent_nums));
			
			printf("Child proc executing...\n");
			for(i = 0; i < n; i++){
				if(palindrome(parent_nums[i]))
					child_palindromes[k++] = parent_nums[i];
				
			}
			
			write(fdctop[1], &k, sizeof(k));
			write(fdctop[1], child_palindromes, sizeof(child_palindromes));
			
		}
		
		return 0;
}
			
