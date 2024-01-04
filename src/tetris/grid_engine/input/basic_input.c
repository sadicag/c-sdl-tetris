
/**
 *  A Basic input handler for SDL
 */
INPUT_FLAG basic_engine_input()
{
  SDL_Event event;

  while(SDL_PollEvent(&event))
  {
    switch(event.type)
    {
      case SDL_QUIT:
        return inf_quit;
      break;
      case SDL_WINDOWEVENT:
        return win_evnt;
      break; 
      default:
        return inf_none;
      break;
    }
  }
}
