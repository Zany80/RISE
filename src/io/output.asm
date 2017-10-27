#export puts

;//puts [Display]
;//Puts a string of text on the screen. Can handle approximately 100k
;//characters per second at the standard 4MHz speed.
puts:
	ld a, (hl)
	cp 0
	ret z
	out (0), a
	inc hl
	jr puts
