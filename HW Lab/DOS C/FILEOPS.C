#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<dos.h>
union REGS r,i;
main(){
	char fname[20],buffer[50],newname[20],buffer1[50];
	int ch,k,u=0,handle,mode,d=0,l,atr,orig,re,w;
	clrscr();
	while(1) {
		printf("\nMenu\n1.Create\n2.Open\n3.Write\n4.Read				\n5.Set Current File Position\n6.Set File Attributes			\n7.Close file\n8.Delete file\n9.Exit\nEnter your	 			choice : ");
		scanf("%d",&ch);
		switch(ch) {
			case 1:
				printf("\nEnter the File Name : ");
				fflush(stdin);
				gets(fname);
				r.h.ah = 0x3c;
				r.x.cx = 0;
				r.x.dx = FP_OFF(fname);
				intdos(&r,&i);
				if(i.x.cflag) {
					printf("\nError in Creation.");
					printf("\nError : %d", i.x.ax);
				}
				else
					printf("\nFile was created with 							handle : %d",i.x.ax);

				handle = i.x.ax;
				break;

			case 2:
				printf("\nEnter the File Name : ");
				fflush(stdin);
				gets(fname);
				printf("\nEnter Mode : \n 1. Read \n 2. 					Write \n 3. Read & Write \n Enter your 					Choice : ");
				scanf("%d",&mode);
				r.h.ah = 0x3D;
				r.h.al = mode-1;
				if(r.h.al == 0) {
					re = 1;
					w = 0;
				}
				if(r.h.al == 1){
					re = 0;
					w = 1;
				}
				if(r.h.al == 2){	
					re = 1;
					w = 1;
				}
				r.x.dx = FP_OFF(fname);
				intdos(&r,&i);
				if(i.x.cflag){	
					printf("\nError in Opening the 							file.");
					printf("\nError : %d",i.x.ax);
				}
				else
					printf("\nFile opened with handle : 
					%d",i.x.ax);
				handle = i.x.ax;
				break;
			case 3:
				printf("\nEnter the handle of the file: ");
				scanf("%d",&handle);
				if(w == 1) {
					r.h.ah = 0x40;
					r.x.bx = handle;
					printf("\nEnter the string to be 						written : ");
					fflush(stdin);
					gets(buffer1);
					u = strlen(buffer1);
					for(k = 0,l = d; k < u; k++, l++)
						buffer[l]=buffer1[k];
					d = l;
					r.x.cx = u;
					r.x.dx=FP_OFF(buffer1);
					intdos(&r,&i);
					if(i.x.cflag) {
						printf("\nError in writing.");
						printf("\nError code : 
						%d",i.x.ax);
					}
					else
						printf("\nContents written to 							file succesfully...");
				}
				else
					printf("\nRead Only Mode : Cannot 						Write to file!");
				break;

			case 4:
				printf("\nEnter handle of the file : ");
				scanf("%d",&handle);
				if(re == 1) {
					r.x.bx=handle;
					r.h.ah=0x3f;
					r.x.dx=FP_OFF(buffer1);
					r.x.cx=64;
					intdos(&r,&i);
					if(i.x.cflag) {
						printf("\nError : ");
						printf("\nError Code : 
						%d",i.x.ax);
					}
					else {
						if(i.x.ax != 0) {
							printf("\nContents : ");
							for(l = 0;l < i.x.ax; l++)
								putch(buffer1[l]);
						}
						else
							printf("Error : Nothing to 								display!");
					}
				}
				else
					printf("\nWrite Only Mode : Cannot 						Read from file!");
				break;
			case 5:
				printf("\nEnter handle of the file : ");
				scanf("%d",&handle);
				r.h.ah = 0x42;
				printf("\n1.Read from beginning\n2.Write to					end\nEnter origin of move : ");
				scanf("%d",&orig);
				if(orig == 1)
					r.h.al = 0;
				if(orig == 2)
					r.h.al = 2;
				r.x.bx = handle;
				r.x.cx = 0;
				r.x.dx = 0;
				intdos(&r,&i);
				if(i.x.cflag) {
					printf("\nError in Setting File 							Pointer.");
					printf("\nError : %d", i.x.ax);
				}
				else
					printf("\nFile Pointer Set.");
				break;
			case 6:
				printf("\nEnter the File Name : ");
				fflush(stdin);
				gets(fname);
				r.h.ah = 0x43;
				r.h.al = 1;
				printf("\nEnter attribute to set : \n1.Read 				Only\n2.Hidden\n3.Archive\n");
				scanf("%d",&atr);
				switch(atr) {
					case 1:
						r.x.cx = 0x01;
						re = 1;
						w = 0;
						break;
					case 2:
						r.x.cx = 0x02;
						break;
					case 3:
						r.x.cx = 0x20;
						break;
				}
				r.x.dx=FP_OFF(fname);
				intdos(&r,&i);
				if(i.x.cflag) {
					printf("\nError in Setting 								Attribute.");
					printf("\nError : %d", i.x.ax);
				}
				else
					printf("\nAttribute Set.");
				break;

			case 7:	
				printf("\nEnter the handle of file to be 					closed : ");
				scanf("%d",&handle);
				r.x.bx = handle;
				r.h.ah = 0x3e;
				intdos(&r,&i);
				if(i.x.cflag) {
					printf("\nError : ");
					printf("\n Error code : %d",i.x.ax);
				}
				else
					printf("\nFile Closed.");
				break;

			case 8:   
				printf("\n Enter file name to be 						deleted:");
				fflush(stdin);
				gets(fname);
				r.h.ah=0x41;
				intdos(&r,&i);
				if(i.x.cflag) {
					  printf("Error in File deletion.");
					  printf("\n Error code:%d",i.x.ax);
				}
				else
					 printf("File deleted");
				break;
			case 9:
				printf("\nExiting.");
				getch();
				return;
		}
		getch();
	}
}