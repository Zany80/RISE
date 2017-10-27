#include "defines.inc"

.macro cls(saveaf)
	.if saveaf
		push af
	.endif
	ld a, 0
	out (0), a
	.if saveaf
		pop af
	.endif
.endmacro

;//cls [Output]
;//Clears the screen. Use cls(true) to preserve the A register.
.macro cls
	cls(false)
.endmacro
