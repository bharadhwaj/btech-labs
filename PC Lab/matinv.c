#include<stdio.h>
#include<math.h>
int determinant(int mat[10][10],int m)
{
    	int det=0,k,i,j,p,q,m1[10][10],f=1;
    	if(m==1)
    		det=mat[0][0];
    	else
     		for(k=0;k<m;k++)
 		{
  		 	for(i=0,p=1;i<m;i++,p++)
   			for(j=0,q=0;j<m;j++,q++)
   		 	{
   			 	if(j==k)
   				  	q++;
   			 	m1[i][j]=mat[p][q];
  		 	}
  		 	det+=mat[0][k]*f*determinant(m1,m-1);
  		 	f*=-1;
 	 	}
    	return det;
}
void inverse(int mat[10][10], int m)
{
    	int m1[10][10],adj[10][10],i,j,p,q,s,det,x,y;
    	float inv[10][10],cof[10][10];
    	for(i=0;i<m;i++)
    	{
    		for(j=0;j<m;j++)
    		{
   		 	for(x=0,p=0;p<m;p++)
    			{
    				if(p==i)      
        	        		continue;
        	        	else
        	        	{	
        				for(y=0,q=0;q<m;q++)
        				{
        	    	   			if(q==j)
 							continue;
 						else
 		    					m1[x][y++]=mat[p][q];
    					}
    				}
    				x++;
    			}
    		adj[j][i]=pow(-1,(i+j+2))*(float)determinant(m1,(m-1));
    		}
    	}
    	det=determinant(mat,m);
    	for(i=0;i<m;i++)
    	{
    		for(j=0;j<m;j++)
    		{
    		    	inv[i][j]=adj[i][j]/(float)det;
    	     
    		}
    	}
    	printf("\n\n The inverse of the matrix is: \n\n");
    	for(i=0;i<m;i++)
    	{
		for(j=0;j<m;j++)
			printf("%f \t",inv[i][j]);
    		printf("\n");
    	}
}    
main()
{
	int a[10][10],n,d,i,j;
    	printf("\n\n Enter the order of matrix: ");
	scanf("%d",&n);
    	printf("\n\n Enter the elements: ");
    	for(i=0;i<n;i++)
    	{
    		for(j=0;j<n;j++)
    			scanf("%d",&a[i][j]);
    	}
    	d=determinant(a,n);
    	printf("\n\n The determinant is %d \n",d);
    	if(d==0)
    		printf("\n\n Inverse doesnot exist.");
    	else
    		inverse(a,n);
}
