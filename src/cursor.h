#ifndef __ANSIIsACurse_Line_Attrs__
#define __ANSIIsACurse_Line_Attrs__

#include <stdint.h>

// Orig (0;0) -> (top;left)

// Get cursor location
void save_c_pos();
void restore_c_pos();

// Move cursor vertical (-u / +d)
void mv_c_vert(int16_t up_dw);
// Move cursor up
void mv_c_up(uint16_t up);
// Move cursor down
void mv_c_dw(uint16_t dw);

// Move cursor horizontal (-l / +r)
void mv_c_hor(int16_t lt_rt);
// Move cursor left
void mv_c_lt(uint16_t lt);
// Move cursor right
void mv_c_rt(uint16_t rt);

// Move cursor to location
void mv_c_abs(uint16_t x, uint16_t y);
// Move cursor to newline
void mv_c_nl();
// Move cursor to the beginning of the line 
void mv_c_l_beg();

// Erase current line from beginning to end (cursor position unchanged)
void del_line(void);

#endif
