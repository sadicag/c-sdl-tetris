#ifndef DRAW_H
#define DRAW_H

/**
 *  Drawing and Presentation of Scenes are handled here.
 */

/**
 *  Functions
 */
void prepare_engine_scene(GridEngine *engine);
void present_engine_scene(GridEngine *engine);
void draw_grid(GridEngine *engine, int W, int H, int board[H][W]);

/**
 *  Implementations
 */
#include "prepare_scene.c"
#include "present_scene.c"
#include "draw_grid.c"

/**
 *  Subfiles
 */

#endif
