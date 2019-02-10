#include <stdlib.h>
#include <stdio.h>

#include "cursor.h"

#define ESCAPE_SEQ 0x1b

// ** Vertical Movement **
void mv_c_vert(int16_t up_dw) {
	uint16_t abs_up_dw = abs(up_dw);
	if (up_dw > 0) {
		mv_c_dw(abs_up_dw);
	} else {
		mv_c_up(abs_up_dw);
	}
}

void mv_c_up(uint16_t up) {
	printf("%c[%dA", ESCAPE_SEQ, up);
}

void mv_c_dw(uint16_t dw) {
	printf("%c[%dB", ESCAPE_SEQ, dw);
}
// ** END Vertical Movement **

// ** Horizontal Movement **
void mv_c_hor(int16_t lt_rt) {
	uint16_t abs_lt_rt = abs(lt_rt);
	if (lt_rt > 0) {
		mv_c_rt(abs_lt_rt);
	} else {
		mv_c_lt(abs_lt_rt);
	}
}

void mv_c_lt(uint16_t lt) {
	printf("%c[%dD", ESCAPE_SEQ, lt);
}

void mv_c_rt(uint16_t rt) {
	printf("%c[%dC", ESCAPE_SEQ, rt);
}
// ** END Horizontal Movement **

// ** Absolute Movement **
void mv_c_abs(uint16_t x, uint16_t y) {
	printf("%c[%d;%dH",ESCAPE_SEQ,x,y);
}

void mv_c_nl() {
	printf("%cE",ESCAPE_SEQ);
}
// ** END Absolute Movement **
