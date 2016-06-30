#include <stdio.h>
#include <string.h>
void swap(char *x, char *y)
{
    char temp;
    temp  = *x;
    *x = *y;
    *y = temp;
}
void permute(char *string, int pos)
{
    int i;
    if(pos == strlen(string)-1)
        printf("%s\n", string);
    else
        for(i = pos; i < strlen(string); i++)
        {
            swap(string+pos, string+i);
            permute(string, pos+1);
            swap(string+pos, string+i);
        }
}
main()
{
    char a[100];
    printf("\n\n Enter a String: ");
    scanf("%s",a);
    permute(a,0);
}

