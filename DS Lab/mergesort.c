#include<stdio.h>
int elt;
void merge(int A[], int L[], int n1, int R[], int n2) {
	int i = 0,j = 0,k,p;
	for(k = 0; k < n1+n2; k++) {
		if(i < n1) {
			if(j == n2 || L[i] <= R[j]) {
				A[k] = L[i];
				i++;
			}
			else {
				A[k] = R[j];
				j++;
			}
		}
		else {
			if(j < n2) {
				A[k] = R[j];
				j++;
			}
		}
	}
	if(elt == n1+n2) {
	printf("\n The elements after sorting: \n");
	for(p = 0; p < n1+n2; p++)
			printf("%d ->",A[p]);
	}
}
void mergesort(int A[], int n) {
	int n1,n2,i,j;
	if(n == 1)
		return;
	else {
		n1 = n/2;
		n2 = n-n1;
		int L[n1],R[n2];
		for(i = 0; i < n1; i++)
			L[i] = A[i];
		for(j = 0; j < n2; j++)
			R[j] = A[n1+j];
		mergesort(L,n1);
		mergesort(R,n2);
		merge(A,L,n1,R,n2);
	}
}
main() {
	int n,i;
	printf("\n Enter the number of elements in array: ");
	scanf("%d",&n);
	elt = n;
	int A[n];
	printf("\n Enter the elements: ");
	for(i = 0; i < n; i++)
		scanf("%d",&A[i]);
	mergesort(A,n);

}
