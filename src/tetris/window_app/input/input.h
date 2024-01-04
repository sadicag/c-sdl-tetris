#ifndef APP_INPUT_H
#define APP_INPUT_H

/**
 *  Input of the App is handled here and 
 *  returned as flags.
 */

typedef unsigned int INPUT_FLAG; // Type for Input Flags

/**
 *  The Flags to be returned:
 */ 
INPUT_FLAG inf_none = 0; // No Input
INPUT_FLAG inf_quit = 1; // Quit the App
INPUT_FLAG win_evnt = 2; // Window Resized


/**
 *  Functions
 */
INPUT_FLAG basic_app_input();

/**
 *  Implementations
 */
#include "basic_input.c"

/**
 *  Subfiles
 */

#endif
