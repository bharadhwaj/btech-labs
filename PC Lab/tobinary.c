#include<stdio.h>
#include<string.h>
main()
{
 int a[100],B[100],r1,r,n,b,h,dec,oct,ch,i=0,j,p=0,q;
 long int bin;
 char d[20],c[100];
 printf("\n\n 1. Decimal to Binary.");
 printf("\n\n 2. Octal to Binary.");
 printf("\n\n 3. Hexadecimal to Binary.");
 printf("\n\n Enter your choice (1-3): ");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:
   printf("\n\n Enter the Decimal number: ");
   scanf("%d",&dec);
   while(dec!=0)
   {
    a[i]=dec%2;
    i=i+1;
    dec=dec/2;
   }
   j=i-1;
   printf("\n The Binary equivalent is ");
   for(i=(j);i>=0;i--)
   {
    printf("%d",a[i]);
   }
   break;



  case 2:
   printf("\n\n Enter the Octal number (0-7): ");
   scanf("%s",c);
   r=strlen(c);
   printf("\n The Binary equivalent is ");
   for(i=0;i<r;i++)
   {
    n=c[i];
    switch(n)
    {
      case '0':
       printf("000");
       break;
      case '1':
       printf("001");
       break;
      case '2':
       printf("010");
       break;
      case '3':
       printf("011");
       break;
      case '4':
       printf("100");
       break;
      case '5':
       printf("101");
       break;
      case '6':
       printf("110");
       break;
      case '7':
       printf("111");
       break;
      default:
       printf("\n\n Not an octal number.");
    }
   }
   break;



  case 3:
   printf("\n\n Enter the Hexadecimal number (0-9 & A-F): ");
   scanf("%s",d);
   printf("\n The binary equivalent is ");
   r=strlen(d);
   for(i=0;i<r;i++)
   {
    n=d[i];
    switch(n)
    {
      case '0':
       printf("0000");
       break;
      case '1':
       printf("0001");
       break;
      case '2':
       printf("0010");
       break;
      case '3':
       printf("0011");
       break;
      case '4':
       printf("0100");
       break;
      case '5':
       printf("0101");
       break;
      case '6':
       printf("0110");
       break;
      case '7':
       printf("0111");
       break;
      case '8':
       printf("1000");
       break;
      case '9':
       printf("1001");
       break;
      case 'A':
       printf("1010");
       break;
      case 'B':
       printf("1011");
       break;
      case 'C':
       printf("1100");
       break;
      case 'D':
       printf("1101");
       break;
      case 'E':
       printf("1110");
       break;
      case 'F':
       printf("1111");
       break;
      default:
       printf("\n\n Not a Hexadecimal number.");
    }
   }
   printf("\n");
   break;


  default:
   printf("\n\n Invalid choice. Try with numbers 1-4.");
 }
}
