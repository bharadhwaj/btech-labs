#include <stdio.h>
#include <conio.h>
int factorial(int n)
{
  if(n == 1)
    return 1;
  else
    return n * factorial(n-1);
}
main()
{
  int n;
  clrscr();
  printf("Enter  a number : ");
  scanf("%d", &n);
  if (n < 0)
    printf("Not defined\n");
  else if(n == 0)
    printf("0! = 1");
  else
    printf("%d! = %d\n",n,factorial(n));
  getch();
}