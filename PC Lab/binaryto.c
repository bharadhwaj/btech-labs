
#include<stdio.h>
int oct(int);
void hex(int);
int main()
{
 long int bin,b;
 int i,j=0,p=0;
 int d=0,o;
 printf("enter a binary number:\n");
 scanf("%ld",&bin);
 b=bin;
 for(j=1;b!=0;j=j*2)
 {p=b%10;
  b=b/10;
  d=d+(p*j);}
 printf("\ndecimal equivalent=%d",d);
  o=oct(d);
 printf("\n octal equivalent=%d",o);
 hex(d);
}

oct(int d)
{
 int r=0,s=0;
 if(d==8)
 return 10;
 else
 {
  while(d!=0)
  {
   s=(s*10)+(d%8);
   d/=8;
  }
 while(s!=0)
 {
  r=(r*10)+(s%10);
  s/=10;
 }
 return r;
}}

void hex(int d)
{
 int a[10],k=0,i;
 char c; 
 printf("\nhexadecimal equivalent=");
 while(d!=0)
 {
  a[k]=d%16;
  k++;
  d/=16;
 }
 for(i=k-1;i>=0;i--)
 {
  if(a[i]<10)
  printf("%d",a[i]);
 else
  printf("%c",a[i]+65-10);
 }
 printf("\n");
}
