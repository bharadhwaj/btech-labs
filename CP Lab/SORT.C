#include <stdio.h>
#include <conio.h>
main()
{
  int a[20], t, i, j, n;
  clrscr();
  printf("Enter no. of elements : ");
  scanf("%d", &n);
  printf("Enter %d numbers: ", n);
  for(i = 0; i < n; i++)
    scanf("%d", &a[i]);

  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n-1; j++)
    {
      if(a[j] < a[j+1])
      {
	t = a[j];
	a[j] = a[j+1];
	a[j+1] = t;
      }
    }
  }
  printf("Sorted numbers: ");
  for(i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\nSmallest element = %d", a[n-1]);
  getch();
}
