#include<stdio.h>
#include<Conio.h>

struct cricket
{
 char name[20],team[20];
 int avg;

 }crick[50];

main()
{

 int n,i;
 char name[20];
 clrscr();

printf("\n\n\t\t Enter the no of players:");
scanf("%d",&n);

for(i=0;i<n;i++)
{clrscr();

 printf("\n\n\t\tEnter the name of team     :");
  scanf("%s",crick[i].team);
 printf("\n\n\t\tEnter the name of player   :");
  scanf("%s",crick[i].name);
 printf("\n\n\t\tEnter the  average         :");
  scanf("%d",&crick[i].avg);
}

printf("\n\n\t\t Data input Completed..........");
clrscr();


printf("\n\n\n\n\t\t\tEnter the name of the team to display  : ");
scanf("%s",name);

clrscr();


printf("\n\n\n\t\t\t %s",name);
printf("\n\n\t\t-------------------------");
printf("\n\n\t\t  Player\t\tAverage");
printf("\n\n\t\t-------------------------");

for(i=0;i<n;i++)
{
 if(!strcmp(crick[i].team,name))
 {printf("\n\t\t|  %s\t\t%d\t|",crick[i].name,crick[i].avg);
 }
 }
 getch();
 }