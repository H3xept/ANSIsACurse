#include <stdio.h>
#include "characters.h"

// Convert any color to its corresponding background color
#define BG_COLOR(color) (color+10)

typedef enum {
	C_DECORATION_CODE_Bold 		= 1,
	C_DECORATION_CODE_Underline = 4,
	C_DECORATION_CODE_Blinking	= 5,
	C_DECORATION_CODE_Reversed 	= 7,
} C_DECORATION_CODE;

void c_color(C_COLOR_CODE c_code) {
	printf("\x1b[%dm",c_code);
}

void c_decorate(C_DECORATION c_decoration) {
	if (c_decoration & C_DECORATION_Bold)
	{ c_color((C_COLOR_CODE)C_DECORATION_CODE_Bold); }
	if (c_decoration & C_DECORATION_Underline)
	{ c_color((C_COLOR_CODE)C_DECORATION_CODE_Underline); }
	if (c_decoration & C_DECORATION_Reversed)
	{ c_color((C_COLOR_CODE)C_DECORATION_CODE_Reversed); }
	if (c_decoration & C_DECORATION_Blinking)
	{ c_color((C_COLOR_CODE)C_DECORATION_CODE_Blinking); }
}

void c_bg_color(C_COLOR_CODE c_code) {
	c_color(BG_COLOR(c_code));
}

void c_reset() {
	c_color(0);
}
