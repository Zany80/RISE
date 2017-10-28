#include <output.h>

void cls(){
	putch(0);
}

void putch(char c){
	__asm
	dec sp
	pop hl
	pop af
	out (0), a
	push af
	push hl
	inc sp
	__endasm;
	c;
}

void puts(char *str){
	while((*str)!=0)
		putch(*str++);
}
