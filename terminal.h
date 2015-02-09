#ifndef _TERMINAL_H_
#define _TERMINAL_H_

#define TERM_HEIGHT 80
#define TERM_WIDTH 25

typedef struct {
	char screen[TERM_WIDTH][TERM_HEIGHT];
	int in;
	int out;
} terminal;

#endif
