#include<stdio.h>
int hcf(int ,int);
int lcm(int, int);
main()
{
    int n,a[100],i,h,l,x,y;
    printf("\n\n Enter the number of elements: ");
    scanf("%d",&n);
    printf("\n\n Enter the %d elements: ",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    x=a[0];
    for(i=1;i<n;i++)
    {
        h=hcf(x,a[i]);
        x=h;
    }
    y=a[0];
    for(i=0;i<n;i++)
    {
        l=lcm(y,a[i]);
        y=l;
    }
    printf("\n\n The HCF of these %d numbers is %d.",n,h);
    printf("\n\n The LCM of these %d numbers is %d.",n,l);
}
int hcf(int a, int b)
{
    int i,s;
    if(a>b)
        s=b;
    else
        s=a;
    for(i=s;i>=1;i--)
    {
         if(a%i==0 && b%i==0)
         {
             return i;
             break;
         }
    }
}
int lcm(int a, int b)
{
    int c;
    c=(a*b)/hcf(a,b);
    return c;
}
