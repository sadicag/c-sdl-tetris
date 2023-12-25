#ifndef PIECE_H
#define PIECE_H

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
  int in[8];  // Initial Position
  /*
  The 4 matrices below represent
  the rotation shape of the piece.
  Meaning of Values:
    0 = no block
    1 = normal block
    2 = pivot block
  */
  int m1[25]; // Rotation no. 1
  int m2[25]; // Rotation no. 2
  int m3[25]; // Rotation no. 3
  int m4[25]; // Rotation no. 4
  TETROMINO type;
} Piece;

/**
 *  Define the active piece
 *  that will be controlled
 *  by the player.
 */
typedef struct {
  Piece *piece;
  int rotation;
  int x;
  int y;
} ActivePiece;

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
#include "create_ln.c"
#include "create_le.c"
#include "create_je.c"
#include "create_ne.c"
#include "create_se.c"
#include "create_te.c"

/**
 *  Subfiles
 */

#endif
