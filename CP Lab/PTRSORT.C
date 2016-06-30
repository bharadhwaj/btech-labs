#include <stdio.h>
#include <conio.h>
main()
{
  int i, j, n, a[20],t;
  int *ar;
  int *tp = &t;
  clrscr();
  ar = a;
  printf("Enter number of elements : ");
  scanf ("%d", &n);
  printf("Enter %d numbers : ", n);
  for(i = 0; i < n; i++)
    scanf("%d", ar+i);
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n-1; j++)
    {
      if(*(a+j) > *(a+j+1))
      {
	*tp = *(a+j);
	*(a+j) = *(a+j+1);
	*(a+j+1) = *tp;
      }
    }
  }
  printf("Sorted numbers: \n");
  for(i = 0; i < n; i++)
    printf("%d ", *(a+i));

  getch();
}