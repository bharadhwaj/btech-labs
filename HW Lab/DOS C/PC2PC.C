#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
int portstat(void);
int portinit(void);
int re(void);
int se(char);
union REGS i,o;
int portinit() {
	i.h.ah = 0x00;
	i.h.al = 0xfb;
	i.x.dx = 0;
	int86(0x14,&i,&o);
	return(o.h.ah);
}

int portstat() {
	i.h.ah = 0x03;
	i.x.dx = 0;
	int86(0x14,&i,&o);
	return(1);
}

int re() {
	if(portstat() == 1) {
		i.h.ah = 0x02;
		i.x.dx = 0;
		int86(0x14,&i,&o);
	}
	return(o.h.al);
}

int se(char c) {
	if(portstat() == 1) {
		i.h.ah = 0x01;
		i.h.al = c;
		i.x.dx = 0;
		int86(0x14,&i,&o);
	}
	return 1;
}

void main() {
	int ch, i;
	char r;
	while(1) {
		clrscr();
		printf("\n 1. Initialise \n 2. Receive \n 3. Send \n 			4. Exit \n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch) {
			case 1:
				i = portinit();
				printf("%d",i);
				printf("\n Port initialised.");
				getch();
				break;
			case 2: 
				printf("\n Receiving...");
				do {
					r = re();
					if((r >= 0) && (r < 127))
						printf("%c",r);
				}
				while( !kbhit() );
					break;
			case 3: 
				printf("\n Data to send: ");
				flushall();
				gets(str); 
				for(i = 0; i < strlen(str); i++)
					se(str[i]);
				break;
			case 4:
				exit(0);
		}
	}
}
