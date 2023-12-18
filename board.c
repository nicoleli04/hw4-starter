#include "cse30life.h"
#include "board.h"

/**
 * create a new board
 *
 * - malloc a Board structure
 * - set the generation to 0
 * - open the file (if it doesn't exist, return a NULL pointer
 * - read the first line which is the number of rows
 * - read the second line which is the number of cols
 * - set the # of rows and # of cols in the boards structure
 * - malloc bufferA and bufferB 
 * - Set currentBuffer and nextBuffer
 * - clear both board buffers
 * - read the file until done.  each row contains a row and a columns separted by
 *   white space
 *     for each line, set the cell in the current buffer
 * - close the file
 * - return the boards pointer if successfull or NULL ptr otherwise
 */
Board* create_board(const char* filename) {
	Board* board = (Board*)malloc(sizeof(Board));
	if (board == NULL){
		return NULL;
	}
	board->gen = 0;

	FILE* fp;
	if ((fp = fopen(filename, "r") ) == NULL){
		return NULL;
	}
	size_t numRows_input;
	size_t numCols_input;
	if((fscanf(fp, "%zu", &numRows_input)) > 0){
		board -> num_rows = numRows_input;
	}
	else{
		return NULL;
	}
	if ((fscanf(fp, "%zu", &numCols_input)) > 0){
		board -> num_cols = numCols_input;
	}

	else{
		return NULL;
	}

	board->buffer_a = (Cell*)malloc(board->num_rows * board->num_cols);
	board->buffer_b = (Cell*)malloc(board->num_rows * board->num_cols);
	clear_board(board);

	size_t numOne;
	size_t numTwo;
	while(fscanf(fp, "%zu %zu", &numOne, &numTwo) == 2){
		*(board->current_buffer + ((numOne * board->num_cols) + numTwo)) = 1;
	}
	
	fclose(fp);
	return board;


}

/**
 * delete a board
 */
void delete_board(Board** bpp) {
	Board* board = *bpp;
	free(board->buffer_a);
	free(board->buffer_b);
	free(board);
	*bpp = NULL;
}

/**
 * set all the Cells in both buffers to 0
 */
void clear_board(Board* board) {
	for(size_t i = 0; i < board->num_rows*board->num_cols; i++){
		board->buffer_a[i] = 0;
		board->buffer_b[i] = 0;
	}
}

/**
 * swap the current and next buffers
 */
void swap_buffers(Board* board) {
	Cell* temp = board->current_buffer;
  board->current_buffer = board->next_buffer;
  board->next_buffer = temp;
}

/**
 * get a cell index
 */
size_t get_index(size_t num_cols, size_t row, size_t col) {
	return row * num_cols + col;
}
