#ifndef APP_BASIC_INPUT_C
#define APP_BASIC_INPUT_C

/**
 *  A Basic input handler for SDL
 */
INPUT_FLAG basic_app_input()
{
  SDL_Event event;

  while(SDL_PollEvent(&event))
  {
    switch(event.type)
    {
      case SDL_QUIT:
        return inf_quit;
      break;
      
      default:
        return inf_none;
      break;
    }
  }
}

#endif
