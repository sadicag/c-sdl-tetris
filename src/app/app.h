#ifndef APP_H
#define APP_H

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
} App;


/**
 *  Include Error Handler
 */
#include "error_handler/error_handler.h"

/**
 *  Functions
 */
// Initialize the App with required parameters
App *init_app(char *app_title, Px width, Px height);
// Free the App and its contents
void free_app(App *app);

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
