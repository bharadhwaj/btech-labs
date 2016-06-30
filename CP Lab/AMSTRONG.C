#include <stdio.h>
#include <conio.h>
main()
{
  int n,r,s,t;
  clrscr();
  printf("Enter the number: ");
  scanf ("%d",&n);
  t = n;
  for(s = 0;t != 0;t /= 10)
  {
    r = t % 10;
    s += r * r * r;
  }
  if(s == n)
    printf ("%d is an amstrong number\n",n);
  else
    printf ("%d is not an amstrong number\n",n);
    getch();
}