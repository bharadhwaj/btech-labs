#include<stdio.h>
void quicksort(int A[],int first,int last){
	int pivot,temp,i,j;
	if(first<last){
		pivot=first;
        i=first;
        j=last;
        while(i<j){
	        while(A[i] <= A[pivot] && i<last)
	            i++;
            while(A[j] > A[pivot])
                j--;
            if(i < j){
                temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
        }
        temp=A[pivot];
        A[pivot]=A[j];
        A[j]=temp;
        quicksort(A,first,j-1);
        quicksort(A,j+1,last);
	}
}

main(){
  	int n,i;
  	printf("\n Enter the number of elements: ");
  	scanf("%d",&n);
	int A[n];
  	printf("\n Enter %d elements: ",n);
  	for(i=0;i<n;i++)
    	scanf("%d",&A[i]);
	quicksort(A,0,n-1);
  	printf("\n The Sorted elements: ");
  	for(i=0;i<n;i++)
    	printf("%d ",A[i]);
}

