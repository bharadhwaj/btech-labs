#include<stdio.h>
#include<conio.h>
void main()
{	int n,i,a[20],temp;
	clrscr();
	printf("\nEnter the number of elements  to be sorted:");
	scanf("%d",&n);
	printf("\nEnter elements  to be sorted:\n");
	for(i=0;i<n;i++)
	{	scanf("%d",&a[i]);
	}
	for(i=0;i<(n-1);i++)
	{	if(a[i]<a[i+1])
		{
		 temp=a[i];
		 a[i]=a[i+1];
		 a[i+1]=temp;
		 }
	}
	printf("\nThe smallest number is:%d",a[n-1]);
	getch();
}

