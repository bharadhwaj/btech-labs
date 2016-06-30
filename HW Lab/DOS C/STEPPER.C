#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#define PORT 0x378
int i;
unsigned char clkarr[]={0x01,0x02,0x04,0x08};
unsigned char ackarr[]={0x08,0x04,0x04,0x01};
void clockwise(int n) {
	printf("\nMotor is rotating clockwise...");
	for(i = 0; i < (n/1.8); i++) {
		outportb(PORT, clkarr[i%4]);
		delay(150);
	}
}

void anticlockwise(int n) {
	printf("\n Motor is rotating anticlockwise...\n");
	for(i = 0; i < (n/1.8); i++) {
		outportb(PORT, ackarr[i%4]);
		delay(150);
	}
}

void main() {
	int ch,angle;
	do {
		clrscr();
		printf("1. Clockwise\n2. Anti clockwise\n3. Exit\n");
		printf("\nEnter choice:");
		scanf("%d",&ch);
		switch(ch) {
			case 1:
				printf("Enter the angle: ");
				scanf("%d",&angle);
				clockwise(angle);
				outportb(PORT,0);
				break;
			case 2:
				printf("Enter the angle:");
				scanf("%d",&angle);
				anticlockwise(angle);
				outportb(PORT,0);
				break;
			case 3:
				exit(0);
			default:
				printf("Error: Invalid Choice.");
				getch();
		}
	}while(1);
	getch();
}