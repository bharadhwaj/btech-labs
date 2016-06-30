#include<stdio.h>
#include<math.h>
#define pi 3.14
int fact(int);
main()
{
    int i,j,x,n;
    float y,sin=0,cos=0;
    long int e;
    printf("\n Enter the limit [x]: ");
    scanf("%d",&x);
    printf("\n Enter the number of terms: ");
    scanf("%d",&n);
    y=(x*3.14)/180;
    for(i=0;i<n;i++)
    {
        e=e+(pow(x,i)/fact(i));
    }
    for(i=1,j=0;j<n;i=i+2,j++)
    {
        sin=sin+((pow(-1,j)*pow(y,i))/fact(i));
    }
    for(i=0,j=0;j<n;i=i+2,j++)
    {
        cos=cos+((pow(-1,j)*pow(y,i))/fact(i));
    }
    printf("\n\n e^%d = %ld",x,e);
    printf("\n\n sin(%d) = %f",x,sin);
    printf("\n\n cos(%d) = %f",x,cos);
}
int fact(int n)
{
    if(n==0)
        return 1;
    else
        return (n*fact(n-1));
}

