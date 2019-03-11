#ifndef __ANSIIsACurse_Characters__
#define __ANSIIsACurse_Characters__

// FORMAT ^[C_COLOR<?;C_MODIFIER>m

// EG. 	Blue = ^[34m
// 		Bright Blue = ^[34;1m

typedef enum {
	C_COLOR_CODE_Black 		= 30,
	C_COLOR_CODE_Red 		= 31,
	C_COLOR_CODE_Green 		= 32,
	C_COLOR_CODE_Yellow 	= 33,
	C_COLOR_CODE_Blue 		= 34,
	C_COLOR_CODE_Magenta 	= 35,
	C_COLOR_CODE_Cyan 		= 36,
	C_COLOR_CODE_White 		= 37
} C_COLOR_CODE;

typedef enum {
	C_DECORATION_Bold 		= (1 << 0),
	C_DECORATION_Underline 	= (1 << 1),
	C_DECORATION_Reversed 	= (1 << 2),
	C_DECORATION_Blinking	= (1 << 3)
} C_DECORATION;

// Set character color
void c_color(C_COLOR_CODE c_code);
char* c_color_string(const char* src, C_COLOR_CODE c_code);
// Set background color
void c_bg_color(C_COLOR_CODE c_code);
char* c_bg_color_string(const char* src, C_COLOR_CODE c_code);
// Set decorations for characters
void c_decorate(C_DECORATION c_decoration);
char* c_decorate_string(const char* src, C_DECORATION c_decoration);
// Reset original terminal attributes
void c_reset();



#endif
