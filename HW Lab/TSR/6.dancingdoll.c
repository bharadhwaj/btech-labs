#include"dos.h"
#include<stdio.h>
void interrupt our();
void interrupt ( *prev)();
char far * scr = (char far *)0xB8000000L;
void main() {
    unsigned long char far *p;
    p = ( char far *) 36;
    prev = *p;
    *p = our;
    keep(0,500);
}

void interrupt our() {
    int i;
    for(i=0; i<3999; i+=2) {	
        if(*(scr+i)>='A'&& *(scr+i)<='Z')
            *(scr+i)+=32;
	  else
		 if(*(scr+i)>='a'&& *(scr+i)<='z')
		     *(scr+i)-=32;
    }
    (*prev)();
}
