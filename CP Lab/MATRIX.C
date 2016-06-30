#include <stdio.h>
#include <conio.h>
main()
{
  int a[10][10], b[10][10], c[10][10], m, n, p, q, i, j, k;
  clrscr();
  printf("Enter order of 1st matrix:");
  scanf("%d %d", &m, &n);
  printf("Enter %d elements : ", m*n);
  for(i=0; i < m; i++)
    for(j = 0; j < n; j++)
      scanf("%d", &a[i][j]);
  printf("Enter order of 2nd matrix :");
  scanf("%d %d", &p, &q);
  if(n!=p)
  {
    printf("Orders of matrices are not compatible for matrix multiplication\n");
    return;
  }
  printf("Enter %d elements : ", p*q);
  for(i=0; i < p; i++)
    for(j = 0; j < q; j++)
      scanf("%d", &b[i][j]);

  for(i= 0; i < m; i++)
  {
    for(j = 0; j < q; j++)
    {
      c[i][j] = 0;
      for(k = 0; k < n; k++)
	c[i][j] += a[i][k] * b[k][j];
    }

  }
  printf("Matrix 1: \n");
  for(i= 0; i < m; i++)
  {
    for(j = 0; j < n; j++)
      printf("%d\t", a[i][j]);
    printf("\n");
  }
  printf("Matrix 2: \n");
  for(i= 0; i < p; i++)
  {
    for(j = 0; j < q; j++)
      printf("%d\t", b[i][j]);
    printf("\n");
  }
  printf("Matrix product: \n");
  for(i= 0; i < m; i++)
  {
    for(j = 0; j < q; j++)
      printf("%d\t", c[i][j]);
    printf("\n");
  }
  getch();
}

