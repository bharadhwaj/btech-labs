#include<stdio.h>
main()
{
    int n,i,j,temp=0,count,maxcount;
    float a[50],sum=0,mean=0,median=0,mode;
    printf("\n\n Enter the number of elements: ");
    scanf("%d",&n);
    printf("\n\n Enter the %d elements: ",n);
    for(i=0;i<n;i++)
        scanf("%f",&a[i]);
    for(i=0;i<n;i++)
        sum=sum+a[i];
    mean=sum/n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    if(n%2==0)
        median=(a[n/2]+a[(n/2)+1])/2;
    else
        median=a[(n+1)/2];
    for(i=0;i<(n-1);i++)
    {
        count=0;
        for(j=1;j<n;j++)
        {
            if(a[i]==a[j])
                count++;
        }
        if(count<2)
            mode=0;
        else
        {
            if(count>maxcount)
            {
                maxcount=count;
                mode=a[i];
            }
        }
    }
    printf("\n\n The Mean of %d numbers is %f",n,mean);
    printf("\n\n The Median of %d numbers is %f",n,median);
    printf("\n\n The Mode of %d numbers is %f",n,mode);
}
