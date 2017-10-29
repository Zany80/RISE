#include <system.h>

void halt() __naked{
	__asm
	halt
	ret
	__endasm;
}

void shutdown() __naked {
	__asm
	ld a, 1
	out (2), a
	__endasm;
}

void reset() __naked {
	__asm
	ld a, 0
	out (2), a
	__endasm;
}

void strcpy(char * dest, const char * src){
	char cont = 1;
	while(cont == 1){
		*dest = *src;
		if((*src) == 0)
			cont = 0;
		dest++;
		src++;
	}
}
void putch(char c);
int strlen(const char *s){
	int i = 0;
	char cont = 1;
	while(cont == 1){
		if((*s) == 0){
			cont = 0;
		}
		else {
			i++;
			s++;
		}
	}
	return i;
}
