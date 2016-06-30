#include <stdio.h>
#include <conio.h>
main()
{
  int i,n,j;
  struct student {
    int marks[6];
    int total;
    float average;
  };
  struct student *s;
  clrscr();
  printf("Enter no.of students : ");
  scanf("%d", &n);
  s = (struct student*) malloc(n * sizeof(struct student) );
  for(i = 0; i < n; i++)
  {
    printf("Enter 6 marks of student %d:", i+1);
    (s+i)->total = 0;
    for(j = 0; j < 6; j++) {
      scanf("%d", &((s+i)->marks[j]));
      (s+i)->total += (s+i)->marks[j];
    }
    (s+i)->average = (float)(s+i)->total / 6;
  }
  printf("Average of:\n");
  for(i = 0; i < n; i++)
    printf("Student %d : %f\n", i+1,(s+i)->average);
  free(s);
  getch();
}