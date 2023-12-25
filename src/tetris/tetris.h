#ifndef TETRIS_H
#define TETRIS_H

#define BOARD_WIDTH  10
#define BOARD_HEIGHT 20

/**
 *  Define the board where the game
 *  is going to take place in.
 */
typedef struct {
  int board[BOARD_WIDTH*BOARD_HEIGHT]; 
} Tetris;

/**
 *  Functions
 */

/**
 *  Implementations
 */

/**
 *  Subfiles
 */
#include "piece/piece.h"
#include "app/app.h"


#endif
