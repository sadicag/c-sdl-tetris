#ifndef APP_ERROR_HANDLER_H
#define APP_ERROR_HANDLER_H

/**
 *  Errors that need to be printed for the
 *  App are handled here.
 */

/**
 *  Functions
 */
void app_init_failure_print(int is_exit, char* suffix);

/**
 *  Implementations
 */
#include "app_init_failure_print.c"

/**
 *  Subfiles
 */

#endif
