#ifndef TETRIS_H
#define TETRIS_H

/**
 *  Dependencies
 */
#include <stdlib.h>
#include <time.h>
#include "game/tetris_piece/piece.h"

ActivePiece* active_piece; // Set the global active_piece

const time_t WAIT_TIME = 700; // milliseconds

#define BOARD_WIDTH  10
#define BOARD_HEIGHT 20

int POSITION_FREE = 0;
int POSITION_FULL = 1;

typedef struct {
  int x;
  int y; 
} Coordinate;

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
Tetris *debug(Tetris *game, int rotation);
Tetris *next_step(Tetris *game);
Tetris *copy(Tetris *game);
int is_move_possible(Tetris *game, ActivePiece *active_piece, int x, int y);
int is_game_over(Tetris *game);
void free_board(Tetris *game);
void game_loop(Tetris *game);

/**
 *  Implementations
 */
#include "game/init.c"
#include "game/storepiece.c"
#include "game/deletelines.c"
#include "game/ismoveposs.c"
#include "game/isover.c"
#include "game/free.c"
#include "game/debug.c"
#include "game/copy.c"
#include "game/next_step.c"

/**
 *  Subfiles
 */
#include "game/grid_engine/engine.h"


#endif
