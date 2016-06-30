#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main() {
	int a[2],b[2],s[20],n,s1[20];
	int i=0;
	int p,temp,j,q=0;
	 pipe(a);
	 pipe(b);
	 p=fork();
	 if(p) {
	 	printf("\nParent Process:");
	 	printf("\nEnter the total number of elements: ");
	 	scanf("%d",&n);
	 	write(a[1],&n,sizeof(n));
	 	printf("\nEnter the elements : ");
	 	for(i=0;i<n;i++)
	 	scanf("%d",&s[i]);
	 	
	 	write(a[1],s,sizeof(s));
	 	printf("\nPassing to parent process : ");
	 	read(b[0],s1,sizeof(s1));
	 	
	 	printf("\nThe sorted array is : ");
	 	
	 	for(q=0;q<n;q++)
	 		printf(" %d",s1[q]);
	 	printf("\n\n");
	 }
	 
	 else
	 {
	 	sleep(0);
	 	
	 	read(a[0],&n,sizeof(n));
	 	read(a[0],s,sizeof(s));
	 	
	 	for(i=0;i<n;i++)
	 		for(j=i;j<n;j++)
	 			if(s[i]>s[j]) {
	 				temp=s[i];
	 				s[i]=s[j];
	 				s[j]=temp;
	 			}
	 	
	 	write(b[1],s,sizeof(s));
	 }	
}	 	
