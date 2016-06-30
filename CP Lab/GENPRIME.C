#include <stdio.h>
#include <conio.h>
main()
{
 int i,j,n,flag;
 clrscr();
 printf("Enter the limit: ");
 scanf("%d", &n);
 for(i = 2; i <=n; i++)
 {
   flag = 0;
   for(j = 2; j <= i/2; j++)
   {
     if (i%j == 0)
     {
       flag = 1;
       break;
     }
   }
   if(flag == 0)
   printf("%d ", i);
 }
 getch();
}

