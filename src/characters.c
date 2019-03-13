#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

char* c_color_string(const char* src, C_COLOR_CODE c_code) {
	char* ret = calloc(strlen(src) + 10, sizeof(char));
	sprintf(ret, "\x1b[%dm%s\x1b[0m",c_code, src);
	ret = realloc(ret, strlen(ret) + 1);
	return ret;
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

char* c_decorate_string(const char* src, C_DECORATION c_decoration) {
	if (c_decoration & C_DECORATION_Bold)
	{ return c_color_string(src, (C_COLOR_CODE)C_DECORATION_CODE_Bold); }
	if (c_decoration & C_DECORATION_Underline)
	{ return c_color_string(src, (C_COLOR_CODE)C_DECORATION_CODE_Underline); }
	if (c_decoration & C_DECORATION_Reversed)
	{ return c_color_string(src, (C_COLOR_CODE)C_DECORATION_CODE_Reversed); }
	if (c_decoration & C_DECORATION_Blinking)
	{ return c_color_string(src, (C_COLOR_CODE)C_DECORATION_CODE_Blinking); }
	return (char*)src;
}

void c_bg_color(C_COLOR_CODE c_code) {
	c_color(BG_COLOR(c_code));
}

char* c_bg_color_string(const char* src, C_COLOR_CODE c_code){
	return c_color_string(src, BG_COLOR(c_code));
}

void c_reset() {
	c_color(0);
}
