#ifndef TETRIS_H
#define TETRIS_H

#include <stdlib.h>
#include <string.h>

/**
 *  Define ID of each Tetromino Shape
 */
typedef char TETROMINO;

TETROMINO sq_t = 0x01; // Square 
TETROMINO ln_t = 0x02; // Line
TETROMINO le_t = 0x03; // L-Shape
TETROMINO je_t = 0x04; // L-Shape Mirrored
TETROMINO ne_t = 0x05; // N-Shape
TETROMINO se_t = 0x06; // N-Shape Mirrored
TETROMINO te_t = 0x07; // T-Shape

/**
 *  Define the piece and its 5x5 matrices
 *  for the game display and logic.
 */
typedef struct {
  int m1[25];
  int m2[25];
  int m3[25];
  int m4[25];
  TETROMINO type;
} Piece;

/**
 *  Functions
 */
Piece *create_sq();
Piece *create_ln();
Piece *create_le();
Piece *create_je();
Piece *create_ne();
Piece *create_se();
Piece *create_te();
void free_piece(Piece *piece);

/**
 *  Implementations
 */
#include "create_sq.c"

/**
 *  Subfiles
 */
#include "app/app.h"


#endif
