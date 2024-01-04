#ifndef APP_INIT_C
#define APP_INIT_C

/**
 *  This function initializes an App and returns a pointer for it.
 *
 *  First, it is checked if SDL can be initialized.
 *  Second, the App struct is allocated a certain memory.
 *  Third, the Window of the App is created with the required parameters
 *    + Render Scale Quality is set to Linear
 *  Fourth, the Renderer is created
 *  Lastly the app pointer is returned
 */
App *init_app(char *app_title, Px width, Px height)
{
  // Initialize SDL
  if(SDL_Init(SDL_INIT_VIDEO) < 0) app_init_failure_print(1, 
                                  "Could not initialize SDL");

  // Initialize the App Struct
  App *app = malloc(sizeof(App));
  app->SCR_Width  = width;
  app->SCR_Height = height;
  app->renderer_flags = SDL_RENDERER_ACCELERATED;
  app->window_flags = 0;

  // Initialize/Create the SDL Window
  app->window = SDL_CreateWindow(app_title,
                                 SDL_WINDOWPOS_UNDEFINED,
                                 SDL_WINDOWPOS_UNDEFINED,
                                 app->SCR_Width,
                                 app->SCR_Height,
                                 app->window_flags
                                 );

  if(!app->window) app_init_failure_print(1, 
                  "Could not open Window");

  // Set the render quality
  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
  
  // Set the window size to be resizable 
  SDL_SetWindowResizable(app->window, SDL_TRUE);

  // Initialize/Create the SDL Renderer
  app->renderer = SDL_CreateRenderer(app->window, 
                                     -1, 
                                     app->renderer_flags);

  if(!app->renderer) app_init_failure_print(1, 
                    "Could not create Renderer");
  
  return app;
}

#endif
