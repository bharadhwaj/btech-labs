#include <stdio.h>
#include <string.h>
#define MAX 256
int search(char string[], char substring[], int pos)
{
	int j;
	for (j = 0; string[pos + j] != '\0' && substring[j] != '\0'; j++)
		if (string[pos + j] != substring[j])
			return 0;
	return 1;
}

int main()
{
	char string[MAX], substring[MAX], c;
	int i, ls, lsub,f=0;
	printf("Enter string: ");
	fgets(string, MAX, stdin);
	printf("Enter substring: ");
	fgets(substring, MAX, stdin);
	lsub = strlen(substring);
	substring[lsub - 1] = '\0';
	ls = strlen(string);
	for (i = 0; i < ls; i++)
		if (search(string, substring, i)==1)
		{
			f=1;
			printf("\n Substring found at: ", ls, lsub);
			printf("%d ", i+1);
			printf("\nString after removing substring:\n");
			for (i = 0; i < ls; i++)
				if (search(string, substring, i))
					i += lsub - 2;
				else
					printf("%c", string[i]);

		}
	if(f==0)
		printf("\n\n Substring not found.");

}
