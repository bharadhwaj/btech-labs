#include<stdio.h>
#include<unistd.h>
#include <string.h>
#define MAX 256

int palindrome(char a[32]){
	int i;
	int l = strlen(a);
	for(i = 0; i <= l/2; i++)
		if(a[i] != a[l-1-i])
			return 0;

	return 1;
}
int main()
{
		int fdptoc[2], fdctop[2];
		
		char parent_strings[MAX][32];
		
		char child_palindromes[MAX][32];
		
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
			printf("\tEnter %d strings: ", n);
			for(i = 0; i < n; i++)
				scanf("%s", &parent_strings[i]);
				

			write(fdptoc[1], parent_strings, sizeof(parent_strings));

			read(fdctop[0], &npalindromes, sizeof(npalindromes));
			read(fdctop[0], &child_palindromes, sizeof(child_palindromes));
			
			printf("\nParent proc: \n");
			printf("\tPalindromes: ");
			for(i = 0; i < npalindromes; i++)
				printf("%s " , child_palindromes[i]);
			printf("\n");
	
		}else{			
			read(fdptoc[0], &n, sizeof(n));
			read(fdptoc[0], &parent_strings, sizeof(parent_strings));
			
			printf("Child proc executing...\n");
			for(i = 0; i < n; i++){
				if(palindrome(parent_strings[i]))
					strcpy(child_palindromes[k++], parent_strings[i]);
				
				
			}
			
			write(fdctop[1], &k, sizeof(k));
			write(fdctop[1], child_palindromes, sizeof(child_palindromes));
			
		}
		
		return 0;
}
			
