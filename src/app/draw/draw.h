#ifndef APP_DRAW_H
#define APP_DRAW_H

/**
 *  Drawing and Presentation of Scenes are handled here.
 */

/**
 *  Functions
 */
void prepare_app_scene(App *app);
void present_app_scene(App *app);

/**
 *  Implementations
 */
#include "prepare_scene.c"
#include "present_scene.c"

/**
 *  Subfiles
 */

#endif
