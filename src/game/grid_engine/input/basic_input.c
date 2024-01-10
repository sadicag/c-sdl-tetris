
/**
 *  A Basic input handler for SDL
 */
INPUT_FLAG basic_engine_input(Coordinate *transform)
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
      case SDL_KEYDOWN: // User pressed a key
        switch(event.key.keysym.sym)
        { 
          case SDLK_LEFT:
            transform->x--;
          break;
          case SDLK_RIGHT:
            transform->x++;
          break;
          case SDLK_DOWN:
            transform->y--;
          break;
          default:
          break;
        }
        return key_prss;
      break;
      default:
        return inf_none;
      break;
    }
  }
}

