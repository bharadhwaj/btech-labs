#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
main() {
	char str[100];
	DIR *p;
	struct dirent *d;
	printf("\n Enter the directory name: ");
	scanf("%s",str);
	p = opendir(str);
	if(p == NULL) 
		perror("Error");
	else {
		while(d = readdir(p))
			printf("%s \t",d->d_name);
	}
	printf("\n");
}
