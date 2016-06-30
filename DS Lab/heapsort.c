#include<stdio.h>
#define MAX 256
int A[MAX];
void heapify(int A[], int i, int n) {
	int lar, temp;
	int l = 2*i+1, r = 2*i+2;
		if(A[l] > A[i] && l < n)
			lar = l;
		else
			lar = i;
		if( A[r] > A[lar] && r < n)
			lar = r;
		if(lar != i) {
			temp = A[lar];
			A[lar] = A[i];
			A[i] = temp;
			heapify(A,lar,n);
		}
}
main() {
	int n, i, t;
	printf("\n Enter the number of elements: ");
	scanf("%d",&n);
	int l = n-1;
	printf("\n Enter the %d elements: ",n);
	for(i = 0; i < n; i++)
		scanf("%d",&A[i]);
	for(i = n/2; i >= 0; i--)
		heapify(A,i,n);
	for(i = l; i > 0; i--) {
		t = A[i];
		A[i] = A[0];
		A[0] = t;
		l--;
		heapify(A,0,l+1);
	}
	printf("\n The sorted array is: \n");
	for(i = 0; i< n; i++)
		printf("%d ",A[i]);	
}
