#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

/**
 *  Errors that need to be printed for the
 *  App are handled here.
 */

/**
 *  Functions
 */
void engine_init_failure_print(int is_exit, char* suffix);

/**
 *  Implementations
 */
#include "engine_init_failure_print.c"

/**
 *  Subfiles
 */

#endif
