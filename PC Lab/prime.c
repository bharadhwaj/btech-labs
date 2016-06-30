#include<stdio.h>
main()
{
    int n,i,flag=0;
    printf("\n\n Enter the number to check: ");
    scanf("%d",&n);
    for(i=2;i<=(n/2);i++)
    {
        if(n%i==0)
            flag=1;
    }
    if(flag==1)
        printf("\n\n %d is Composite number.",n);
    else
        printf("\n\n %d is Prime number.",n);
}
