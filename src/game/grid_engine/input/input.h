#ifndef INPUT_H
#define INPUT_H

/**
 *  Input of the App is handled here and 
 *  returned as flags.
 */

typedef unsigned char INPUT_FLAG; // Type for Input Flags

/**
 *  The Flags to be returned:
 */ 
INPUT_FLAG inf_none   = 0x0A; // No Input
INPUT_FLAG inf_quit   = 0x0B; // Quit the App
INPUT_FLAG win_evnt   = 0x0C; // Window Resized
INPUT_FLAG key_prss   = 0x0D; // Keyboard Press
INPUT_FLAG rot_prss   = 0x0E; // Rotate Press

/**
 *  Functions
 */
INPUT_FLAG basic_engine_input(Coordinate *transform);

/**
 *  Implementations
 */
#include "basic_input.c"

/**
 *  Subfiles
 */

#endif
