#include<stdio.h>
main() {
	int n,i,j,elt,temp,beg,end,mid,flag;
	printf("\n\n Enter the number of elements: ");
	scanf("%d",&n);
	int A[n];
	printf("\n\n Enter the elements: ");
	for(i = 0; i < n; i++)
		scanf("%d",&A[i]);
	for(i = 0; i < n; i++)
		for(j = 0; j < n-i-1; j++) {
			if(A[j] > A[j+1]) {
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	printf("\n\n The sorted array is: ");
	for(i = 0; i < n; i++)
		printf("%d -> ",A[i]);
	printf("\n\n Enter the element to be searched: ");
	scanf("%d",&elt);	
	beg = 0;
	end = n-1;
	while(beg <= end) {
		mid = (beg+end)/2;
		if(A[mid] > elt)
			end = mid-1;
		else if(A[mid] < elt)
			beg = mid+1;
		else if(A[mid] == elt) {
			flag = 1;
			break;
		}
	}
	if(flag == 1)
		printf("\n\n Element %d is found at position %d in sorted order.",elt,mid+1);
	else
		printf("\n\n Element not found!");
}
