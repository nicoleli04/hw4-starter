#include "sim.h"

#define C_IMPL
extern void asm_do_row(Cell*, Cell*, size_t, size_t, size_t);

/**
 * gets x mod N (works for negative numbers as well! Use this instead of %)
 */
size_t mod(int x, size_t N) {
	return (x + x / N * N) % N;
}

/**
 * process one row of the board
 */
static void do_row(Cell* dest, Cell* src, size_t row, size_t rows, size_t cols) {
	// TODO
}


/**
 * perform a simulation for "steps" generations
 *
 * for steps
 *   calculate the next board
 *   swap current and next
 */
void sim_loop(Board* board, unsigned int steps) {
	// TODO
}
