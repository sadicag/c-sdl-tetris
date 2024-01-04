#ifndef ENGINE_INIT_C
#define ENGINE_INIT_C

/**
 *  This function initializes an GridEngine and returns a pointer for it.
 *
 *  First, it is checked if SDL can be initialized.
 *  Second, the GridEngine struct is allocated a certain memory.
 *  Third, the Window of the GridEngine is created with the required parameters
 *    + Render Scale Quality is set to Linear
 *  Fourth, the Renderer is created
 *  Lastly the app pointer is returned
 */
GridEngine *init_engine(char *eng_title, Px width, Px height)
{
  // Initialize SDL
  if(SDL_Init(SDL_INIT_VIDEO) < 0) engine_init_failure_print(1, 
                                    "Could not initialize SDL");

  // Initialize the GridEngine Struct
  GridEngine *engine = malloc(sizeof(GridEngine));
  engine->SCR_Width  = width;
  engine->SCR_Height = height;
  engine->renderer_flags = SDL_RENDERER_ACCELERATED;
  engine->window_flags = 0;

  // Initialize/Create the SDL Window
  engine->window = SDL_CreateWindow(eng_title,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    engine->SCR_Width,
                                    engine->SCR_Height,
                                    engine->window_flags
                                    );

  if(!engine->window) engine_init_failure_print(1, 
                          "Could not open Window");

  // Set the render quality
  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
  
  // Set the window size to be resizable 
  SDL_SetWindowResizable(engine->window, SDL_TRUE);

  // Initialize/Create the SDL Renderer
  engine->renderer = SDL_CreateRenderer(engine->window, 
                                        -1, 
                                        engine->renderer_flags);

  if(!engine->renderer) engine_init_failure_print(1, 
                          "Could not create Renderer");
  
  return engine;
}

#endif
