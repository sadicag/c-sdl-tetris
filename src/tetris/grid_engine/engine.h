#ifndef ENGINE_H
#define ENGINE_H

/**
 *  App itself and the functions used
 *  are initialized and linked/included 
 *  in this folder.
 */

#include <SDL2/SDL.h>

/**
 *  Definition of Metrics Used
 */
typedef int Px; // Pixels
typedef int SDL_Flag; // SDL Flags

/**
 *  Definition of App
 */
typedef struct {
  Px            SCR_Width; // Screen Width
  Px            SCR_Height; // Screen Height
  SDL_Flag      renderer_flags;  // Flags for Renderer
  SDL_Flag      window_flags;    // Flags for Window 
  SDL_Renderer  *renderer;  // Renderer for SDL
  SDL_Window    *window;  // Window for SDL
  char          title[256]; // Title of Window
} GridEngine;


/**
 *  Include Error Handler
 */
#include "error_handler/error_handler.h"

/**
 *  Include Status Handler
 */
#include "status_handler/status_handler.h"

/**
 *  Functions
 */
// Initialize the GridEngine with required parameters
GridEngine *init_engine(char *eng_title, Px width, Px height);
// Free the GridEngine and its contents
void free_engine(GridEngine *engine);

/**
 *  Implementations
 */
#include "init.c"
#include "free.c"

/**
 *  Subfiles
 */
#include "input/input.h"
#include "draw/draw.h"

#endif
