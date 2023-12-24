#ifndef APP_FREE_C
#define APP_FREE_C

/**
 *  This function frees the contents of the app,
 *  and the app itself. The Renderer and the Window
 *  is destroyed. The SubSystems of the SDL Flags
 *  also are quit, before quitting SDL itself.
 *
 *  Afterall, the app pointer itself is free'd.
 */
void free_app(App *app)
{
  // Set width and height values
  // of window to zero
  app->SCR_Width = 0;
  app->SCR_Height = 0;

  // Destroy the renderer
  SDL_DestroyRenderer(app->renderer);
  // Destroy the Window
  SDL_DestroyWindow(app->window);

  // Quit the Subsystem of Renderer
  SDL_QuitSubSystem(app->renderer_flags);
  // Quit the Subsystem of Window
  SDL_QuitSubSystem(app->window_flags);

  // Quit SDL
  SDL_Quit();

  // Free Pointer
  free(app);
}

#endif
