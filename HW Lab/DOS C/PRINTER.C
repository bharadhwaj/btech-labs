PROGRAM

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void print(char);
void italics();
void compressed();
void normal();
void subscript();
void superscript();
void menu(void);
void readstr();
void main(){
	int s;
	clrscr();
	biosprint(0,0,0);
	s = biosprint(2,0,0);
	if(s & 0x80)
		menu();
	else
		printf("\nPrinter is busy.");
	getch();
}
void menu() {
	int c;
	while(1) {
		printf("\nFont types: ");
		printf("\n1.Normal\n2.Italics\n3.Compressed					\n4.Superscript\n5.subscript\n6.Exit");
		printf("\nEnter your choice");
		scanf("%d",&c);
		switch(c) {
			case 1:
				normal();
				break;
  			case 2:
				italics();
				break;
 			case 3:
				compressed();
				break;
  			case 4:
				superscript();
				break;
  			case 5:
				subscript();
				break;
  			case 6:
				exit(0);
 		}
 	}
 }

void print(char x) {
	biosprint(0,x,0);
}

void italics() {
	print(27);
	print(52);
	readstr();
	print(27);
	print(53);
}

void compressed() {
	print(15);
	readstr();
	print(18);
}

void normal() {
	print(27);
	print(37);
	readstr();
	print(27);
	print(84);
}

void superscript() {
	print(27);
	print(83);
	print(49);
	readstr();
	print(27);
	print(84);
}

void subscript() {
	print(27);
	print(83);
	print(48);
	readstr();
	print(27);
	print(84);
}

void readstr() {
 	char c;
 	printf("\nEnter the string\n");
 	flushall();
 	do {
  		scanf("%c",&c);
  		print(c);
  	}while(c!='\n');
}
