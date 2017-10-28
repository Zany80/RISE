#include <screens.h>
#include <data.h>
#include <system.h>
#include <output.h>

screen getCurrentScreen() {
	return getData()->current_screen;
}
