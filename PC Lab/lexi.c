#include<stdio.h>
#include<string.h>
main()
{
    char a[100][100],temp[100];
    int n,i,j;
    printf("\n\n Enter the number of string: ");
    scanf("%d",&n);
    printf("\n\n Enter the string one by one: \n");
    for(i=0;i<n;i++)
    {
        scanf("%s",a[i]);
    }
    for(i=0;i<(n-1);i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(a[i],a[j])>0)
            {
                strcpy(temp,a[i]);
                strcpy(a[i],a[j]);
                strcpy(a[j],temp);
            }
        }
    }
    printf("\n\n The Strings in Lexicographic order is: \n\n");
    for(i=0;i<n;i++)
        printf("%s \n",a[i]);
}
