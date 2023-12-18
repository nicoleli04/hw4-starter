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
	size_t col;
	for(col = 0; col< cols; col++){
		size_t alive_neighbours = 0;
		for (int r = -1; r<=1; r++){
			for (int c = -1; c<= 1; c++){
				if (r==0 && c==0){
					continue;
				}
				size_t neighbour_r= mod(row + r + rows, rows);
				size_t neighbour_c = mod(col + c +cols, cols);

				size_t neighbour_index = get_index(cols,neighbour_r, neighbour_c);
				
				if (*(src + neighbour_index) == 1){
					alive_neighbours++;
				}
			}
		}
		if(src[row*cols+col] == 1){
			if (alive_neighbours > 1 && alive_neighbours < 4){
				dest[rows*cols+col] = 1;
			}
			else{
				dest[rows*cols+col] = 0;
			}
		}
		else{
			if (alive_neighbours == 3 || alive_neighbours == 6){
				dest[rows*cols+col] = 1;
			}
			else{
				dest[rows*cols+col] =0;
			}
		}
	}
	
}


/**
 * perform a simulation for "steps" generations
 *
 * for steps
 *   calculate the next board
 *   swap current and next
 */
void sim_loop(Board* board, unsigned int steps) {
	for(unsigned int i = 0; i <steps;i++){
		for(size_t row = 0; row < board-> num_rows; row++){
			do_row(board->current_buffer, board->next_buffer, row, board->num_rows, board->num_cols);
			swap_buffers(board);
			board->gen +=1;
		}
	}

}
