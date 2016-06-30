#include <stdio.h>
#include <conio.h>
void swap(int &x, int &y)
{
  int t = x;
  x = y;
  y = t;
}
main()
{
  int a,b;
  clrscr();
  printf("Enter two numbers: ");
  scanf("%d %d", &a, &b);
  printf("Before swap\n a = %d, b = %d\n", a, b);
  swap(a,b);
  printf("After swap\n a = %d, b = %d\n", a, b);
  getch();
}