#include<stdio.h>
#include<math.h>
main()
{					
	float a[10][10],x[10],g[10],v;
	int n,i,j,k,q,m,p;
	printf("Enter the number of unknowns: ");
		scanf("%d",&n);
	if(n!=0)
	{
		for(i=0;i<n;i++)
		{
			printf("\n\n Equation %d :", (i+1));
			for(j=0;j<n;j++)
			{
				printf("\n Enter the coefficient of x%d:",(j+1));
					scanf("%f",&a[i][j]);
			}
			printf("\n Enter the RHS:");
				scanf("%f",&a[i][j]);
		}
		printf("\n\n The augmented matrix: \n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<=n;j++)
				printf("%.2f\t",a[i][j]);
			printf("\n");
		}
		for(k=0;k<n-1;k++)
		{
			for(i=k+1;i<n;i++)
			{
				v=a[i][k]/a[k][k];
				for(j=k;j<=n;j++)
					a[i][j]-=v*a[k][j];
			}
		}
		printf("\n\n The Echelon form is:\n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<=n;j++)
				printf("%.2f\t",a[i][j]);
			printf("\n");
		}
		for(k=n-2;k>=0;k--)
		{
			for(i=0;i<=k;i++)
			{
				v=a[i][k+1]/a[k+1][k+1];
				for(j=0;j<=n;j++)
					a[i][j]-=v*a[k+1][j];
			}
		}
		printf("\n\n The solutions are: ");
		for(i=0;i<n;i++)
		{
			x[i]=a[i][n]/a[i][i];
			printf("\n x%d = %5.2f\t",i+1,x[i]);
		}
	}
	else
		printf("\n Error: Number of unknowns should be greater than zero.");
}
