#include <stdio.h>
#include <conio.h>
#include <math.h>
main()
{
  int a,b,c,d;
  float r1, r2;
  clrscr();
  printf("Enter the coefficients of x^2, x, and constant term: \n");
  scanf("%d %d %d", &a, &b, &c);
  d = (b*b) - (4 * a * c);
  if (a==0)
  {
    printf("Not a quadratic equation\n");
    return 0;
  }
  if(d ==0)
  {
    r1 = -b/(2*a);
    printf("Real; and equal roots %f and %f ", r1, r1);
  }
  else if(d > 0)
  {
    r1 = (-b + sqrt(d)) / (2*a);
    r2 = (-b - sqrt(d)) / (2*a);
    printf("Real and distinct roots %f and %f", r1, r2);
  }
  else if(d <0)
  {
    r1 = -b/(2*a);
    r2 = (sqrt(-d))/(2*a);
    printf("Imaginary roots\n %f + %f", r1, r2);
    printf("\n%f - %f\n", r1, r2);
  }
  getch();
}