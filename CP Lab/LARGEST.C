#include <stdio.h>
#include <conio.h>
main()
{
  int a[20], n, i, l;
  clrscr();
  printf("Enter number of elements: ");
  scanf("%d", &n);
  printf("Enter %d numbers: ", n);
  for(i=0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  l = a[0];
  for (i = 1; i < n; i++)
  {
    if (a[i] > l)
      l = a[i];
  }
  printf("Largest number is: %d", l);
  getch();
}