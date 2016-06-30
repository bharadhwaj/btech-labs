#include<stdio.h>
#include <conio.h>
main()
{
  FILE *fin;
  FILE *fout;
  char finname[256],foutname[256],c;
  clrscr();
  printf("Enter file to be read: ");
  scanf("%s", finname);
  fin = fopen(finname,"r");
  if(fin == NULL)
  {
    printf("Error opening file\n");
    getch();
    return 1;
  }
  else
    printf("File found and opened\n");
  printf("Enter output file name: ");
  scanf("%s", foutname);
  fout = fopen(foutname,"w");
  if(fin == NULL)
  {
    printf("Error opening/creating file");
    getch();
    return 1;
  }
  while((c=getc(fin)) != EOF)
    printf("%c",c);
  rewind(fin);
  while((c=getc(fin)) != EOF)
    fprintf(fout,"%c",c);
  printf("\nFile writing was successful\n");
  getch();
}
