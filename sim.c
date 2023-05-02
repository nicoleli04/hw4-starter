/**
 * Assignment: life
 * Name: TODO
 * PID: TODO
 * Class: UCSD CSE30-SP21
 *
 */
#include "sim.h"

#define CIMP
extern void asm_doRow(belem *, belem *, size_t, size_t, size_t);

/**
 * gets x mod N (works for negative numbers as well! Use this instead of %)
 */
size_t getModVal(int x, size_t N){
     size_t adj = x/N;

     return((x+adj*N)%N);
}

/**
 * process one row of the board
 */
static void doRow(belem *dest, belem *src, size_t row, size_t rows, size_t cols){
  // TODO: 
}


/**
 * perform a simulation for "steps" generations
 *
 * for steps
 *   calculate the next board
 *   swap current and next
 */
void simLoop(boards_t *self, unsigned int steps){
  // TODO:
}