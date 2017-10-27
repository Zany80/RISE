#include "defines.inc"
#include "output.inc"

#export check_first_run

check_first_run:
	ld hl, pmem
	bit 2, (hl)
	ret nz
	ld a, (hl)
	or 0x04
	ld (hl), a
	ld hl, .first
	call puts
	ld b, 0
	ld hl, pmem+1
.loop:
	ld a, 16
	ld (hl), 0 \ inc hl
	dec a
	cp 0
	jp nz, .loop
	djnz .loop
	ret

.first: .asciiz "As this is the first run, clearing all save data..."
