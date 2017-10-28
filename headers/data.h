#include <screens.h>

typedef struct{
	unsigned char save_flags;
	screen current_screen;
}data_t;

data_t *getData();

void initData();
