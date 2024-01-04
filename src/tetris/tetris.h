#ifndef TETRIS_H
#define TETRIS_H


/**
 *  Dependencies
 */
#include "tetris_piece/piece.h"
#include <stdlib.h>

#define BOARD_WIDTH  10
#define BOARD_HEIGHT 20

int POSITION_FREE = 0;
int POSITION_FULL = 1;

/**
 *  Define the board where the game
 *  is going to take place in.
 */
typedef struct {
  int board[BOARD_HEIGHT][BOARD_WIDTH]; 
} Tetris;

/**
 *  Functions
 */
Tetris *init_board();
Tetris *store_piece(Tetris *game, ActivePiece *active_piece);
Tetris *delete_line(Tetris *game, int y);
Tetris *delete_possible_lines(Tetris *game);
int is_move_possible(Tetris *game, ActivePiece *active_piece, int x, int y);
int is_game_over(Tetris *game);
void free_board(Tetris *game);

/**
 *  Implementations
 */
#include "init.c"
#include "storepiece.c"
#include "deletelines.c"
#include "ismoveposs.c"
#include "isover.c"
#include "free.c"

/**
 *  Subfiles
 */
#include "window_app/app.h"


#endif
