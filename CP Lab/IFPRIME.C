#include <stdio.h>
#include <conio.h>
main()
{
  int n, i,flag = 0;
  clrscr();
  printf("Enter the number : ");
  scanf("%d", &n);
  if (n == 1)
  {
    printf("Neither prime nor composite \n");
    return 0;
  }
  for(i = 2; i < n; i++)
  {
    if(n%i == 0)
    {
      flag = 1;
      break;
    }
  }
  if(flag == 1)
    printf("%d is not a prime number\n", n);
  else
    printf("%d is a prime number\n", n);
  getch();
}