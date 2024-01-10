#ifndef ENGINE_FREE_C
#define ENGINE_FREE_C

/**
 *  This function frees the contents of the app,
 *  and the app itself. The Renderer and the Window
 *  is destroyed. The SubSystems of the SDL Flags
 *  also are quit, before quitting SDL itself.
 *
 *  Afterall, the app pointer itself is free'd.
 */
void free_engine(GridEngine *engine)
{
  // Set width and height values
  // of window to zero
  engine->SCR_Width = 0;
  engine->SCR_Height = 0;

  // Destroy the renderer
  SDL_DestroyRenderer(engine->renderer);
  // Destroy the Window
  SDL_DestroyWindow(engine->window);

  // Quit the Subsystem of Renderer
  SDL_QuitSubSystem(engine->renderer_flags);
  // Quit the Subsystem of Window
  SDL_QuitSubSystem(engine->window_flags);

  // Quit SDL
  SDL_Quit();

  // Free Pointer
  free(engine);
}

#endif
