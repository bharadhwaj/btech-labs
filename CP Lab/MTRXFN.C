#include <stdio.h>
#include <conio.h>
void inputmatrix(int m[10][10], int row, int column)
{ int i,j;
  printf("Enter %d elements : ", row*column);
    for(i=0; i < row; i++)
      for(j = 0; j < column; j++)
	scanf("%d", &m[i][j]);
}

void printmatrix(int m[10][10], int row, int column)
{
  int i, j;
  for(i = 0; i < row; i++)
  {
    for(j=0; j < column; j++)
      printf("%d \t", m[i][j]);
    printf("\n");
  }
}
void multiply(int a[10][10],int b[10][10], int c[10][10], int m, int p, int q)
{
  int i,j,k;
  for(i= 0; i < m; i++)
  {
    for(j = 0; j < q; j++)
    {
      c[i][j] = 0;
      for(k = 0; k < p; k++)
	c[i][j] += a[i][k] * b[k][j];
    }
  }
}
main()
{
  int a[10][10], b[10][10], c[10][10], m, n, p, q, i, j, k;
  clrscr();
  printf("Enter order of 1st matrix:");
  scanf("%d %d", &m, &n);
  inputmatrix(a,m,n);
  printf("Enter order of 2nd matrix :");
  scanf("%d %d", &p, &q);
  if(n!=p)
  {
    printf("Orders of matrices are not compatible for matrix multiplication\n");
    return 0;
  }
  inputmatrix(b,p,q);

  multiply(a,b,c,m,p,q);

  printf("Matrix 1: \n");
  printmatrix(a,m,n);
  printf("Matrix 2: \n");
  printmatrix(b,p,q);
  printf("Matrix product: \n");
  printmatrix(c,m,q);
  getch();
}
