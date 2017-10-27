#include <defines.inc>
#include <output.inc>

.area rise

rise:
	cls
	call check_first_run
	
.end:
	halt
	jr .end
