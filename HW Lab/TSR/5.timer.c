#include<dos.h>
#include<conio.h>
union REGS r;
char time_string[10];                     
char far *ptr=(char far *)0xb8000000L;
char far *temp_ptr;
int i;
void interrupt (*oldtimer) ();
void interrupt newtimer() {
    (*oldtimer) ();
    r.h.ah=2;
    int86(0x1a,&r,&r);
    time_string[0]=' ';
    time_string[1]=(r.h.ch>>4)+'0';
    time_string[2]=(r.h.ch & (char)0x0f)+'0';
    time_string[3]=':';
    time_string[4]=(r.h.cl>>4)+'0';
    time_string[5]=(r.h.cl & (char)0x0f)+'0';
    time_string[6]=':';
    time_string[7]=(r.h.dh>>4)+'0';
    time_string[8]=(r.h.dh & (char)0x0f)+'0';
    time_string[9]=' ';
    temp_ptr=ptr+140;
    for(i=0;i<10;i++) {
        *temp_ptr++=time_string[i];
        *temp_ptr++=0x4f;
    }
}

void main() {
    oldtimer=getvect(0x1c);
    setvect(0x1c,newtimer);
    keep(0,400);
    getch();
}
