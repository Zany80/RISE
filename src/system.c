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
